/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvarga <mvarga@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 13:46:32 by mvarga            #+#    #+#             */
/*   Updated: 2019/03/21 13:46:56 by mvarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expert_system.h"

#define GNL_END 0
#define GNL_ERR -1
#define GNL_INSIDE 1

static int	read_line(char *saved_buff, char *buff, char *line)
{
	char	*next_line;

	ft_bzero(line, BUFF_SIZE + 1);
	ft_strncat(saved_buff, buff, ft_strlen(buff));
	if ((next_line = ft_strchr(saved_buff, '\n')))
	{
		*next_line++ = '\0';
		ft_memcpy(line, saved_buff, ft_strlen(saved_buff));
		ft_memmove(saved_buff, next_line, ft_strlen(next_line) + 1);
		return (TRUE);
	}
	return (FALSE);
}

int			get_line(const int fd, char *line)
{
	ssize_t		num_read;
	char		buff[MAX_READ + 1];
	static char	saved_buff[BUFF_SIZE + 1];

	ft_bzero(buff, MAX_READ + 1);
	if (read_line(saved_buff, buff, line))
		return (GNL_INSIDE);
	while ((num_read = read(fd, buff, MAX_READ)) > 0)
	{
		if (read_line(saved_buff, buff, line))
			return (GNL_INSIDE);
		ft_bzero(buff, MAX_READ + 1);
	}
	if (*saved_buff)
	{
		ft_memcpy(line, saved_buff, ft_strlen(saved_buff));
		ft_bzero(saved_buff, BUFF_SIZE + 1);
		return (GNL_INSIDE);
	}
	return (num_read == -1 ? GNL_ERR : GNL_END);
}
