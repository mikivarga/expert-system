/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvarga <mvarga@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 16:59:08 by mvarga            #+#    #+#             */
/*   Updated: 2019/03/31 16:59:09 by mvarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expert_system.h"

/*
static void rules_split(char *rules, char rules_res[][MAX])
{
    char *ptr;
    
    if ((ptr = ft_strchr(rules, '>')))
    {
        ft_strcpy(rules_res[END], ptr + 1);
    }
    while (*ptr == '=')// || *ptr == '<')
    {
        ptr--;
    }
    ft_strncpy(rules_res[BEG], rules, ptr - (rules + 1));
}
*/


static int letters_is_true(t_expert *data, char *beg, int status, int stop)
{
    int i;

    i = -1;
    while (beg[++i])
    {
        if (LETTER(beg[i]))
        {
            char *ptr;

            ptr = ft_strchr(data->solver[DATA], beg[i]);
            if (*ptr)
            {
                if (i == 0 || (beg[i - 1] != '!' && beg[i - 1] != '^' && beg[i - 1] != '+'))
                {
                    if ('+' == *(ptr + MAX))
                    {
                        status = TRUE;
                    }
                }
                if ('+' == *(ptr + MAX * 2))
                {
                    status = TRUE;
                }
            }
        }
        else if ('|' == beg[i])
        {
            char *ptr;

            if (FALSE == status)
            {
                if (TRUE == LETTER(beg[i + 1]))
                {
                    ptr = ft_strchr(data->solver[DATA], beg[i + 1]);
                    if (*ptr)
                    {
                        if ('+' == *(ptr + MAX))
                        {
                            status = TRUE;
                        }
                    }
                }
                else
                {
                    ptr = ft_strchr(data->solver[DATA], beg[i + 2]);
                    if (*ptr)
                    {
                        if ('+' != *(ptr + MAX))
                        {
                            status = TRUE;
                        }
                    }
                }
                
            }
            else
            {
                //if (ex && or_exist(first) && !fuck)
                return (TRUE);
            }
        }
        else if ('+' == beg[i])
        {
            if (TRUE == status)
            {
                if ('!' == beg[i + 1])
                {
                    if ()
                }
            }
            else
            {
                status = FALSE;
            }
            
        }
        else if ('^' == beg[i])
        {

        }
        else if (TRUE == BRACKETS(beg[i]))
        {

        }
        else
        {
            
        }
    }
    ft_printf("  [DATA] = %s\n", data->solver[DATA]);
    ft_printf("[STATUS] = %s\n", data->solver[STATUS]);
    ft_printf(" [FACTS] = %s\n\n", data->solver[FACTS]);
    (void)stop;
    (void)data;
    (void)beg;
    return (status);
}

void algorithm(t_expert *data)
{
    char rules_res[BEG_END][MAX];
    char *ptr;
    int i;

    while (1)
    {
        i = -1;
        while (data->rules[++i])
        {
            ft_bzero(rules_res[BEG], MAX * 2);
            if ((ptr = ft_strchr(data->rules[i], '>')))
            {
                ft_strcpy(rules_res[END], ptr + 1);
            }
            *ptr == '=' ? ptr-- : ptr;
            ft_strncpy(rules_res[BEG], data->rules[i], ptr - (data->rules[i] + 1));
            if (ft_strchr(rules_res[BEG], '<'))
            {
                printf("MIKI\n");
            }
            if (TRUE == letters_is_true(data, rules_res[BEG], FALSE, FALSE))
                ft_printf("beg: %s\nend: %s\n\n", rules_res[BEG], rules_res[END]);
        }
        break ;
    }
}