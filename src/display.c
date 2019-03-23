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

void		display(int lim, ...)
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