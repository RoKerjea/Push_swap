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
	t_honte	pardon;

	pardon.size = size;
	pardon.count.a = 0;
	pardon.count.b = 0;
	pardon.media = findmedianofchunk(stkgiv->first, size, 0.4);
	pardon.quart = findmedianofchunk(stkgiv->first, size, 0.65);
	while (biggerintinstack(pardon.media, stkgiv, pardon.size) && pardon.size--)
	{
		if (stkgiv->first->num < pardon.media && stkgiv->len > 1)
			push_to_a_keep(stkgiv, stkget, &pardon, nextchunk);
		else if (stkgiv->first->num >= pardon.media
			&& ++nextchunk->b && stkgiv->len > 0)
			push_to_a_push(stkgiv, stkget, &pardon, nextchunk);
	}
	return (pardon.count);
}

t_median	push_to_b(t_data *stkgiv, t_data *stkget,
unsigned int size, t_median *nextchunk)
{
	t_honte	pardon;

	pardon.size = size;
	pardon.count.a = 0;
	pardon.count.b = 0;
	pardon.media = findmedianofchunk(stkgiv->first, size, 0.4);
	pardon.quart = findmedianofchunk(stkgiv->first, size, 0.25);
	while (smallerintinstack(pardon.media, stkgiv, pardon.size)
		&& pardon.size--)
	{
		if (stkgiv->first->num > pardon.media && stkgiv->len > 1)
			push_to_b_keep(stkgiv, stkget, &pardon, nextchunk);
		if (stkgiv->first->num <= pardon.media && ++nextchunk->b)
			push_to_b_push(stkgiv, stkget, &pardon, nextchunk);
	}
	return (pardon.count);
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
