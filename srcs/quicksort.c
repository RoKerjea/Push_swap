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
{/*
	printf("start of push to stack%c for chunksize = %u\n", stackreceiver->name, chunksize);
	printf("stackgiver count = %u\n", stackgiver->count);
	ft_printstacks(stackgiver, stackreceiver);*/
	int	non = 1;
	if (chunksize - stackgiver->count == 0)
		non = 0;
	int	median;
	int	lowquartian;
	int	upquartian;
	t_median	nextchunk;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	nextchunk.a = 0;
	nextchunk.b = 0;
	median = findmedianofchunk(stackgiver->first, chunksize);
	lowquartian = findquartianofchunk(stackgiver->first, chunksize);
	upquartian = findupquartianofchunk(stackgiver->first, chunksize);
	while (smallerintinstack(median, stackgiver) && chunksize && stackgiver->name == 'a')
	{
		if (stackgiver->first->num > median && stackgiver->count > 1)
		{
			named_ope_rotate(stackgiver);
			i++;
		}
		chunksize--;
		if (stackgiver->first->num <= median)
		{
			if (stackgiver->first->num > lowquartian)
			{
				j++;
				nextchunk.a++;
				named_ope_push(stackgiver, stackreceiver);
				if (stackreceiver->count > 1)
				{
					if (stackgiver->first->num > median && stackgiver->count > 1 && chunksize)
					{
						ope_rr(stackgiver, stackreceiver);
						i++;
						chunksize--;
					}
					else
						named_ope_rotate(stackreceiver);
				}
			}
			else if (stackgiver->first->num <= lowquartian)
			{
				nextchunk.b++;
				named_ope_push(stackgiver, stackreceiver);
			}
		}
	}
	//printf("median = %d, upquart = %d\n", median, upquartian);
	while (biggerintinstack(median, stackgiver) && chunksize && stackgiver->name == 'b')
	{
		if (stackgiver->first->num < median && stackgiver->count > 1)
		{
			named_ope_rotate(stackgiver);
			i++;
		}
		chunksize--;
		if (stackgiver->first->num >= median)
		{
			if (stackgiver->first->num <= upquartian)
			{
				j++;
				nextchunk.a++;
				named_ope_push(stackgiver, stackreceiver);
				if (stackreceiver->count > 1)
				{
					if (stackgiver->first->num <= median)
					{
						ope_rr(stackgiver, stackreceiver);
						i++;
						chunksize--;
					}
					else
						named_ope_rotate(stackreceiver);
				}
			}
			else if (stackgiver->first->num > upquartian)
			{
				nextchunk.b++;
				named_ope_push(stackgiver, stackreceiver);
			}
		}
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
	while (j && stackreceiver->count > 1)
	{
		named_ope_revrotate(stackreceiver);
		j--;
	}
	return (nextchunk);
}

void	lower_med_quicksort(t_data *stackgiver, t_data *stackreceiver, t_median	nextchunk)
{
	if (isstacksort(stackreceiver, nextchunk.a) != 1)
		double_pi_quicksort(stackreceiver, stackgiver, nextchunk.a);
	while (nextchunk.a--)
		named_ope_push(stackreceiver, stackgiver);
	if (isstacksort(stackreceiver, nextchunk.b) != 1)
		double_pi_quicksort(stackreceiver, stackgiver, nextchunk.b);
	while (nextchunk.b--)
		named_ope_push(stackreceiver, stackgiver);
}
/*
void	pushswappush(t_data *stackgiver, t_data *stackreceiver)
{
	named_ope_push(stackgiver, stackreceiver);
	named_ope_swap(stackgiver);
	named_ope_push(stackreceiver, stackgiver);
}*/

void	chunk_of_threea(t_data *stackgiver, t_data *stackreceiver)
{
	int	a;
	int	b;
	int	c;

	a = stackgiver->first->num;
	b = stackgiver->first->next->num;
	c = stackgiver->first->next->next->num;
	if (a > b && b < c && a < c)
		named_ope_swap(stackgiver);
	else if (a > b && b > c && a > c)
	{
		named_ope_swap(stackgiver);
		named_ope_push(stackgiver, stackreceiver);
		named_ope_swap(stackgiver);
		named_ope_push(stackreceiver, stackgiver);
		named_ope_swap(stackgiver);
	}
	else if (a > b && b < c && a > c)
	{
		named_ope_swap(stackgiver);
		named_ope_push(stackgiver, stackreceiver);
		named_ope_swap(stackgiver);
		named_ope_push(stackreceiver, stackgiver);
	}
	else if (a < b && b > c && a < c)
	{
		named_ope_push(stackgiver, stackreceiver);
		named_ope_swap(stackgiver);
		named_ope_push(stackreceiver, stackgiver);
	}
	else if (a < b && b > c && a > c)
	{
		named_ope_push(stackgiver, stackreceiver);
		named_ope_swap(stackgiver);
		named_ope_push(stackreceiver, stackgiver);
		named_ope_swap(stackgiver);
	}
}

void	chunk_of_threeb(t_data *stackgiver, t_data *stackreceiver)
{
	int	a;
	int	b;
	int	c;

	a = stackgiver->first->num;
	b = stackgiver->first->next->num;
	c = stackgiver->first->next->next->num;
	if (a > b && b < c && a < c)
	{
		named_ope_push(stackgiver, stackreceiver);
		named_ope_swap(stackgiver);
		named_ope_push(stackreceiver, stackgiver);
		named_ope_swap(stackgiver);
	}
	else if (a < b && b < c && a < c)
	{
		named_ope_swap(stackgiver);
		named_ope_push(stackgiver, stackreceiver);
		named_ope_swap(stackgiver);
		named_ope_push(stackreceiver, stackgiver);
		named_ope_swap(stackgiver);
	}
	else if (a > b && b < c && a > c)
	{
		named_ope_push(stackgiver, stackreceiver);
		named_ope_swap(stackgiver);
		named_ope_push(stackreceiver, stackgiver);
	}
	else if (a < b && b > c && a < c)
	{
		named_ope_swap(stackgiver);
		named_ope_push(stackgiver, stackreceiver);
		named_ope_swap(stackgiver);
		named_ope_push(stackreceiver, stackgiver);
	}
	else if (a < b && b > c && a > c)
		named_ope_swap(stackgiver);
}

void	double_pi_quicksort(t_data *stackgiver, t_data *stackreceiver, unsigned int chunksize)
{
	t_median	nextchunk;

	nextchunk.a = 0;
	nextchunk.b = 0;
	if (chunksize == 1 || chunksize == 0)
		return ;
	if (chunksize == 2)
		named_ope_swap(stackgiver);
	if (chunksize == 3 && stackgiver->name == 'a' && isstacksort(stackgiver, chunksize) != 1)
		chunk_of_threea(stackgiver, stackreceiver);
	if (chunksize == 3 && stackgiver->name == 'b' && isstacksort(stackgiver, chunksize) != 1)
		chunk_of_threeb(stackgiver, stackreceiver);
	if (chunksize > 3 && isstacksort(stackgiver, chunksize) != 1)
	{
		nextchunk = push_to_other_stack(stackgiver, stackreceiver, chunksize);
	}
	if (isstacksort(stackgiver, chunksize - (nextchunk.a + nextchunk.b)) != 1)
		double_pi_quicksort(stackgiver, stackreceiver, chunksize - (nextchunk.a + nextchunk.b));
	lower_med_quicksort(stackgiver, stackreceiver, nextchunk);
}
