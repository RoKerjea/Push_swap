/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rokerjea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 12:42:24 by rokerjea          #+#    #+#             */
/*   Updated: 2022/05/03 12:42:27 by rokerjea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>

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

typedef struct s_median
{
	long int	a;
	long int	b;
}		t_median;

typedef struct s_medindex
{
	unsigned int	start;
	unsigned int	res;
	unsigned int	end;
}		t_medindex;

/*LIB*/

long			ft_atol(const char *str);
void			ft_putnbr_fd(int n, int fd);
char			**ft_split(char const *s, char c);
char			*ft_strdup(const char *s1);
char			*ft_strjoin(char const *s1, char const *s2);
char			**ft_freetab(char **tab);
unsigned long	ft_strlen(const char *s);

/*sorted.c*/

int				isstacksort(t_data *stack, unsigned int size);
int				issort(t_link *link, unsigned int size);
int				issortrev(t_link *link, unsigned int size);

/*mklst*/

t_data			mkstacka(t_tabint tabint);
t_data			mkdata(void);

/*algo.c*/

//void			algo_5(t_data *stacka, t_data *stackb);
void			algo_3(t_data *stacka, t_data *stackb);

/*push.c*/

t_median		push_half(t_data *stkgiv, t_data *stkget, unsigned int size);
int				smallerintinstack(int median, t_data *stack, unsigned int size);
int				biggerintinstack(int median, t_data *stack, unsigned int size);

/* operation.c*/

void			waitpush(t_data *stackgiver, t_data *stackreceiver, char order);
void			ope_swap(t_data *datastack);
void			ope_rotate(t_data *datastack);
void			ope_revrotate(t_data *datastack);
void			ope_push(t_data *stackgiver, t_data *stackreceiver);

/*named_ope.c*/

void			named_ope_swap(t_data *stackgiver, t_data *stackreceiver);
void			named_ope_push(t_data *stackgiver, t_data *stackreceiver);
void			named_ope_rotate(t_data *stackgiver, t_data *stackreceiver);
void			named_ope_revrotate(t_data *stackgiver, t_data *stackreceiver);

/*secret_push.c*/

void			waitpush(t_data *stackgiver, t_data *stackreceiver, char order);
void			actualpush(t_data *stackgiver, t_data *stackreceiver);

/*double_ope.c*/

void			ope_ss(t_data *stackgiver, t_data *stackreceiver);
void			ope_rr(t_data *stackgiver, t_data *stackreceiver);
void			ope_rrr(t_data *stackgiver, t_data *stackreceiver);

/*parsing.c*/

t_tabint		make_tab_from_input(int argc, char **argv);

/*median.c*/

int				findmedianofchunk(t_link *link, unsigned int size, float aim);
void			swap(int *a, int *b);

/*quicksort.c*/

void			double_pi_quicksort(t_data *stg, t_data *str, unsigned int siz);
void			chunk_of_threeb(t_data *stkgiv, t_data *stkget);
void			chunk_of_threea(t_data *stkgiv, t_data *stkget);
void			pushswappush(t_data *stkgiv, t_data *stkget);

#endif
