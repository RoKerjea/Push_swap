
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

long	ft_atol(const char *str);
void	ft_putnbr_fd(int n, int fd);
t_link	*mkstacklink(void);
t_data	mkstacka(int argc, char **argv);
int		checkarg(char *str);
t_data	mkdata(void);
void	ope_swap(t_data *datastack);
void	ope_rotate(t_data *datastack);
void	ope_revrotate(t_data *datastack);
void	ope_push(t_data *stackgiver, t_data *stackreceiver);

#endif