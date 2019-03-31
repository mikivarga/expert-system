/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvarga <mvarga@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 12:08:26 by mvarga            #+#    #+#             */
/*   Updated: 2019/03/23 12:31:44 by mvarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expert_system.h"

static void		display(int lim, ...)
{
	va_list	ap;
	int		i;

	i = 0;
	sleep(1);
	va_start(ap, lim);
	while (i++ < lim)
	{
		ft_printf("%s", va_arg(ap, const char *));
	}
	va_end(ap);
}

void		show_err(const char *str)
{
	display(4, "[", RED("ERROR"), "] => ", str);
}

void		show_err_parsing(const char *str, const char *buf)
{
	show_err(str);
	if (FACTS_SMB == *buf)
	{
    	ft_printf("%s%s", buf + 1, YELLOW("' in FACTS\n"));
	}
    else if (QUERIES_SMB == *buf)
	{
        ft_printf("%s%s", buf + 1, YELLOW("' in QUERIES\n"));
	}
	else
	{
		ft_printf("%s%s", buf, YELLOW("' in RULS\n"));
	}
}