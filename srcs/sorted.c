#include "../include/push_swap.h"

int	issatcksort(t_data stack, unsigned int size)
{
	if (stack.name == 'a')
		return (issort(stack->first, size));
	if (stack.name == 'b')
		return (issortrev(stack->first, size));
	return (-1);
}

int	issort(t_link *link, unsigned int size)
{
	int	tmp;

	tmp = link->num;
	link = link->next;
	while (--size)
	{
		if (tmp > link->num)
			return (-1);
		tmp = link->num;
		link = link->next;
	}
	return (1);
}

int	issortrev(t_link *link, unsigned int size)
{
	if (link == NULL)
		return (-1);
	int	tmp;

	tmp = link->num;
	link = link->prev;
	while (--size)
	{
		if (tmp > link->num)
			return (-1);
		tmp = link->num;
		link = link->prev;
	}
	return (1);
}