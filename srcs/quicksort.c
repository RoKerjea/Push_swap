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
			if (stackgiver->first->num <= lowquartian)//inferior quart to top of stack b, bottom of a
			{
				nextchunk.b++;
				named_ope_push(stackgiver, stackreceiver);
				if (stackreceiver->name == 'a' && stackreceiver->count > 1)
				{
					j++;
					named_ope_rotate(stackreceiver);
				}
				//ft_printstacks(stackgiver, stackreceiver);			
			}
			else if (stackgiver->first->num > lowquartian)//superior quart to bottom of stack b, top of a
			{
				nextchunk.a++;
				named_ope_push(stackgiver, stackreceiver);
				if (stackreceiver->name == 'b' && stackreceiver->count > 1)
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
		//printf("reverse rotate maybe faulty\n");
		named_ope_revrotate(stackreceiver);//get sup quart to top of stack, to keep sorted
	}
	//if (nextchunk.a + nextchunk.b == 2 && isstacksort(stackreceiver, 2) != 1)
	//	named_ope_swap(stackreceiver);
	//printf ("end of push med quart, chunk a = %d, b = %d\n", nextchunk.a, nextchunk.b);
	return (nextchunk);
}

void	push_sorted_chunk(t_data *stackgiver, t_data *stackreceiver, unsigned int chunksize)
{
	///printf ("start of push sorted size = %d\n", chunksize);
	if (isstacksort(stackgiver, chunksize) != 1)
	{
		printf("!!error, chunk of size %u not sorted when pushed back!\n", chunksize);
		printf("!!should be sent from stack %c to %c\n", stackgiver->name, stackreceiver->name);
		ft_printstacks(stackgiver, stackreceiver);
		exit(0);
	}
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
void	lower_med_quicksort(t_data *stackgiver, t_data *stackreceiver, t_median	nextchunk)
{
	if (stackgiver->name == 'a')
	{
		if (nextchunk.a > 1)
		{
			double_pi_quicksort(stackreceiver, stackgiver, nextchunk.a);//next quicksort for superior quart		
		}
		push_sorted_chunk(stackreceiver, stackgiver, nextchunk.a);
		printf("end of lowermedquicsrt half, chunk = %u, pushed to %c\n", nextchunk.a, stackgiver->name);
		//ft_printstacks(stackgiver, stackreceiver);
		if (nextchunk.b > 1)
		{
			double_pi_quicksort(stackreceiver, stackgiver, nextchunk.b);//next quicksort for inferior quart		
		}
		push_sorted_chunk(stackreceiver, stackgiver, nextchunk.b);
		printf("end of lowermedquicsrt half, chunk = %u, pushed to %c\n", nextchunk.b, stackgiver->name);
		//ft_printstacks(stackgiver, stackreceiver);
	}
	if (stackgiver->name == 'b')
	{
		if (nextchunk.b > 1)
		{
			double_pi_quicksort(stackreceiver, stackgiver, nextchunk.b);//next quicksort for superior quart		
		}
		push_sorted_chunk(stackreceiver, stackgiver, nextchunk.b);
		printf("end of lowermedquicsrt half, chunk = %u, pushed to %c\n", nextchunk.b, stackgiver->name);
		//ft_printstacks(stackgiver, stackreceiver);
		if (nextchunk.a > 1)
		{
			double_pi_quicksort(stackreceiver, stackgiver, nextchunk.a);//next quicksort for inferior quart		
		}
		push_sorted_chunk(stackreceiver, stackgiver, nextchunk.a);
		printf("end of lowermedquicsrt half, chunk = %u, pushed to %c\n", nextchunk.a, stackgiver->name);
		//ft_printstacks(stackgiver, stackreceiver);
	}
	if (isstacksort(stackgiver, (nextchunk.a + nextchunk.b)) != 1)
	{
		printf("!!error, chunk of size %u not sorted after both lowermedquicsrt!\n", nextchunk.a + nextchunk.b);
		ft_printstacks(stackgiver, stackreceiver);
		exit(0);
	}
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
	if (isstacksort(stackgiver, chunksize -(nextchunk.a + nextchunk.b)) != 1)
	{
		printf("!!error, chunk of size %u not sorted after first half of quicksrt!\n", chunksize -(nextchunk.a + nextchunk.b));
		ft_printstacks(stackgiver, stackreceiver);
		exit(0);
	}
	//get lowerchunks back in full
	lower_med_quicksort(stackgiver, stackreceiver, nextchunk);
	//printf("top %u int of stack %c are supposed to be sorted\n", chunksize, stackgiver->name);
	//ft_printstacks(stackgiver, stackreceiver);
}
