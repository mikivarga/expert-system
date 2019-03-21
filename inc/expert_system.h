/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expert_system.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvarga <mvarga@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 12:59:51 by mvarga            #+#    #+#             */
/*   Updated: 2019/03/21 14:42:58 by mvarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPERT_SYSTEM_H
# define EXPERT_SYSTEM_H

# include <unistd.h>
# include "./../lib/libft/inc/libft.h"
# include "./../lib/ft_printf/inc/ft_printf.h"

# define MAX_READ 1024
# define BUFF_SIZE MAX_READ * 4

int					get_line(const int fd, char *line);

#endif
