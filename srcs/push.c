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
		if (link->num >= median)
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
		if (link->num <= median)
			return (1);
		link = link->next;
	}
	return (0);
}

t_median	push_to_a(t_data *stkgiv, t_data *stkget,
unsigned int size, t_median *nextchunk)
{
	int			media;
	int			upquart;
	t_median	count;

	count.a = 0;
	count.b = 0;
	media = findmedianofchunk(stkgiv->first, size, 0.5);
	upquart = findmedianofchunk(stkgiv->first, size, 0.75);
	while (biggerintinstack(media, stkgiv, size) && size--)
	{
		if (stkgiv->first->num < media && stkgiv->len > 1)
		{
			if (size == 1)
			{
				if (isstacksort(stkget, 2) && (nextchunk->b - nextchunk->a) >= 2)
					ope_ss(stkget, stkgiv);
				else
					named_ope_swap(stkgiv, stkget);
			}
			else
			{
				count.a++;			
				named_ope_rotate(stkgiv, stkget);
			}
		}
		else if (stkgiv->first->num >= media && ++nextchunk->b)
		{
			named_ope_push(stkgiv, stkget);
			if (stkget->first->num < upquart && ++nextchunk->a)
			{
				if (biggerintinstack(media, stkgiv, size) && ++count.b)
				{
					if (stkgiv->first->num < media && stkget->len > 1 && ++count.a)
						ope_rr(stkgiv, stkget);
					else
						named_ope_rotate(stkget, stkgiv);
				}
			}
		}
	}
	return (count);
}

t_median	push_to_b(t_data *stkgiv, t_data *stkget,
unsigned int size, t_median *nextchunk)
{
	int			media;
	int			lquart;
	t_median	count;

	count.a = 0;
	count.b = 0;
	media = findmedianofchunk(stkgiv->first, size, 0.4);
	lquart = findmedianofchunk(stkgiv->first, size, 0.25);
	while (smallerintinstack(media, stkgiv, size) && size--)
	{
		if (stkgiv->first->num > media && stkgiv->len > 1)
		{
			if (size == 1)
			{
				if (isstacksort(stkget, 2) && (nextchunk->b - nextchunk->a) >= 2)
				{
					ope_ss(stkget, stkgiv);
				}
				else
					named_ope_swap(stkgiv, stkget);
			}
			else
			{
				named_ope_rotate(stkgiv, stkget);
				count.a++;
			}
		}
		if (stkgiv->first->num <= media && ++nextchunk->b)
		{
			named_ope_push(stkgiv, stkget);
			if (stkget->first->num >= lquart && ++nextchunk->a)
			{
				if (smallerintinstack(media, stkgiv, size) && ++count.b)
				{
					if (stkgiv->first->num > media && stkget->len > 1 && ++count.a)
						ope_rr(stkgiv, stkget);
					else if (stkget->len > 1)
						named_ope_rotate(stkget, stkgiv);
				}
			}
		}
	}
	return (count);
}

t_median	push_half(t_data *stkgiv, t_data *stkget, unsigned int size)
{
	int			non;
	t_median	nextchunk;
	t_median	count;

	nextchunk.a = 0;
	nextchunk.b = 0;
	non = 1;
	if (size - stkgiv->len == 0)
		non = 0;
	if (stkgiv->name == 'a')
		count = push_to_b(stkgiv, stkget, size, &nextchunk);
	else
		count = push_to_a(stkgiv, stkget, size, &nextchunk);
	nextchunk.b -= nextchunk.a;
	while (count.a && count.b && non && stkgiv->len > 1 && stkget->len > 1)
	{
		count.a--;
		count.b--;
		ope_rrr(stkgiv, stkget);
	}
	while (non && count.a-- && stkgiv->len > 1)
		named_ope_revrotate(stkgiv, stkget);
	while (count.b-- && stkget->len > 1)
		named_ope_revrotate(stkget, stkgiv);
	return (nextchunk);
}
