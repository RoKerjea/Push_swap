#include "../include/push_swap.h"

unsigned int	push_to_other_stack2(t_data *stackgiver, t_data *stackreceiver, unsigned int chunksize)
{
	int non = 1;
	if (chunksize - stackgiver->count == 0)
		non = 0;
	int median;
	unsigned int	nextchunk;
	unsigned int	i;

	i = 0;
	nextchunk = 0;
	median = findmedianofchunk(stackgiver->first, chunksize);
	while (chunksize)
	{
		if (stackgiver->name == 'a')
		{
			if (stackgiver->first->num <= median)
			{
				named_ope_push(stackgiver, stackreceiver);
				nextchunk++;
			}
			if (stackgiver->first->num > median && stackgiver->count > 1)
			{
				named_ope_rotate(stackgiver);//prob here!!
				i++;
			}
		}
		if (stackgiver->name == 'b')
		{
			if (stackgiver->first->num > median)
			{
				named_ope_push(stackgiver, stackreceiver);
				nextchunk++;
			}
			if (stackgiver->first->num <= median && stackgiver->count > 1)
			{
				named_ope_rotate(stackgiver);//prob here!!
				i++;
			}
		}
		chunksize--;
	}
	if (non)
	{
		while (i && stackgiver->count > 1)
		{
			i--;
			named_ope_revrotate(stackgiver);
		}
	}
	return (nextchunk);
}

void	push_sorted_chunk2(t_data *stackgiver, t_data *stackreceiver, unsigned int chunksize)
{
	while (chunksize)
	{
		named_ope_push(stackgiver, stackreceiver);
		chunksize--;
	}
}

void	single_pi_quicksort(t_data *stackgiver, t_data *stackreceiver, unsigned int chunksize)
{
	unsigned int    nextchunk;

	nextchunk = 0;
	if (chunksize == 1 || chunksize == 0)
		return;
	if (chunksize == 2)
	{
		if (chunksize == 2 && isstacksort(stackgiver, chunksize) != 1)
			named_ope_swap(stackgiver);
		return;
	}
	if (chunksize >= 2 && isstacksort(stackgiver, chunksize) != 1)
		nextchunk = push_to_other_stack2(stackgiver, stackreceiver, chunksize);
	if (isstacksort(stackgiver, chunksize - nextchunk) != 1)
		single_pi_quicksort(stackgiver, stackreceiver, chunksize - nextchunk);//next quicksort for rest of stack
	single_pi_quicksort(stackreceiver, stackgiver, nextchunk);//next quicksort for superior quart
	push_sorted_chunk2(stackreceiver, stackgiver, nextchunk);
}