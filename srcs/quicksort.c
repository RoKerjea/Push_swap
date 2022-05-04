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
	named_ope_swap(stkgiv);
	named_ope_push(stkget, stkgiv);
}

void	chunk_of_threea(t_data *stkgiv, t_data *stkget)
{
	int	a[3];

	a[0] = stkgiv->first->num;
	a[1] = stkgiv->first->next->num;
	a[2] = stkgiv->first->next->next->num;
	if (a[0] > a[1] && a[1] < a[2] && a[0] < a[2])
		named_ope_swap(stkgiv);
	else if (a[0] > a[1] && a[1] > a[2] && a[0] > a[2])
	{
		named_ope_swap(stkgiv);
		pushswappush(stkgiv, stkget);
		named_ope_swap(stkgiv);
	}
	else if (a[0] > a[1] && a[1] < a[2] && a[0] > a[2])
	{
		named_ope_swap(stkgiv);
		pushswappush(stkgiv, stkget);
	}
	else if (a[0] < a[1] && a[1] > a[2] && a[0] < a[2])
		pushswappush(stkgiv, stkget);
	else if (a[0] < a[1] && a[1] > a[2] && a[0] > a[2])
	{
		pushswappush(stkgiv, stkget);
		named_ope_swap(stkgiv);
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
		named_ope_swap(stkgiv);
	}
	else if (a[0] < a[1] && a[1] < a[2] && a[0] < a[2])
	{
		named_ope_swap(stkgiv);
		pushswappush(stkgiv, stkget);
		named_ope_swap(stkgiv);
	}
	else if (a[0] > a[1] && a[1] < a[2] && a[0] > a[2])
		pushswappush(stkgiv, stkget);
	else if (a[0] < a[1] && a[1] > a[2] && a[0] < a[2])
	{
		named_ope_swap(stkgiv);
		pushswappush(stkgiv, stkget);
	}
	else if (a[0] < a[1] && a[1] > a[2] && a[0] > a[2])
		named_ope_swap(stkgiv);
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

int med_of_four(t_link *link)
{
	long int res1;
	long int res2;
	int res3;
	int i;
	int j;
	int *tab;
	
	i = 0;
	tab = malloc(sizeof(int) * 4);
	while (i < 4)
	{
		tab[i] = link->num;
		link = link->next;
		i++;
	}
	i = 0;
//	printf("1 = %i 2 = %i 3 = %i 4 = %i\n", tab[0], tab[1], tab[2], tab[3]);
	while (i < 4)
	{
		j = i;
		while (j < 4)
		{
			if (tab[i] > tab[j])
				swap(&tab[i], &tab[j]);
			j++;
		}
		i++;
	}
//	printf("1 = %i 2 = %i 3 = %i 4 = %i\n", tab[0], tab[1], tab[2], tab[3]);
	res1 = tab[1];
	res2 = tab[2];
	res3 = (res1 + res2) / 2;
	return (res3);
}

void	chunk_of_four_to_a(t_data *stkgiv, t_data *stkget)
{
	int i;
	int j;
	int			media;

	j = 0;
	i = 4;
	media = med_of_four(stkgiv->first);
	while (biggerintinstack(media, stkgiv, i) && i--)
	{
		if (stkgiv->first->num <= media)
		{
			if (i == 1 && isstacksort(stkgiv, 2) != 1)
				named_ope_swap(stkgiv);
			else
			{
				j++;
				named_ope_rotate(stkgiv);
			}
		}
		else if (stkgiv->first->num > media)
			named_ope_push(stkgiv, stkget);
	}
	while (j--)
		named_ope_revrotate(stkgiv);
	if (isstacksort(stkgiv, 2) != 1 && isstacksort(stkget, 2) != 1)
		ope_ss(stkget, stkgiv);
	if (isstacksort(stkgiv, 2) != 1)
		named_ope_swap(stkgiv);
	if (isstacksort(stkget, 2) != 1)
		named_ope_swap(stkget);
	named_ope_push(stkget, stkgiv);
	named_ope_push(stkget, stkgiv);
}

void	chunk_of_four_to_b(t_data *stkgiv, t_data *stkget)
{
	int i;
	int j;
	int			media;

	j = 0;
	i = 4;
	media = med_of_four(stkgiv->first);
	//printf("media = %i\n", media);
	while (smallerintinstack(media, stkgiv, i) && i--)
	{
		if (stkgiv->first->num > media)
		{
			if (i == 1 && isstacksort(stkgiv, 2) != 1)
				named_ope_swap(stkgiv);
			else
			{
				j++;
				named_ope_rotate(stkgiv);
			}
		}
		else if (stkgiv->first->num <= media)
			named_ope_push(stkgiv, stkget);
	}
	while (j--)
		named_ope_revrotate(stkgiv);
	if (isstacksort(stkgiv, 2) != 1 && isstacksort(stkget, 2) != 1)
		ope_ss(stkget, stkgiv);
	if (isstacksort(stkgiv, 2) != 1)
		named_ope_swap(stkgiv);
	if (isstacksort(stkget, 2) != 1)
		named_ope_swap(stkget);
	named_ope_push(stkget, stkgiv);
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
		named_ope_swap(stkgiv);
	if (size == 3 && stkgiv->len == 3 && isstacksort(stkgiv, size) != 1)
		algo_3(stkgiv);
	if (size == 3 && stkgiv->name == 'a' && isstacksort(stkgiv, size) != 1)
		chunk_of_threea(stkgiv, stkget);
	if (size == 3 && stkgiv->name == 'b' && isstacksort(stkgiv, size) != 1)
		chunk_of_threeb(stkgiv, stkget);
	if (size == 4 && stkgiv->name == 'a' && isstacksort(stkgiv, size) != 1)
		chunk_of_four_to_b(stkgiv, stkget);
	if (size == 4 && stkgiv->name == 'b' && isstacksort(stkgiv, size) != 1)
		chunk_of_four_to_a(stkgiv, stkget);
	if (size > 4 && isstacksort(stkgiv, size) != 1)
		nextchunk = push_half(stkgiv, stkget, size);
	if (isstacksort(stkgiv, size - (nextchunk.a + nextchunk.b)) != 1)
		double_pi_quicksort(stkgiv, stkget, size - (nextchunk.a + nextchunk.b));
	lower_med_quicksort(stkgiv, stkget, nextchunk);
}
