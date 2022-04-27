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
	printf ("start of push med quart with size of %d\n", chunksize);
	int median;
	int	lowquartian;
	t_median	nextchunk;

	nextchunk.a = 0;
	nextchunk.b = 0;
	median = findmedianofchunk(stackgiver->first, chunksize);
	lowquartian = findquartianofchunk(stackgiver->first, chunksize);
	while (smallerintinstack(median, stackgiver))
	{
		if (stackgiver->first->num > median)
			named_ope_rotate(stackgiver);
		if (stackgiver->first->num <= median)
		{
			if (stackgiver->first->num <= lowquartian)//inferior quart to top of other stack
			{
				nextchunk.b++;
				named_ope_push(stackgiver, stackreceiver);				
			}
			else if (stackgiver->first->num > lowquartian)//superior quart to bottom of other stack
			{
				nextchunk.a++;
				named_ope_push(stackgiver, stackreceiver);
				named_ope_rotate(stackreceiver);
			}
		}
	}
	while (stackreceiver->last->num > lowquartian)
		named_ope_revrotate(stackreceiver);//get sup quart to top of stack, to keep sort
	printf ("end of push med quart, chunk a = %d, b = %d\n", nextchunk.a, nextchunk.b);
	return (nextchunk);
}

void	push_sorted_chunk(t_data *stackgiver, t_data *stackreceiver, unsigned int chunksize)
{

	printf ("start of push sorted size = %d\n", chunksize);
	while (chunksize)
	{
		named_ope_push(stackgiver, stackreceiver);
		chunksize--;
	}
	printf ("end of push sorted\n");
}

void	double_pi_quicksort(t_data *stackgiver, t_data *stackreceiver, unsigned int chunksize)
{

	printf ("start of double_pi_quicksort with size of %d\n", chunksize);
	ft_printstacks(stackgiver, stackreceiver);
	t_median	nextchunk;

	nextchunk.a = 0;
	nextchunk.b = 0;
	if (chunksize == 0)
		chunksize = stackgiver->count;
	if (chunksize == 1)
	{
		return;
	}
	if (chunksize == 2 && isstacksort(stackgiver, chunksize) != 1)
	{
		named_ope_swap(stackgiver);
	}
	if (chunksize == 2)
	{
		return;
	}
	if (chunksize > 2 && isstacksort(stackgiver, chunksize) != 1)
		nextchunk = push_to_other_stack(stackgiver, stackreceiver, chunksize);
	if (isstacksort(stackgiver, chunksize) != 1)
	{
		printf ("start of new quicksort with size of %d\n", chunksize -(nextchunk.a + nextchunk.b));
		double_pi_quicksort(stackgiver, stackreceiver, chunksize -(nextchunk.a + nextchunk.b));//next quicksort for rest of stack
	}
	if (nextchunk.a > 1)
	{
		printf("gate1\n");
		double_pi_quicksort(stackreceiver, stackgiver, nextchunk.a);//next quicksort for superior quart
		
	}
	push_sorted_chunk(stackreceiver, stackgiver, nextchunk.a);
	if (nextchunk.b > 1)
	{
		printf("gate2\n");
		double_pi_quicksort(stackreceiver, stackgiver, nextchunk.b);//next quicksort for inferior quart
		
	}
	push_sorted_chunk(stackreceiver, stackgiver, nextchunk.b);
	printf("top %u int of stack %c are supposed to be sorted\n", chunksize, stackgiver->name);
	ft_printstacks(stackgiver, stackreceiver);
}
