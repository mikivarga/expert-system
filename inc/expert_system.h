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
# include <fcntl.h>
# include "./../lib/libft/inc/libft.h"
# include "./../lib/ft_printf/inc/ft_printf.h"

# define RED(string) "\x1b[31m" string "\x1b[0m"
# define GREEN(string) "\x1b[32m" string "\x1b[0m"
# define YELLOW(string) "\x1b[33m" string "\x1b[0m"
# define BLUE(string) "\x1b[34m" string "\x1b[0m"
# define PINK(string) "\x1b[35m" string "\x1b[0m"

# define EMPTY_LINE(ch) ((ch) == '\n' || (ch) == '\0')
# define IS_SPACE(ch) ((ch) == ' ' || ((ch) > 8 && (ch) < 14))
# define NON_COMPLIANT_LINE(ch) (EMPTY_LINE((ch)) || IS_SPACE((ch)))
# define IS_ALPHA(ch) ((ch) <= 'Z' && (ch) >= 'A')
# define MAX_READ 1024
# define BUFF_SIZE (MAX_READ * 4)

# define DATA 0
# define STATUS 1
# define FACTS 2
# define SYSTEM 3
# define MAX_FACTS_QUERIES 27

# define IS_COMMENT '#'
# define FACTS_SMB '='
# define QUERIES_SMB '?'

typedef struct s_expert
{
    int number_rules;
    char *arr[SYSTEM];
    char facts[MAX_FACTS_QUERIES];
    char queries[MAX_FACTS_QUERIES];
    char **rules;
}               t_expert;

int get_line(const int fd, char *line);
void show_err(const char *str);
void show_err_character(const char *str, const char c, const char place);
int save_line(t_expert *data, char *str);

#endif
