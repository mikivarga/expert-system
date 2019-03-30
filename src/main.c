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

int read_file(t_expert *data, const char *path_to_file)
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
            return (FALSE);
        }
    }
    close(fd);
	printf("facts %s\nqueries %s\n", data->facts, data->queries);
    return (TRUE);
}

int		main(int argc, char **argv)
{
	int			err;
	t_expert	data;

	ft_bzero(data.facts, MAX_FACTS_QUERIES);
	ft_bzero(data.queries, MAX_FACTS_QUERIES);
	data.rules = NULL;
	data.number_rules = 0;
	if (argc == 2)
	{
		err = read_file(&data, argv[1]);
	}
	else if (argc == 3 && ft_strcmp(argv[2], "-v") == 0)
	{
		
	}
	else
	{
		show_err(YELLOW("incorrect input\n"));
		return (0);
	}

	(void)argv;
	return (0);
}
