#include "../include/push_swap.h"

void	ope_ra(t_data stacka)
{
	ope_rotate(stacka);
	write(1, "ra\n", 3);
}

void	ope_rb(t_data stackb)
{
	ope_rotate(stackb);
	write(1, "rb\n", 3);
}

void	ope_rra(t_data stacka)
{
	ope_revrotate(stacka);
	write(1, "rra\n", 4);
}

void	ope_rrb(t_data stackb)
{
	ope_revrotate(stackb);
	write(1, "rrb\n", 4);
}