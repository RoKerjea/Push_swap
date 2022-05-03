/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rokerjea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 16:19:46 by rokerjea          #+#    #+#             */
/*   Updated: 2022/05/03 16:19:50 by rokerjea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	biggerintinstack(int median, t_data *stack, unsigned int size)
{
	t_link	*link;

	link = stack->first;
	while (link != NULL && size--)
	{
		if (link->num > median)
			return (1);
		link = link->next;
	}
	return (0);
}

int	smallerintinstack(int median, t_data *stack, unsigned int size)
{
	t_link	*link;

	link = stack->first;
	while (link != NULL && size--)
	{
		if (link->num < median)
			return (1);
		link = link->next;
	}
	return (0);
}

t_median	push_to_a(t_data *stkgiv, t_data *stkget, unsigned int size, t_median *nextchunk)
{
	int			median;
	int			upquart;
	t_median	counter;

	counter.a = 0;
	counter.b = 0;
	median = findmedianofchunk(stkgiv->first, size, 0.5);
	upquart = findmedianofchunk(stkgiv->first, size, 0.75);
	while (biggerintinstack(median, stkgiv, size) && size--)
	{
		if (stkgiv->first->num < median && stkgiv->len > 1 && ++counter.a)
			named_ope_rotate(stkgiv);
		if (stkgiv->first->num >= median && ++nextchunk->b)
		{
			named_ope_push(stkgiv, stkget);
			if (stkget->first->num < upquart && ++counter.b && ++nextchunk->a)
			{
				if (stkgiv->first->num <= median && stkget->len > 1 && ++counter.a && size--)
					ope_rr(stkgiv, stkget);
				else
					named_ope_rotate(stkget);
			}			
		}
	}
	return (counter);
}

t_median	push_to_b(t_data *stkgiv, t_data *stkget, unsigned int size, t_median *nextchunk)
{
	int			median;
	int			lquart;
	t_median	counter;

	counter.a = 0;
	counter.b = 0;
	median = findmedianofchunk(stkgiv->first, size, 0.4);
	lquart = findmedianofchunk(stkgiv->first, size, 0.25);
	while (smallerintinstack(median, stkgiv, size) && size--)
	{
		if (stkgiv->first->num > median && stkgiv->len > 1 && ++counter.a)
			named_ope_rotate(stkgiv);
		if (stkgiv->first->num <= median && ++nextchunk->b)
		{
			named_ope_push(stkgiv, stkget);
			if (stkget->first->num > lquart && ++counter.b && ++nextchunk->a)
			{
				if (stkgiv->first->num > median && stkget->len > 1 && ++counter.a && size--)
					ope_rr(stkgiv, stkget);
				else if (stkget->len > 1)
					named_ope_rotate(stkget);
			}
		}
	}
	return (counter);
}

t_median	push_half(t_data *stkgiv, t_data *stkget, unsigned int size)
{
	int			non;
	t_median	nextchunk;
	t_median	counter;

	nextchunk.a = 0;
	nextchunk.b = 0;
	non = 1;
	if (size - stkgiv->len == 0)
		non = 0;
	if (stkgiv->name == 'a')
		counter = push_to_b(stkgiv, stkget, size, &nextchunk);
	else
		counter = push_to_a(stkgiv, stkget, size, &nextchunk);
	nextchunk.b -= nextchunk.a;
	while (counter.a && counter.b && non && stkgiv->len > 1 && stkget->len > 1)
	{
		counter.a--;
		counter.b--;
		ope_rrr(stkgiv, stkget);
	}
	while (non && counter.a-- && stkgiv->len > 1)
		named_ope_revrotate(stkgiv);
	while (counter.b-- && stkget->len > 1)
		named_ope_revrotate(stkget);
	return (nextchunk);
}
