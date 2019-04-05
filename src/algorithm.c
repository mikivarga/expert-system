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

static void add_to_solver(t_expert *data)
{
    int i;
    int j;
    int z;

    i = 0;
    while (data->facts[i])
    {
        data->solver[DATA][i] = data->facts[i];
        data->solver[STATUS][i] = '+';//TRUE;
        //ft_printf("data->solver[STATUS][i] = '+' %s", data->solver[STATUS]);
        data->solver[FACTS][i] = '-';//;FALSE;
        i++;
    }
    i = 0;
    while (data->queries[i])
    {
        j = 0;
        while (data->solver[DATA][j])
        {
            if (data->solver[DATA][j] == data->queries[i])
            {
                break ;
            }
            j++;
        }
        if ('\0' == data->solver[DATA][j])
        {
            data->solver[DATA][j] = data->queries[i];
            data->solver[STATUS][j] = '-';//FALSE;
            data->solver[FACTS][j] = '-';//FALSE;
        }
        i++;
    }
    i = 0;
    while (data->rules[i])
    {
        j = 0;
        while (data->rules[i][j])
        {
            if (ALPHA(data->rules[i][j]))
            {
                z = 0;
                while (data->solver[DATA][z])
                {
                    if (data->solver[DATA][z] == data->rules[i][j])
                    {
                        break ;
                    }
                    z++;
                }
                if ('\0' == data->solver[DATA][z])
                {
                    data->solver[DATA][z] = data->rules[i][j];
                    data->solver[STATUS][z] = '-';//FALSE;
                    data->solver[FACTS][z] = '-';//FALSE;
                }
            }
            j++;
        }
        i++;
    }
}

void algorithm(t_expert *data)
{
    add_to_solver(data);
    ft_printf("  [DATA] = %s\n", data->solver[DATA]);
    ft_printf("[STATUS] = %s\n", data->solver[STATUS]);
    ft_printf(" [FACTS] = %s\n", data->solver[FACTS]);
}