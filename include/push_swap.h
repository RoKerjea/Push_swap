
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
	unsigned int	count;
	struct s_link	*first;
	struct s_link	*last;
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
	int a;
	int b;
}		t_median;



/*LIB*/

long	ft_atol(const char *str);
void	ft_putnbr_fd(int n, int fd);
char	**ft_split(char const *s, char c);
unsigned long	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_freetab(char **tab);

/*push_swap.c*/

int		issort(t_link *stack);
int		issortrev(t_link *stack);

/*printforcheck  TO_DELETE*/
void	ft_printstacks(t_link *stacka, t_link *stackb);
void	ft_printstacksrev(t_link *stacka, t_link *stackb);
void	printtab(t_tabint tabint);

/*mklst*/

//t_link	*mkstacklink(void);
t_data	mkstacka(t_tabint tabint);
//int		checkarg(char *str);
t_data	mkdata(void);

/*algo.c*/

void	algo_100(t_data *stacka, t_data *stackb);
void	algo_5(t_data *stacka, t_data *stackb);
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

/*parsing.c*/

t_tabint	make_tab_from_input(int argc, char **argv);

/*median.c*/

int	findmedianofchunk(t_link *link, unsigned int chunksize);

#endif