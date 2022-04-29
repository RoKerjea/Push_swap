#include "../include/push_swap.h"

unsigned int	push_to_other_stack2(t_data *stackgiver, t_data *stackreceiver, unsigned int chunksize)
{
	//printf ("start of push med half with size of %d\n", chunksize);
	int median;
	unsigned int	nextchunk;
	unsigned int	i;

	i = 0;
	nextchunk = 0;
	median = findmedianofchunk(stackgiver->first, chunksize);
	//printf ("med = %d\n", median);
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
				//ft_printstacks(stackgiver, stackreceiver);
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
				//ft_printstacks(stackgiver, stackreceiver);
			}
		}
		chunksize--;
	}
	while (i && stackgiver->count > 1)
	{
		i--;
		named_ope_revrotate(stackgiver);
	}
	//printf ("end of push med half, chunk a = %d\n", nextchunk);
	return (nextchunk);
}

void	push_sorted_chunk2(t_data *stackgiver, t_data *stackreceiver, unsigned int chunksize)
{
/*
	printf ("start of push sorted size = %d\n", chunksize);
	if (isstacksort(stackgiver, chunksize) != 1)
	{
		printf("!!error, chunk of size %u not sorted when pushed back!\n", chunksize);
		printf("!!should be sent from stack %c to %c\n", stackgiver->name, stackreceiver->name);
		ft_printstacks(stackgiver, stackreceiver);
		exit(0);
	}*/
	while (chunksize)
	{
		named_ope_push(stackgiver, stackreceiver);
		chunksize--;
	}
//	printf ("end of push sorted\n");
}

void	single_pi_quicksort(t_data *stackgiver, t_data *stackreceiver, unsigned int chunksize)
{
	//printf ("start of single_pi_quicksort with size of %d\n", chunksize);
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
	{
		single_pi_quicksort(stackgiver, stackreceiver, chunksize - nextchunk);//next quicksort for rest of stack
	}
/*	printf("gate2\n");
	if (isstacksort(stackgiver, chunksize - nextchunk) != 1)
	{
		printf("!!error, chunk of size %u not sorted after first half of quicksrt!\n", chunksize - nextchunk);
		ft_printstacks(stackgiver, stackreceiver);
		exit(0);
	}*/
	//get lowerchunks back in full after new sort
	single_pi_quicksort(stackreceiver, stackgiver, nextchunk);//next quicksort for superior quart
	//printf("gate2\n");
	push_sorted_chunk2(stackreceiver, stackgiver, nextchunk);
	/*printf("top %u int of stack %c are supposed to be sorted\n", chunksize, stackgiver->name);
	ft_printstacks(stackgiver, stackreceiver);*/
}