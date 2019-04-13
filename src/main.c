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

static void save_to_solver(char *solver, const char letter, char status, char facts)
{
    *solver = letter;
    *(solver + STATUS) = status;
    *(solver + FACTS) = facts; 
}

static void add_to_solver(t_expert *data)
{
    int i;
    int j;
    int z;

    i = -1;
    while (data->facts[++i])
    {
        save_to_solver(&(data->solver[i]), data->facts[i], '1', '0');
    }
    i = -1;
    while (data->queries[++i])
    {
        j = -1;
        while (data->solver[++j])
        {
            if (data->solver[j] == data->queries[i])
            {
                break ;
            }
        }
        if ('\0' == data->solver[j])
        {
			save_to_solver(&(data->solver[j]), data->queries[i], '0', '0');
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
                while (data->solver[++z])
                {
                    if (data->solver[z] == data->rules[i][j])
                    {
                        break ;
                    }
                }
                if ('\0' == data->solver[z])
                {
					save_to_solver(&(data->solver[z]), data->rules[i][j], '0', '0');
                }
            }
        }
    }
}

static void solver(t_expert *data)
{
    char buf[BUFF_SIZE];

    if (TRUE == data->view)
        display(3, YELLOW("QUERIES : "), data->queries, "\n\n");
    add_to_solver(data);
    algorithm(data, NULL, TRUE, -1);
    show(data);
    /*while (TRUE == data->view)
    {
        ft_printf("%s\n", GREEN("enter a new facts(=..) or exit\n"));
        get_line(STDIN_FILENO, buf);
        if (0 == ft_strcmp(buf, "exit"))
            break ;
        ft_bzero(data->solver, MAX * 3);
        ft_bzero(data->facts, MAX);
        if (FALSE == save_line(data, buf))
        {
            show_err_parsing(YELLOW("something wrong: '"), buf);
            continue ;
        }
        add_to_solver(data);
        algorithm(data, NULL, TRUE, -1);
        show(data);
    }*/
    (void)buf;
}

static void read_file(t_expert *data, const char *path_to_file)
{
    int fd;
    char buf[BUFF_SIZE];

    fd = open(path_to_file, O_RDONLY);
    if (-1 == fd)
    {
		show_err(YELLOW("no such file or directory\n"));
        return ;
    }
    while (get_line(fd, buf) > 0)
    {
        if (FALSE == save_line(data, buf))
        {
            close(fd);
			show_err_parsing(YELLOW("something wrong: '"), buf);
            return ;
        }
    }
    close(fd);
	if (data->rules == NULL)
	{
		show_err(YELLOW("NO RULES\n"));
		return ;
	}
    solver(data);
}

int		main(int argc, char **argv)
{
	t_expert	data;

	data.view = FALSE;
    ft_bzero(data.solver, MAX * 3);
	ft_bzero(data.facts, MAX);
	ft_bzero(data.queries, MAX);
	data.rules = NULL;
	if (argc == 2)
	{
		read_file(&data, argv[1]);
	}
	else if (argc == 3 && ft_strcmp(argv[1], "-v") == 0)
	{
		data.view = TRUE;
		read_file(&data, argv[2]);
	}
	else
	{
		show_err(YELLOW("incorrect input\n"));
		return (0);
	}
    free_data(&data);
	return (0);
}