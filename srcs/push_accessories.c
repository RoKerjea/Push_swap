/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_accessories.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rokerjea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 19:39:17 by rokerjea          #+#    #+#             */
/*   Updated: 2022/05/10 19:39:20 by rokerjea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	push_to_a_push(t_data *stkgiv, t_data *stkget,
t_honte *pardon, t_median *nextchunk)
{
	named_ope_push(stkgiv, stkget);
	if (stkget->first->num < pardon->quart && ++nextchunk->a)
	{
		if (biggerintinstack(pardon->media, stkgiv, pardon->size)
			&& ++pardon->count.b)
		{
			if (stkgiv->first->num < pardon->media && stkget->len > 1
				&& stkgiv->len > 1 && ++pardon->count.a)
				ope_rr(stkgiv, stkget);
			else if (stkget->len > 1)
				named_ope_rotate(stkget, stkgiv);
		}
	}
}

void	push_to_a_keep(t_data *stkgiv, t_data *stkget,
t_honte *pardon, t_median *nextchunk)
{
	if (pardon->size == 1)
	{
		if (isstacksort(stkget, 2) && (nextchunk->b - nextchunk->a) >= 2
			&& stkgiv->len > 1 && stkget->len > 1)
			ope_ss(stkget, stkgiv);
		else if (stkgiv->len > 1)
			named_ope_swap(stkgiv, stkget);
	}
	else if (stkgiv->len > 1)
	{
		pardon->count.a++;
		named_ope_rotate(stkgiv, stkget);
	}
}

void	push_to_b_push(t_data *stkgiv, t_data *stkget,
t_honte *pardon, t_median *nextchunk)
{
	named_ope_push(stkgiv, stkget);
	if (stkget->first->num >= pardon->quart && ++nextchunk->a)
	{
		if (smallerintinstack(pardon->media, stkgiv, pardon->size)
			&& ++pardon->count.b)
		{
			if (stkgiv->first->num > pardon->media && stkget->len > 1
				&& stkgiv->len > 1 && ++pardon->count.a)
				ope_rr(stkgiv, stkget);
			else if (stkget->len > 1)
				named_ope_rotate(stkget, stkgiv);
		}
	}
}

void	push_to_b_keep(t_data *stkgiv, t_data *stkget,
t_honte *pardon, t_median *nextchunk)
{
	if (pardon->size == 1)
	{
		if (isstacksort(stkget, 2) && (nextchunk->b - nextchunk->a) >= 2
			&& stkget->len > 1 && stkgiv->len > 1)
		{
			ope_ss(stkget, stkgiv);
		}
		else if (stkgiv->len > 1)
			named_ope_swap(stkgiv, stkget);
	}
	else if (stkgiv->len > 1)
	{
		named_ope_rotate(stkgiv, stkget);
		pardon->count.a++;
	}
}
