
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
	char			name;
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

/*sorted.c*/

int		isstacksort(t_data *stack, unsigned int size);
int		issort(t_link *link, unsigned int size);
int		issortrev(t_link *link, unsigned int size);

/*printforcheck  TO_DELETE*/
void	ft_printstacks(t_data *stackone, t_data *stacktwo);
void	ft_printstacksrev(t_link *stacka, t_link *stackb);
void	printtab(t_tabint tabint);

/*mklst*/

//t_link	*mkstacklink(void);
t_data	mkstacka(t_tabint tabint);
//int		checkarg(char *str);
t_data	mkdata(void);

/*algo.c*/

void	algo_5(t_data *stacka, t_data *stackb);
void	algo_3(t_data *stacka);
int		smallerintinstack(int median, t_data *stack);
int		biggerintinstack(int median, t_data *stack);

/* operation.c*/

void	ope_swap(t_data *datastack);
void	ope_rotate(t_data *datastack);
void	ope_revrotate(t_data *datastack);
void	ope_push(t_data *stackgiver, t_data *stackreceiver);

/*named_ope1.c*/


void	named_ope_swap(t_data *stack);
void	named_ope_push(t_data *stackgiver, t_data *stackreceiver);

/*named_ope2.c*/

void	named_ope_rotate(t_data *stack);
void	named_ope_revrotate(t_data *stack);

/*double_ope.c*/

void	ope_ss(t_data *stacka, t_data *stackb);
void	ope_rr(t_data *stacka, t_data *stackb);
void	ope_rrr(t_data *stacka, t_data *stackb);

/*parsing.c*/

t_tabint	make_tab_from_input(int argc, char **argv);

/*median.c*/

int	findmedianofchunk(t_link *link, unsigned int chunksize);
int	findquartianofchunk(t_link *link, unsigned int chunksize);
int	findupquartianofchunk(t_link *link, unsigned int chunksize);


void	double_pi_quicksort(t_data *stackgiver, t_data *stackreceiver, unsigned int chunksize);
void	single_pi_quicksort(t_data *stackgiver, t_data *stackreceiver, unsigned int chunksize);

#endif