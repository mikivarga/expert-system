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
void		show_err_character(const char *str, const char c, const char place)
{
	show_err(str);
	if (place == FACTS_SMB)
	{
    	ft_printf("%c%s", c, YELLOW("' in FACTS\n"));
	}
    else if (place == QUERIES_SMB)
	{
        ft_printf("%c%s", c, YELLOW("' in QUERIES\n"));
	}
	else
	{
		ft_printf("%c%s", c, YELLOW("' in RULS\n"));
	}
}
