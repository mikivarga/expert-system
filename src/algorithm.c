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

int find(t_expert *data, char c, int flag)
{
    char *ptr;
    /*printf("find %s\n", data->solver);
    printf("find %s\n", (data->solver + STATUS));
    printf("find %s\n", (data->solver + FACTS));*/
    ptr = ft_strchr(data->solver, c);
    if (ptr)
    {
        if (STAT == flag)
        {
            ft_printf("current->STATUS %c\n", *(ptr + STATUS));
            return ('1' == *(ptr + STATUS));
        }
        else
        {
            ft_printf("current->f_facts %c\n", *(ptr + FACTS));
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
        //ft_printf("IDIOT %s\n", &s[i]);
        if (TRUE == LETTER(s[i]))
            status_letter(data, s, i, &status);
        else if (TRUE == BRACKETS(s[i]))
            status_brackets(data, s, i, &status);
        else if (TRUE == AND(s[i]))
            status_and(data, s, i, &status); 
        else if (TRUE == OR(s[i]))
        {
            if (FALSE == status_OR(data, s, i, &status) &&
            NULL == ft_strchr(s, '(') && (NULL != ft_strchr(s, '|') && FALSE == stop))
                return (TRUE);
        }
        else if (TRUE == XOR(s[i]))
            status_XOR(data, s, i, &status);
        else if (0 == i && FALSE == find(data, s[i + 1], STAT))
            status = TRUE;
    }
    return (status);
}

static int make_decision(t_expert *data, char *goal, char *rule, int fact)
{
    char *ptr;
    int j;

    j = -1;                 
    while (rule[++j])
    {;
        if (TRUE == find(data, rule[j], FACT))
        {
            fact = TRUE;
            break ;
        }
    }
    if (OR(*(goal - 1)) || OR(*(goal + 1)))
        fact = TRUE;
    else if (XOR(*(goal - 1)) || XOR(*(goal + 1)))
        fact = TRUE;
    ///herare error??
    if (NULL == (ptr = ft_strchr(data->solver, *goal)))
        return (FALSE);
    if ('1' == *(ptr + STATUS))
        return (FALSE);
    ft_printf("IDIOT\n");
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
            contradiction_exit(data, goal[i]);
        }
        else if (FALSE == NOT(goal[i - 1]))
        {
           *status += make_decision(data, &(goal[i]), rule, FALSE);
        }
    }
        if (FALSE != *status)///global)
    {
        ft_printf("\x1b[34m%s\x1b[0m is now true because \x1b[36m%s\x1b[0m is true and implies \x1b[34m%s\x1b[0m\n", goal, rule, goal);
    }
    return (*status);
}


void algorithm(t_expert *data, char *ptr, int find, int i)
{
    char *rule_r;
    char *rule_l;

    while (find)
    {
        i = -1;
        while (data->rules[++i])
        {
            if ((ptr = ft_strchr(data->rules[i], '>')))
                rule_r = ptr + 1;;
            *(ptr - 1) == '=' ? ptr-- : ptr;//??
            *(ptr) = '\0';
            rule_l = data->rules[i];
            ft_printf("~rule_l %s\n", rule_l);     
            if (ft_strchr(rule_l, '<') && rules_is_true(data, rule_r, FALSE, FALSE))
            {
                //ft_printf("<rule_l %s\n", rule_l);
                decision(data, rule_l, rule_r, &find);
               //if (decision(data, rule_l, rule_r, &find) && find && data->view)
               //     show_true_decision(rule_l, rule_r);
            }
            if (rules_is_true(data, rule_l, FALSE, FALSE))
            {
                //ft_printf("rule_l %s\n", rule_l);
                //if (decision(data, rule_r, rule_l, &find) && find && data->view)
                //    show_true_decision(rule_l, rule_r);
                decision(data, rule_r, rule_l, &find);
            }
            *(ptr) = '=';
        }
        ft_printf("\n  [DATA] = %s\n", data->solver);
        ft_printf("[STATUS] = %s\n", data->solver + STATUS);
        ft_printf(" [FACTS] = %s\n\n", data->solver + FACTS);
    }
}