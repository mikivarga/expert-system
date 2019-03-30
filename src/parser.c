/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvarga <mvarga@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 12:43:59 by mvarga            #+#    #+#             */
/*   Updated: 2019/03/23 12:44:00 by mvarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expert_system.h"

static int save_rules(t_expert *data, char *buf)
{
    ft_printf("rules %s\n", buf);
    (void)data;
    (void)buf;
    return (TRUE);
}

static int save_facts_queries(t_expert *data, char *buf, char place)
{
    char *ptr;
    char *tmp;

    ptr = (FACTS_SMB == *buf ? data->facts : data->queries);
    while (*++buf)
    {
        if (TRUE == IS_ALPHA(*buf))
        {
            tmp = ptr;
            while (*tmp)
            {
                if (*tmp == *buf)
                    break ;
                tmp++;
            }
        }
        else
        {
            show_err_character(YELLOW("invalid character '"), *buf, place);
            return (FALSE);
        }
        *tmp = *buf;
    }
    return (TRUE);
}

int save_line(t_expert *data, char *buf)
{
    char *ptr;
    char str[BUFF_SIZE];
    char place;

    if (NULL != (ptr = ft_strchr(buf, IS_COMMENT)))
        *ptr = '\0';
    if (TRUE == EMPTY_LINE(*buf))
        return (TRUE);
    ptr = str;
    while (*buf)
    {
        if (FALSE == IS_SPACE(*buf))
            *ptr++ = *buf;
        buf++;
    }
    *ptr = '\0';
    if (FACTS_SMB == *str || QUERIES_SMB == *str)
    {
        place = *str;
        return (save_facts_queries(data, str, place));
    }
    return (save_rules(data, str));
}