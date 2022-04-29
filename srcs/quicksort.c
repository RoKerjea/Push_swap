/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rokerjea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 12:41:08 by rokerjea          #+#    #+#             */
/*   Updated: 2022/04/27 12:41:12 by rokerjea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_median	push_to_other_stack(t_data *stackgiver, t_data *stackreceiver, unsigned int chunksize)
{
	//printf("size = %u, count = %u\n",chunksize, stackgiver->count);
	int non = 1;
	if (chunksize - stackgiver->count == 0)
		non = 0;
	//printf ("start of push med quart with size of %d\n", chunksize);
	int median;
	int	lowquartian;
	t_median	nextchunk;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	nextchunk.a = 0;
	nextchunk.b = 0;
	median = findmedianofchunk(stackgiver->first, chunksize);
	lowquartian = findquartianofchunk(stackgiver->first, chunksize);
	//printf ("median = %d, quartian = %d\n", median, lowquartian);
	while (smallerintinstack(median, stackgiver) && chunksize && stackgiver->name == 'a')
	{
		if (stackgiver->first->num > median && stackgiver->count > 1)
		{
			named_ope_rotate(stackgiver);//prob here!!
			i++;
		}
		if (stackgiver->first->num <= median)
		{
			if (stackgiver->first->num <= lowquartian)//inferior quart to top of stack b before rrb, end in second pos after rrb
			{
				nextchunk.b++;
				named_ope_push(stackgiver, stackreceiver);		
			}
			else if (stackgiver->first->num > lowquartian)//superior quart to bottom of stack b before rrb, end in first pos after rrb
			{
				nextchunk.a++;
				named_ope_push(stackgiver, stackreceiver);
				j++;
				if (stackreceiver->count > 1)
				{
					named_ope_rotate(stackreceiver);
				}
			}
		}
		chunksize--;
	}

	while (smallerintinstack(median, stackgiver) && chunksize && stackgiver->name == 'b')
	{
		if (stackgiver->first->num <= median && stackgiver->count > 1)
		{
			named_ope_rotate(stackgiver);//prob here!!
			i++;
		}
		if (stackgiver->first->num > median)
		{
			if (stackgiver->first->num <= lowquartian)//inferior quart to bottom of a before rra, end in first pos after rra
			{
				nextchunk.a++;
				named_ope_push(stackgiver, stackreceiver);
				if (stackreceiver->count > 1)
				{
					j++;
					named_ope_rotate(stackreceiver);
				}
				//ft_printstacks(stackgiver, stackreceiver);			
			}
			else if (stackgiver->first->num > lowquartian)//superior quart to top of a before rra, end in second pos after rra
			{
				nextchunk.b++;
				named_ope_push(stackgiver, stackreceiver);
				//ft_printstacks(stackgiver, stackreceiver);
			}
		}
		chunksize--;
	}
	while (i && j && non && stackgiver->count > 1 && stackreceiver->count > 1)
	{
		i--;
		j--;
		ope_rrr(stackgiver, stackreceiver);
	}
	while (non && i && stackgiver->count > 1)
	{
		i--;
		named_ope_revrotate(stackgiver);
	}
	while (j)
	{
		j--;
		named_ope_revrotate(stackreceiver);//get sup quart to top of stack, to keep sorted

	}
	return (nextchunk);
}

void	push_sorted_chunk(t_data *stackgiver, t_data *stackreceiver, unsigned int chunksize)
{
	while (chunksize)
	{
		named_ope_push(stackgiver, stackreceiver);
		chunksize--;
	}
}

/*
	take all of chunksize of stackgiv
	send lower half to stckreceiv
	reuse qcksort to upper half
	until chunk empty or sorted
	reuse qcksrt for lower half, etc
	recuperate lowerhalf
	everything should be sorted
*/
void	lower_med_quicksort(t_data *stackgiver, t_data *stackreceiver, t_median	nextchunk)
{
	double_pi_quicksort(stackreceiver, stackgiver, nextchunk.a);//next quicksort for superior quart		
	push_sorted_chunk(stackreceiver, stackgiver, nextchunk.a);
	double_pi_quicksort(stackreceiver, stackgiver, nextchunk.b);//next quicksort for inferior quart		
	push_sorted_chunk(stackreceiver, stackgiver, nextchunk.b);
	/*if (isstacksort(stackgiver, (nextchunk.a + nextchunk.b)) != 1)
	{
		printf("!!error, chunk of size %u not sorted after both lowermedquicsrt!\n", nextchunk.a + nextchunk.b);
		ft_printstacks(stackgiver, stackreceiver);
		exit(0);
	}*/
}

//at end of function, chunksize should be sorted

void	double_pi_quicksort(t_data *stackgiver, t_data *stackreceiver, unsigned int chunksize)
{
	//printf ("start of double_pi_quicksort with size of %d\n", chunksize);
	//ft_printstacks(stackgiver, stackreceiver);
	t_median	nextchunk;

	nextchunk.a = 0;
	nextchunk.b = 0;
	if (chunksize == 1 || chunksize == 0)
		return;
	if (chunksize == 2)
	{
		if (chunksize == 2 && isstacksort(stackgiver, chunksize) != 1)
			named_ope_swap(stackgiver);
		return;
	}
	if (chunksize >= 2 && isstacksort(stackgiver, chunksize) != 1)
		nextchunk = push_to_other_stack(stackgiver, stackreceiver, chunksize);
	if (isstacksort(stackgiver, chunksize - (nextchunk.a + nextchunk.b)) != 1)
		double_pi_quicksort(stackgiver, stackreceiver, chunksize - (nextchunk.a + nextchunk.b));
	/*if (isstacksort(stackgiver, chunksize -(nextchunk.a + nextchunk.b)) != 1)
	{
		printf("!!error, chunk of size %u not sorted after first half of quicksrt!\n", chunksize -(nextchunk.a + nextchunk.b));
		ft_printstacks(stackgiver, stackreceiver);
		exit(0);
	}*/
	//get lowerchunks back in full
	lower_med_quicksort(stackgiver, stackreceiver, nextchunk);
	//printf("top %u int of stack %c are supposed to be sorted\n", chunksize, stackgiver->name);
	//ft_printstacks(stackgiver, stackreceiver);
}
