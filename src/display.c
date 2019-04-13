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

void show(t_expert *data)
{
    char *ptr;
    int i;

    i = -1;
    while (data->queries[++i])
    {
        ptr = ft_strchr(data->solver, data->queries[i]);
        if (ptr)
        {
            ft_printf("%c", data->queries[i]);
            if ('1' == *(ptr + STATUS) && '1' == *(ptr + FACTS))
            {
                display(3, " => [", PINK("AMBIGUOUS"), "]\n");
            }
            else if ('1' == *(ptr + STATUS) && '0' == *(ptr + FACTS))
            {
                display(3, " => [", GREEN("TRUE"), "]\n");
            }
            else
            {
                display(3, " => [", RED("FALSE"), "]\n");
            }
        }
    }
}

void show_true_decision(char *rule, char *goal)
{
	display(4, "[", GREEN("GOAL"), "] ", GREEN("'"));
	ft_printf("%s%s", goal, GREEN("' is"));
	ft_printf(" %s %s", GREEN("TRUE"), YELLOW(" becouse "));
	ft_printf("%s%s", YELLOW("[RULE] "), GREEN("'"));
	display(3, rule, GREEN("' is TRUE now"), "\n");
}