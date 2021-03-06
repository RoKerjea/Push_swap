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

void	pushswappush(t_data *stkgiv, t_data *stkget)
{
	named_ope_push(stkgiv, stkget);
	named_ope_swap(stkgiv, stkget);
	named_ope_push(stkget, stkgiv);
}

void	chunk_of_threea(t_data *stkgiv, t_data *stkget)
{
	int	a[3];

	a[0] = stkgiv->first->num;
	a[1] = stkgiv->first->next->num;
	a[2] = stkgiv->first->next->next->num;
	if (a[0] > a[1] && a[1] < a[2] && a[0] < a[2])
		named_ope_swap(stkgiv, stkget);
	else if (a[0] > a[1] && a[1] > a[2] && a[0] > a[2])
	{
		named_ope_swap(stkgiv, stkget);
		pushswappush(stkgiv, stkget);
		named_ope_swap(stkgiv, stkget);
	}
	else if (a[0] > a[1] && a[1] < a[2] && a[0] > a[2])
	{
		named_ope_swap(stkgiv, stkget);
		pushswappush(stkgiv, stkget);
	}
	else if (a[0] < a[1] && a[1] > a[2] && a[0] < a[2])
		pushswappush(stkgiv, stkget);
	else if (a[0] < a[1] && a[1] > a[2] && a[0] > a[2])
	{
		pushswappush(stkgiv, stkget);
		named_ope_swap(stkgiv, stkget);
	}
}

void	chunk_of_threeb(t_data *stkgiv, t_data *stkget)
{
	int	a[3];

	a[0] = stkgiv->first->num;
	a[1] = stkgiv->first->next->num;
	a[2] = stkgiv->first->next->next->num;
	if (a[0] > a[1] && a[1] < a[2] && a[0] < a[2])
	{
		pushswappush(stkgiv, stkget);
		named_ope_swap(stkgiv, stkget);
	}
	else if (a[0] < a[1] && a[1] < a[2] && a[0] < a[2])
	{
		named_ope_swap(stkgiv, stkget);
		pushswappush(stkgiv, stkget);
		named_ope_swap(stkgiv, stkget);
	}
	else if (a[0] > a[1] && a[1] < a[2] && a[0] > a[2])
		pushswappush(stkgiv, stkget);
	else if (a[0] < a[1] && a[1] > a[2] && a[0] < a[2])
	{
		named_ope_swap(stkgiv, stkget);
		pushswappush(stkgiv, stkget);
	}
	else if (a[0] < a[1] && a[1] > a[2] && a[0] > a[2])
		named_ope_swap(stkgiv, stkget);
}

void	lower_med_quicksort(t_data *stkgiv, t_data *stkget, t_median nextchunk)
{
	if (isstacksort(stkget, nextchunk.a) != 1)
		double_pi_quicksort(stkget, stkgiv, nextchunk.a);
	while (nextchunk.a--)
		named_ope_push(stkget, stkgiv);
	if (isstacksort(stkget, nextchunk.b) != 1)
		double_pi_quicksort(stkget, stkgiv, nextchunk.b);
	while (nextchunk.b--)
		named_ope_push(stkget, stkgiv);
}

void	double_pi_quicksort(t_data *stkgiv, t_data *stkget, unsigned int size)
{
	t_median	nextchunk;

	nextchunk.a = 0;
	nextchunk.b = 0;
	if (size == 1 || size == 0)
		return ;
	if (size == 2)
	{
		if (isstacksort(stkget, 2) != 1)
			ope_ss(stkget, stkgiv);
		else
			named_ope_swap(stkgiv, stkget);
	}
	if (size == 3 && stkgiv->len == 3 && isstacksort(stkgiv, size) != 1)
		algo_3(stkgiv, stkget);
	if (size == 3 && stkgiv->name == 'a' && isstacksort(stkgiv, size) != 1)
		chunk_of_threea(stkgiv, stkget);
	if (size == 3 && stkgiv->name == 'b' && isstacksort(stkgiv, size) != 1)
		chunk_of_threeb(stkgiv, stkget);
	if (size > 3 && isstacksort(stkgiv, size) != 1)
		nextchunk = push_half(stkgiv, stkget, size);
	if (isstacksort(stkgiv, size - (nextchunk.a + nextchunk.b)) != 1)
		double_pi_quicksort(stkgiv, stkget, size - (nextchunk.a + nextchunk.b));
	if ((nextchunk.a + nextchunk.b) > 0)
		lower_med_quicksort(stkgiv, stkget, nextchunk);
}
