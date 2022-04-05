
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
	struct s_stack *first;
	struct s_stack *last;
}		t_data;

typedef struct s_stack
{
	int				num;
	struct s_stack	*next;
	struct s_stack	*prev;
}		t_stack;

long	ft_atol(const char *str);
void	ft_putnbr_fd(int n, int fd);
t_stack	*mkstacklink(void);
t_data	mkstacka(int argc, char **argv);
int		checkarg(char *str);

#endif