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

static int find(t_expert *data, char c, int flag)
{
    char *ptr;
    
    ptr = ft_strchr(data->solver, c);
    if (ptr)
    {
        if (STAT == flag)
        {
            return ('1' == *(ptr + STATUS));
        }
        else
        {
            return ('1' == *(ptr + FACTS));
        }
    }
    return (FALSE);
}

int rules_is_true(t_expert *data, char *s, int status, int stop)
{
    int i;

    i = -1;
    while (s[++i])
    {
        if (TRUE == LETTER(s[i]))
        {
            if (find(data, s[i], STAT) && !NOT(s[i - 1]) && !XOR(s[i - 1]) && !AND(s[i - 1]))
            {
                status = TRUE;
            }
            else if (find(data, s[i - 1], FACT))
            {
                status = TRUE;
            }
        }
        else if (TRUE == BRACKETS(s[i]))
        {
            int prev;

            prev = FALSE;
            if (s[i] == '(')
            {
                prev = (TRUE == NOT(s[i - 1]) ? TRUE : FALSE);
                status = rules_is_true(data, s + i + 1, status, TRUE);
                while(s[i] && s[i] != ')')
                {
                    i++;
                }
                if (prev)
                {
                    status = (TRUE == status ? FALSE : TRUE);
                }
            }
        }
        else if (TRUE == AND(s[i]))
        {
            if (TRUE == status)
            {
                if (TRUE == LETTER(s[i + 1]) && FALSE == find(data, s[i + 1], STAT))
                {
                    status = FALSE;
                }
                else if (TRUE == NOT(s[i + 1]) && TRUE == find(data, s[i + 2], STAT))
                {
                    status = FALSE;
                }
            }
            else
            {
                status = FALSE;
            }    
        }
        else if (TRUE == OR(s[i]))
        {
            if (FALSE == status)
            {
                if (TRUE == LETTER(s[i + 1]) && TRUE == find(data, s[i + 1], STAT))
                {
                    status = TRUE;
                }
                else if (FALSE == find(data, s[i + 2], STAT))
                {
                    status = TRUE;
                }
            }
            else if (NULL == ft_strchr(s, '('))
            {
                if (NULL != ft_strchr(s, '|') && FALSE == stop)
                {
                    return (TRUE);
                }
            }
        }
        else if (TRUE == XOR(s[i]))
        {
            if (TRUE == status)
            {
                if (TRUE == find(data, s[i + 1], STAT) && FALSE == find(data, s[i + 1], FACT))
                {
                    status = FALSE;
                }
                else if (TRUE == NOT(s[i + 1]) && FALSE == find(data, s[i + 2], STAT))
                {
                    status = FALSE;
                }
            }
            else
            {
                if (TRUE == find(data, s[i + 1], STAT))
                {
                    status = TRUE;
                }
                else if (TRUE == NOT(s[i + 1]) && FALSE == find(data, s[i + 2], STAT))
                {
                    status = TRUE;
                }
            }
        }
        else if (0 == i && FALSE == find(data, s[ i++], STAT))
        {
            status = TRUE;
        }
    }
    (void)stop;
    return (status);
}

static int make_decision(t_expert *data, char *goal, char *rule, int fact)
{
    char *ptr;
    int j;

    j = -1;                 
    while (rule[++j])
    {
        if (TRUE == (fact = (find(data, rule[j], FACT))))
            break ;
    }
    if (OR(*(goal - 1)) || OR(*(goal + 1)))
        fact = TRUE;
    else if (XOR(*(goal - 1)) || XOR(*(goal + 1)))
        fact = TRUE;
    if (NULL == (ptr = ft_strchr(data->solver, *goal)))
        return (FALSE);
    if ('1' == *(ptr + STATUS))
        return (FALSE);
    *(ptr + STATUS) = '1';
    *(ptr + FACTS) = (TRUE == fact ? '1': '0');
    return (TRUE);
}

static int decision(t_expert *data, char *goal, char *rule, int *status)
{
    int i;

    i = -1;
    *status = FALSE;
    while (goal[++i])
    {

        if (FALSE == LETTER(goal[i]))
        {
            continue ;
        }
        if (TRUE == NOT(goal[i - 1]) && (TRUE == find(data, goal[i], STAT)))
        {
            ft_printf("\x1b[31mThere is a contradiction with \x1b[34m%c\x1b[0m\n", goal[i]);
            exit(1);
        }
        else if (FALSE == NOT(goal[i - 1]))
        {
           *status += make_decision(data, &(goal[i]), rule, FALSE); //+=
        }
    }
    if (FALSE != *status)///global)
    {
        //dont show < !!!!
        ft_printf("\x1b[34m%s\x1b[0m is now true because \x1b[36m%s\x1b[0m is true and implies \x1b[34m%s\x1b[0m\n", goal, rule, goal);
    }
    return (*status);
}


void algorithm(t_expert *data, char *ptr, int i)
{
    char str[MAX * 2];
    int find;

    while (1)
    {
        i = -1;
        find = FALSE;
        while (data->rules[++i])
        {
            ft_bzero(str, MAX * 2);
            if ((ptr = ft_strchr(data->rules[i], '>')))
                ft_strcpy(str + R, ptr + 1);
            *ptr == '=' ? ptr-- : ptr;
            ft_strncpy(str, data->rules[i], ptr - (data->rules[i] + 1));
            if (ft_strchr(str, '<') && rules_is_true(data, str + R, FALSE, FALSE))
            {
                decision(data, str, str + R, &find);
            }
            if (rules_is_true(data, str, FALSE, FALSE))
            {
                decision(data, str + R, str, &find);
            }
        }
        if (FALSE == find)
            break ;
    }
}