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
	int non;
	if (chunksize - stackgiver->count == 0)
		non = 0;
	else
		non = 1;
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
	while (smallerintinstack(median, stackgiver) && chunksize)
	{
		if (stackgiver->first->num > median)
		{
			named_ope_rotate(stackgiver);//prob here!!
			i++;
			//ft_printstacks(stackgiver, stackreceiver);
		}
		if (stackgiver->first->num <= median)
		{
			if (stackgiver->first->num <= lowquartian)//inferior quart to top of other stack
			{
				nextchunk.b++;
				named_ope_push(stackgiver, stackreceiver);
				if (stackreceiver->name == 'a' && stackreceiver->first != stackreceiver->last)
				{
					j++;
					named_ope_rotate(stackreceiver);
				}
				//ft_printstacks(stackgiver, stackreceiver);			
			}
			else if (stackgiver->first->num > lowquartian)//superior quart to bottom of other stack
			{
				nextchunk.a++;
				named_ope_push(stackgiver, stackreceiver);
				if (stackreceiver->first != stackreceiver->last && stackreceiver->name == 'b')
				{
					j++;
					named_ope_rotate(stackreceiver);
				}
				//ft_printstacks(stackgiver, stackreceiver);
			}
		}
		chunksize--;
	}
	if (non)//should be only if rest of chunk different from stack->count, to avoid loss of time in first
	{
		while (i--)
			named_ope_revrotate(stackgiver);
	}
	while (j--)
	{
		named_ope_revrotate(stackreceiver);//get sup quart to top of stack, to keep sorted
	}
	if (nextchunk.a + nextchunk.b == 2 && isstacksort(stackreceiver, 2) != 1)
		named_ope_swap(stackreceiver);
	//printf ("end of push med quart, chunk a = %d, b = %d\n", nextchunk.a, nextchunk.b);
	return (nextchunk);
}

void	push_sorted_chunk(t_data *stackgiver, t_data *stackreceiver, unsigned int chunksize)
{
	///printf ("start of push sorted size = %d\n", chunksize);
	while (chunksize)
	{
		named_ope_push(stackgiver, stackreceiver);
		chunksize--;
	}
	//printf ("end of push sorted\n");
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
void	double_pi_quicksort(t_data *stackgiver, t_data *stackreceiver, unsigned int chunksize)
{
	//printf ("start of double_pi_quicksort with size of %d\n", chunksize);
	//ft_printstacks(stackgiver, stackreceiver);
	t_median	nextchunk;

	nextchunk.a = 0;
	nextchunk.b = 0;
	if (chunksize == 1 || chunksize == 0)
	{
		return;	
	}
	if (chunksize == 2)
	{
		if (chunksize == 2 && isstacksort(stackgiver, chunksize) != 1)
			named_ope_swap(stackgiver);
		return;
	}
	if (chunksize > 2 && isstacksort(stackgiver, chunksize) != 1)
		nextchunk = push_to_other_stack(stackgiver, stackreceiver, chunksize);
	if (isstacksort(stackgiver, chunksize -(nextchunk.a + nextchunk.b)) != 1)
	{
		//printf ("start of new quicksort with size of %d\n", chunksize -(nextchunk.a + nextchunk.b));
		double_pi_quicksort(stackgiver, stackreceiver, chunksize -(nextchunk.a + nextchunk.b));//next quicksort for rest of stack
	}
	//get lowerchunks back in full
	if (nextchunk.a > 1)
	{
		//printf("gate1\n");
		double_pi_quicksort(stackreceiver, stackgiver, nextchunk.a);//next quicksort for superior quart		
	}
	push_sorted_chunk(stackreceiver, stackgiver, nextchunk.a);
	if (nextchunk.b > 1)
	{
		//printf("gate2\n");
		double_pi_quicksort(stackreceiver, stackgiver, nextchunk.b);//next quicksort for inferior quart		
	}
	push_sorted_chunk(stackreceiver, stackgiver, nextchunk.b);
	//printf("top %u int of stack %c are supposed to be sorted\n", chunksize, stackgiver->name);
	//ft_printstacks(stackgiver, stackreceiver);
}
