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

static void add_to_solver(t_expert *data) //перенести до main?
{
    int i;
    int j;

    i = 0;
    while (data->facts[i])
    {
        data->solver[DATA][i] = data->facts[i];
        data->solver[STATUS][i] = TRUE;
        data->solver[FACTS][i] = FALSE;
        i++;
    }
    if ('\0' == data->solver[DATA][i])
    {
        while (data->queries[i])
        {
            data->solver[DATA][i] = data->facts[i];
            data->solver[STATUS][i] = FALSE;
            data->solver[FACTS][i] = FALSE;
            i++;
        }
    }
    else
    {
        //check duplicate letters
    }
    //add to solver ruls leters
    (void)j;
}

void algorithm(t_expert *data)
{
    add_to_solver(data);
    printf("data->facts[i] = %s\n", data->solver[DATA]);
    (void)data;
}