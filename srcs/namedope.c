#include "../include/push_swap.h"

void	ope_sa(t_data *datastack)
{
	if (datastack->first != NULL && datastack->first != datastack->last)
	{
		ope_swap(datastack);
		write (1, "sa\n", 3);
	}
}

void	ope_sb(t_data *datastack)
{
	if (datastack->first != NULL && datastack->first != datastack->last)
	{
		ope_swap(datastack);
		write (1, "sb\n", 3);
	}
}

void	ope_pa(t_data *stacka, t_data *stackb)
{
	if (stackb->first != NULL)
	{
		ope_push(stackb, stacka);
		write (1, "pa\n", 3);
	}
}

void	ope_pb(t_data *stacka, t_data *stackb)
{
	if (stacka->first != NULL)
	{
		ope_push(stacka, stackb);
		write (1, "pb\n", 3);
	}
}