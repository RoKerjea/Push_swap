#include "../include/push_swap.h"

void	mkstackb(t_stack stackb)
{
	stackb = malloc(sizeof(stackb));
	if (!stackb)
		return (NULL);
	stackb->next = NULL;
	stackb->prev = NULL;
}

void	mkstacka(int argc, t_stack stacka, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		stacka = malloc(sizeof(stacka));
		if (!stacka)
			return (NULL);
		if (checkarg(argv[i]) == 1)
			stacka->num = ft_atol(argv[i]);
		else
			return (-1);
		stacka->next = NULL;
		stacka->prev = NULL;
	}
}

int checkdup(t_stack stacka)
{
	int		i;
	t_stack	stacknext;

	i = 0;
	while (stacka != NULL)
	{
		stacknext = stacka->next;
		while(stacknext != NULL)
		{
			if (stacka->num == stacknext->num)
				return (-1);
			stacknext = stacknext->next;
		}
		stacka = stacka->next;
		i++;
	}
	return (1);
}

int	checkarg(char *str)
{
	int		i;
	int		j;
	long	l;

	i = 0;
	j = 0;
	while (str[i])
	{
		if ((str[i] < '0' || str[i] > '9')) && str[i] != '-')
			return (-1);
		if (str[i] >= '0' && str[i] <= '9')
			j++;
		if (str[i] == '-' && str[i + 1] == '-')
			return (-1);
		i++;
	}
	if (j == 0)
		return(-1);
	l =	ft_atol(str);
	if (l < -2147483648 || l > 2147483647)
	{
		return (-1);
	}
	return (1);
}

void	ft_printstacks(t_stack stacka, t_stack stackb)
{
	while (stacka)
	{
		ft_putnbr_fd(stacka->num, 1);
		write (1, '\n', 1);
		stacka = stacka->next;


	}

}

void	push_swap(int argc, t_stack stacks[2])
{
	ft_printstacks(stacks[0], stacks[1]);


}

int	main(int argc, char **argv)
{
	t_stack	stacks[2];

	if (argc == 1)
		return (0);
	mkstacka(argc, &stacks[0], argv);
	mkstackb(argc, &stacks[1]);
	push_swap(argc, &stacks);
	return (0);
}