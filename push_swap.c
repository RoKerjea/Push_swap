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



}

int checkdup (t_stack stacka)
{
	int		i;
	t_stack	stacknext;

	i = 0;
	while (stacka != NULL)
	{
		stacknext = stacka->next
		while(stacknext != NULL)
		{
			if (stacka->num == stacknext->num)
				return (-1);
			stacknext = stacknext->next
		}
		stacka = stacka->next
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
			return (-1)
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
		ft_printf("Error\n");
		return (0);
	}
	i = l;
	return (i);
}

void	push_swap(int argc, int *stacka, int *stackb)
{



}

int	main(int argc, char **argv)
{
	t_stack	stacks[2];


	mkstacka(argc, &stacks[0], argv);
	mkstackb(argc, &stacks[1]);
	push_swap(argc, &stacks);
	return (0);
}