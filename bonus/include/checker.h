/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rokerjea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 18:10:16 by rokerjea          #+#    #+#             */
/*   Updated: 2022/05/08 18:10:22 by rokerjea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>

typedef struct s_data
{
	unsigned int	len;
	char			name;
	struct s_link	*first;
	struct s_link	*last;
	int				waitcount;
	char			waitpushto;
}		t_data;

typedef struct s_link
{
	int				num;
	struct s_link	*next;
	struct s_link	*prev;
}		t_link;

typedef struct s_tabint
{
	unsigned int	count;
	int				*tab;
}		t_tabint;

/*LIB*/

long			ft_atol(const char *str);
char			**ft_split(char const *s, char c);
char			*ft_strdup(const char *s1);
char			*ft_strjoin(char const *s1, char const *s2);
void			ft_freetab(char **tab);
unsigned long	ft_strlen(const char *s);

/*sorted.c*/

int				isstacksort(t_data *stack, unsigned int size);
int				issort(t_link *link, unsigned int size);
int				issortrev(t_link *link, unsigned int size);

/*mklst*/

t_data			mkstacka(t_tabint tabint);
t_data			mkdata(void);

/* operation.c*/

void			waitpush(t_data *stackgiver, t_data *stackreceiver, char order);
void			ope_swap(t_data *datastack);
void			ope_rotate(t_data *datastack);
void			ope_revrotate(t_data *datastack);
void			ope_push(t_data *stackgiver, t_data *stackreceiver);

/*parsing.c*/

t_tabint		make_tab_from_input(int argc, char **argv);

#endif
