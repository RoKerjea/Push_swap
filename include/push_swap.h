
#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>

typedef struct s_data
{
	struct s_link *first;
	struct s_link *last;
}		t_data;

typedef struct s_link
{
	int				num;
	struct s_link	*next;
	struct s_link	*prev;
}		t_link;

/*LIB*/

long	ft_atol(const char *str);
void	ft_putnbr_fd(int n, int fd);

/*push_swap.c*/

int		issort(t_link *stack);
void	ft_printstacks(t_link *stacka, t_link *stackb);
void	ft_printstacksrev(t_link *stacka, t_link *stackb);

/*mklst*/

t_link	*mkstacklink(void);
t_data	mkstacka(int argc, char **argv);
int		checkarg(char *str);
t_data	mkdata(void);

/*algo.c*/
void	algo_100(int argc, t_data *stacka, t_data *stackb);
void	algo_5(int argc, t_data *stacka, t_data *stackb);
void	algo_3(t_data *stacka);

/* operation.c*/

void	ope_swap(t_data *datastack);
void	ope_rotate(t_data *datastack);
void	ope_revrotate(t_data *datastack);
void	ope_push(t_data *stackgiver, t_data *stackreceiver);

/*named_ope1.c*/

void	ope_sa(t_data *stacka);
void	ope_sb(t_data *stackb);
void	ope_pa(t_data *stacka, t_data *stackb);
void	ope_pb(t_data *stacka, t_data *stackb);

/*named_ope2.c*/

void	ope_ra(t_data *stacka);
void	ope_rb(t_data *stackb);
void	ope_rra(t_data *stacka);
void	ope_rrb(t_data *stackb);

/*double_ope.c*/

void	ope_ss(t_data *stacka, t_data *stackb);
void	ope_rr(t_data *stacka, t_data *stackb);
void	ope_rrr(t_data *stacka, t_data *stackb);

#endif