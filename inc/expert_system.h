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
# include <stdlib.h>
# include "./../lib/libft/inc/libft.h"
# include "./../lib/ft_printf/inc/ft_printf.h"

# define RED(string) "\x1b[31m" string "\x1b[0m"
# define GREEN(string) "\x1b[32m" string "\x1b[0m"
# define YELLOW(string) "\x1b[33m" string "\x1b[0m"
# define BLUE(string) "\x1b[34m" string "\x1b[0m"
# define PINK(string) "\x1b[35m" string "\x1b[0m"

# define EMPTY_LINE(ch) ((ch) == '\n' || (ch) == '\0')
# define IS_SPACE(ch) ((ch) == ' ' || ((ch) > 8 && (ch) < 14))

# define LETTER(ch) ((ch) <= 'Z' && (ch) >= 'A')
# define BRACKETS(ch) ((ch) == '(' || (ch) == ')')
# define AND(ch) ((ch) == '+')
# define NOT(ch) ((ch) == '!')
# define OR(ch) ((ch) == '|')
# define XOR(ch) ((ch) == '^')
# define SYMB(ch) (AND((ch)) || OR((ch)) || XOR((ch)) || NOT((ch)))
# define MAX_READ 1024
# define BUFF_SIZE (MAX_READ * 4)

/*# define DATA 0*/
# define STAT 1
# define FACT 2
/*# define SYSTEM 3*/
# define MAX 27
# define STATUS (MAX)
# define FACTS (MAX * 2) 

# define R (MAX)
#define RUL_RES 2

# define IS_COMMENT '#'
# define FACTS_SMB '='
# define QUERIES_SMB '?'

typedef struct s_expert
{
    int view;
    char solver[MAX * 3];
    char facts[MAX];
    char queries[MAX];
    char **rules;
}               t_expert;

int get_line(const int fd, char *line);
int save_line(t_expert *data, char *str);
void algorithm(t_expert *data, char *ptr, int i);
void show_err(const char *str);
void show_err_parsing(const char *str, const char *buf);
void		display(int lim, ...);


void free_data(t_expert *data);
#endif
