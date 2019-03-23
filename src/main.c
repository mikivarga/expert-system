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

int		main(int argc, char **argv)
{
	if (argc == 2)
	{

	}
	else if (argc == 3 && ft_strcmp(argv[2], "-d") == 0)
	{
		
	}
	else
	{
		display(4, "[", RED("ERROR"), "] => ", YELLOW("incorrect input\n"));
		return (0);
	}

	(void)argv;
	return (0);
}
