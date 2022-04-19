#include "../include/push_swap.h"

void	ft_printstacks(t_link *stacka, t_link *stackb)
{
	write (1, "stacks first to last\n", 21);
	while (stacka || stackb)
	{
		if (stacka)
		{
			ft_putnbr_fd(stacka->num, 1);
			stacka = stacka->next;
		}
		write (1, " | ", 3);
		if (stackb)
		{
			ft_putnbr_fd(stackb->num, 1);
			stackb = stackb->next;
		}
		write (1, "\n", 1);
	}
	write (1, "\n", 1);
}

void	printtab(t_tabint tabint)
{
	unsigned int	i;

	i = 0;
	printf ("printing *int\n");
	while (i < tabint.count)
	{
		printf("%d\n", tabint.tab[i]);
		i++;
	}
	free(tabint.tab);
	exit(0);
}

void	ft_printstacksrev(t_link *stacka, t_link *stackb)
{
	write (1, "stacks last to first\n", 21);
	while (stacka || stackb)
	{
		if (stacka)
		{
			ft_putnbr_fd(stacka->num, 1);
			stacka = stacka->prev;
		}
		write (1, " | ", 3);
		if (stackb)
		{
			ft_putnbr_fd(stackb->num, 1);
			stackb = stackb->prev;
		}
		write (1, "\n", 1);
	}
	write (1, "\n", 1);
}
