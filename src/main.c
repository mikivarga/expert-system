/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvarga <mvarga@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 13:01:53 by mvarga            #+#    #+#             */
/*   Updated: 2019/03/21 14:36:38 by mvarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expert_system.h"

static void save_data(char *data, const char letter, char status, char facts)
{
	*data = letter;
	*(data + MAX) = status;
	*(data + MAX * 2) = facts;
}

static void add_to_solver(t_expert *data)
{
    int i;
    int j;
    int z;

    i = -1;
    while (data->facts[++i])
    {
		save_data(&(data->solver[DATA][i]), data->facts[i], '+', '-');
    }
    i = -1;
    while (data->queries[++i])
    {
        j = -1;
        while (data->solver[DATA][++j])
        {
            if (data->solver[DATA][j] == data->queries[i])
            {
                break ;
            }
        }
        if ('\0' == data->solver[DATA][j])
        {
			save_data(&(data->solver[DATA][j]), data->queries[i], '-', '-');
        }
    }
    i = -1;
    while (data->rules[++i])
    {
        j = -1;
        while (data->rules[i][++j])
        {
            if (TRUE == LETTER(data->rules[i][j]))
            {
                z = -1;
                while (data->solver[DATA][++z])
                {
                    if (data->solver[DATA][z] == data->rules[i][j])
                    {
                        break ;
                    }
                }
                if ('\0' == data->solver[DATA][z])
                {
					save_data(&(data->solver[DATA][z]), data->rules[i][j], '-', '-');
                }
            }
        }
    }
}

static int read_file(t_expert *data, const char *path_to_file)
{
    int fd;
    char buf[BUFF_SIZE];

    fd = open(path_to_file, O_RDONLY);
    if (-1 == fd)
    {
		show_err(YELLOW("no such file or directory\n"));
        return (FALSE);
    }
    while (get_line(fd, buf) > 0)
    {
        if (FALSE == save_line(data, buf))
        {
            close(fd);
			show_err_parsing(YELLOW("something wrong: '"), buf);
            return (FALSE);
        }
    }
    close(fd);
	if (data->rules == NULL) //check if rules || queries or facts != 0;????
	{
		show_err(YELLOW("NO RULES\n"));
		return (FALSE);
	}
	add_to_solver(data);
    return (TRUE);
}

static void init(t_expert *data)
{
	data->view = FALSE;
	ft_bzero(data->solver[DATA], MAX);
	ft_bzero(data->solver[STATUS], MAX);
	ft_bzero(data->solver[FACTS], MAX);
	ft_bzero(data->facts, MAX);
	ft_bzero(data->queries, MAX);
	data->rules = NULL;
}

int		main(int argc, char **argv)
{
	t_expert	data;

	init(&data);
	if (argc == 2)
	{
		if (FALSE == read_file(&data, argv[1]))
		{
			free_data(&data);
		}
	}
	else if (argc == 3 && ft_strcmp(argv[1], "-v") == 0)
	{
		data.view = TRUE;
		if (FALSE == read_file(&data, argv[2]))
		{
			free_data(&data);
		}
	}
	else
	{
		show_err(YELLOW("incorrect input\n"));
		return (0);
	}
	algorithm(&data);
	return (0);
}
