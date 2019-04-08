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
            else if (NULL == ft_strchr(beg, '('))
            {
                if (NULL != ft_strchr(beg, '|') && FALSE == stop)
                {
                    return (1);
                }
            }
        }
        else if ('+' == beg[i])
        {
            char *ptr;

            if (TRUE == status)
            {
                if ('!' == beg[i + 1])
                {
                    ptr = ft_strchr(data->solver[DATA], beg[i + 2]);
                    if (*ptr)
                    {
                        if ('+' == *(ptr + MAX))
                        {
                            status = FALSE;
                        }
                    }
                }
                if (LETTER(beg[i + 1]))
                {
                    ptr = ft_strchr(data->solver[DATA], beg[i + 1]);
                    if (*ptr)
                    {
                        if ('-' == *(ptr + MAX))
                        {
                            status = FALSE;
                        }
                    }
                }
            }
            else
            {
                status = FALSE;
            }
            
        }
        else if ('^' == beg[i])
        {
            char *ptr;

            if (TRUE == status)
            {
                if ('!' == beg[i + 1])
                {
                    ptr = ft_strchr(data->solver[DATA], beg[i + 2]);
                    if (*ptr)
                    {
                        if ('-' == *(ptr + MAX))
                        {
                            status = FALSE;
                        }
                    }
                }
                ptr = ft_strchr(data->solver[DATA], beg[i + 1]);
                if (*ptr)
                {
                    if ('+' == *(ptr + MAX) && '-' == *(ptr + MAX * 2))
                    {
                        status = FALSE;
                    }
                }
            }
            else
            {
                if ('!' == beg[i + 1])
                {
                    ptr = ft_strchr(data->solver[DATA], beg[i + 2]);
                    if (*ptr)
                    {
                        if ('-' == *(ptr + MAX))
                        {
                            status = TRUE;
                        }
                    }
                }
                ptr = ft_strchr(data->solver[DATA], beg[i + 1]);
                if (*ptr)
                {
                    if ('+' == *(ptr + MAX))
                    {
                        status = TRUE;
                    }
                }
            }
        }
        else if (TRUE == BRACKETS(beg[i]))
        {

        }
        else if (i == 0) // (i - 1 < 0)
        {
            char *ptr;

            ptr = ft_strchr(data->solver[DATA], beg[i + 1]);
            if (*ptr)
            {
                if ('+' == *(ptr + MAX))
                {
                    status = TRUE;
                }
            }
        }
    }
    //ft_printf("  [DATA] = %s\n", data->solver[DATA]);
    //ft_printf("[STATUS] = %s\n", data->solver[STATUS]);
    //ft_printf(" [FACTS] = %s\n\n", data->solver[FACTS]);
    (void)stop;
    (void)data;
    (void)beg;
    return (status);
}

static int     make_true(t_expert *data, char *str1, char *str2)
{
    int i;
    int j;
    int status;
    char *ptr;

    status = FALSE;
    i = -1;
    while (str2[++i])
    {
        j = -1;
        while (data->solver[DATA][++j])
        {
            if (data->solver[DATA][j] == str2[i] && '+' == data->solver[DATA][j + MAX *2])
            {
                status = TRUE;
            }
        }
    }
    i = -1;
    while (str1[i++])
    {
        if (LETTER(str1[i++]))
        {
            if (str1[i - 1] != '!')
            {
                if (str1[i - 1] == '|' || str1[i + 1] == '|' || str1[i - 1] == '^' || str1[i + 1] == '^' || status)
                {

                }
                else
                {
                    
                }
                
            }
            if (str1[i - 1] == '!')
            {

            }
        }
    }
}*/

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

int rules_is_true(t_expert *data, char *str, int status, int stop)
{
    (void)data;
    (void)str;
    (void)status;
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
        {
            break ;
        }
    }
    if (OR(*(goal - 1)) || OR(*(goal + 1)))
    {
        fact = TRUE;
    }
    else if (XOR(*(goal - 1)) || XOR(*(goal + 1)))
    {
        fact = TRUE;
    }
    if (NULL == (ptr = ft_strchr(data->solver, *goal)))
    {
        return (FALSE);
    }
    if ('1' == *(ptr + STATUS))
    {
        return (FALSE);
    }
    *(ptr + STATUS) = '1';
    *(ptr + FACTS) = (TRUE == fact ? '1': '0');
    return (TRUE);
}

int decision(t_expert *data, char *goal, char *rule)
{
    int status;
    int i;

    i = -1;
    status = FALSE;
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
            status += make_decision(data, &(goal[i]), rule, FALSE);
        }
    }
    if (FALSE != status)///global)
    {
        ft_printf("\x1b[34m%s\x1b[0m is now true because \x1b[36m%s\x1b[0m is true and implies \x1b[34m%s\x1b[0m\n", goal, rule, goal);
    }
    return (status);
}


void algorithm(t_expert *data, char *ptr, int i)
{
    char str[MAX * 2];
    int ret;

    while (1)
    {
        i = -1;
        ret = FALSE;
        while (data->rules[++i])
        {
            ft_bzero(str, MAX * 2);
            if ((ptr = ft_strchr(data->rules[i], '>')))
            {
                ft_strcpy(str + R, ptr + 1);
            }
            *ptr == '=' ? ptr-- : ptr;
            ft_strncpy(str, data->rules[i], ptr - (data->rules[i] + 1));
            if (ft_strchr(str, '<'))
            {
                ft_printf("MIKI\n");
            }
            //printf("%s\n%s\n\n", str, str + R);
            //if (TRUE == rules_is_true(data, str, FALSE, FALSE))
            {
                //ft_printf("first %s\nlast %s\n", str, str + R);
                ret = decision(data, str + R, str);
                
                ft_printf("ret = %d\n", ret);
            }
        }
        //if (FALSE == ret)
        {
            break ;
        }
    }
    ft_printf("  [DATA] = %s\n", data->solver);
    ft_printf("[STATUS] = %s\n", data->solver + STATUS);
    ft_printf(" [FACTS] = %s\n\n", data->solver + FACTS);
}