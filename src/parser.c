/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvarga <mvarga@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 12:43:59 by mvarga            #+#    #+#             */
/*   Updated: 2019/03/31 16:20:16 by mvarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expert_system.h"

static int		add_rules(t_expert *data, char *str)
{
	static int	nmb = 0;
	char		**pp;
	char		**old_rules;
	int			i;

	i = 0;
	if (NULL == (pp = (char **)malloc(sizeof(char *) * (nmb + 2))))
	{
		show_err(YELLOW("Unable to allocate memory\n"));
		return (FALSE);
	}
	old_rules = data->rules;
	while (nmb && old_rules[i])
	{
		pp[i] = old_rules[i];
		i++;
	}
	pp[i++] = ft_strdup(str);
	pp[i] = 0;
	if (nmb++)
	{
		free(old_rules);
	}
	data->rules = pp;
	return (TRUE);
}

static int		checking_rules(char *buf, int flag)
{
	int i;

	i = 0;
	while (buf[i])
	{
		if (LETTER(buf[i]) || BRACKETS(buf[i]) || SYMB(buf[i]))
		{
			i++;
		}
		else if (TRUE == flag && 0 == ft_strncmp(buf + i, "=>", 2))
		{
			flag = FALSE;
			i += 2;
		}
		else if (TRUE == flag && 0 == ft_strncmp(buf + i, "<=>", 3))
		{
			flag = FALSE;
			i += 3;
		}
		else
		{
			return (FALSE);
		}
	}
	return (TRUE);
}

static int		save_rules(t_expert *data, char *buf)
{
	char		**ptr;

	ptr = data->rules;
	while (NULL != ptr && NULL != *ptr)
	{
		if (0 == ft_strcmp(*ptr++, buf))
		{
			return (TRUE);
		}
	}
	if ('!' != buf[0])
	{
		if (FALSE == LETTER(buf[0]))
		{
			printf("IDIOT\n");
			return FALSE;
		}
	}
	if (FALSE == checking_rules(buf, TRUE))
	{
		return (FALSE);
	}
	return (add_rules(data, buf));
}

static int		save_facts_queries(t_expert *data, char *buf)
{
	char		*ptr;
	char		*tmp;

	ptr = (FACTS_SMB == *buf ? data->facts : data->queries);
	while (*++buf)
	{
		if (TRUE == LETTER(*buf))
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
			return (FALSE);
		}
		*tmp = *buf;
	}
	return (TRUE);
}

int				save_line(t_expert *data, char *buf)
{
	char		*ptr;
	char		str[BUFF_SIZE];

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
		return (save_facts_queries(data, str));
	}
	return (save_rules(data, str));
}
