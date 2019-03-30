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

/*

void				save_rooms(t_map *pmap, char *str)
{
	char	**pp;
	char	**old_rooms;
	int		i;

	i = 0;
	if (!*str)
		return ;
	if (!(pp = (char **)malloc(sizeof(char *) * (pmap->number_of_rooms + 2))))
		exit_func(pmap, "Unable to allocate memory!");
	old_rooms = pmap->the_rooms;
	while (pmap->number_of_rooms && old_rooms[i])
	{
		if (!ft_strcmp(old_rooms[i], str))
		{
			free(pp);
			exit_func(pmap, ERR_MSG);
		}
		pp[i] = old_rooms[i];
		i++;
	}
	pp[i++] = ft_strdup(str);
	pp[i] = 0;
	if (pmap->number_of_rooms++)
		free(old_rooms);
	pmap->the_rooms = pp;
}

*/


static int add_rules(t_expert *data, char *str)
{
    static int nmb = 2;
    char *pp;
    char **old_rules;
    int i;

    i = 0;
    if (NULL == (pp = (char **)malloc(sizeof(char *) * (nmb++ + 2))))
    {
	    //	exit_func(pmap, "Unable to allocate memory!");
    }


    (void)pp;
    (void)old_rules;
    (void)i;
    (void)data;
    (void)str;
    return (TRUE);
}

static int save_rules(t_expert *data, char *buf)
{
    char **ptr;
    //char **tmp;

    ptr = data->rules;
    while (NULL != ptr && NULL != *ptr)
    {
        if (0 == ft_strcmp(*ptr++, buf))
        {
            return (TRUE);
        }
    }
    /*
    int i;

    i = 0;
    while (line[i])
    {
        if (line[i] <= 'Z' && line[i] >= 'A')
            i++;
        else if (line[i] == '(' || line[i] == ')')
            i++;
        else if (line[i] == '+' || line[i] == '|' || line[i] == '^')
            i++;
        else if (ft_strncmp(line + i, "=>", 2) == 0)
            i+=2;
        else if (ft_strncmp(line + i, "<=>", 3) == 0)
            i+=3;
        else if (line[i] == '!')
            i++;
        else
            return (-1);
    }
    return (1);
}


    */
    ft_printf("rules %s\n", buf);
    (void)*ptr;
    return (add_rules(data, buf));
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