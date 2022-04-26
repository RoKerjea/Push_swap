
#include "../include/push_swap.h"

void	double_pi_quicksort(t_data *stackgiver, t_data *stackreceiver, unsigned int 	chunksize)
{
	int median;
	int	lowquartian;
	unsigned int	nextchunk;//?

	if (chunksize == 2 && isstacksort(stackgiver, chunksize) != 1)
	{
		ope_swap(stackgiver);
		return;
	}
	nextchunk = 0;
	median = findmedianofchunk(stackgiver->first, chunksize);
	lowquartian = //TODO;
	while (smallerintinstack(median, stackgiver))
	{
		if (stackgiver->first->num > median)
			ope_ra(stackgiver);
		if (stackgiver->first->num <= median)
		{
			nextchunk++;
			if (stackgiver->first->num <= lowquartian)
			{
				ope_pb(stackgiver, stackreceiver);
				ope_rb(stackreceiver);
			}
			if (stackgiver->first->num > lowquartian)
				ope_pb(stackgiver, stackreceiver);
		}
	}
	while (stackreceiver->first > lowquartian)
		ope_rrb(stackreceiver);
	if (isstacksort(stackgiver, 0) != 1)
		quicksort(stackgiver, stackreceiver, 0);
	quicksort(stackreceiver, stackgiver, nextchunk / 2);
	quicksort(stackreceiver, stackgiver, nextchunk / 2);
	while (nextchunk)
	{
		ope_pa(stackgiver);
		nextchunk--;
	}
}