/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rokerjea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 19:27:42 by rokerjea          #+#    #+#             */
/*   Updated: 2022/04/22 19:27:44 by rokerjea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	getpivotindexafterpart(int *tab, unsigned int starti, unsigned int endi)
	{
	int				pivoti;
	int				n;
	int				lst;
	unsigned int	i;
	unsigned int	j;

	n = endi - starti + 1;
	pivoti = n / 2;
	swap(&tab[starti + pivoti], &tab[endi]);
	lst = tab[endi];
	i = starti;
	j = starti;
	while (j < endi)
	{
		if (tab[j] < lst)
		{
			swap(&tab[i], &tab[j]);
			i++;
		}
		j++;
	}
	swap(&tab[i], &tab[endi]);
	return (i);
}

void	mediancycle(int *tab, int startindex, int endindex, int midindex, t_median *res)
{
	int	pivotindex;

	if (startindex <= endindex)
	{
		pivotindex = getpivotindexafterpart(tab, startindex, endindex);
		if (pivotindex == midindex)
		{
			res->b = tab[pivotindex];
			if (res->a != -1)
				return ;
		}
		if (pivotindex == midindex - 1)
		{
			res->a = tab[pivotindex];
			if (res->b != -1)
				return ;
		}
		if (pivotindex >= midindex)
			mediancycle(tab, startindex, pivotindex - 1, midindex, res);
		else
			mediancycle(tab, pivotindex + 1, endindex, midindex, res);
	}
	return ;
}

int	oddevenmedian(int *tab, unsigned int chunksize)
{
	t_median	res;

	res.a = -1;
	res.b = -1;
	mediancycle(tab, 0, chunksize - 1, chunksize / 2, &res);
	if (chunksize % 2 == 1)
		return (res.b);
	else
		return ((res.b + res.a) / 2);
}


int	findmedianofchunk(t_link *link, unsigned int chunksize)
{
	int				*tab;
	int				res;
	unsigned int	i;

	i = 0;
	tab = malloc(sizeof(int) * chunksize);
	while (i < chunksize)
	{
		tab[i] = link->num;
		//printf ("int index %u is %d\n", i, tab[i]);
		link = link->next;
		i++;
	}
	res = oddevenmedian(tab, i);
	free(tab);
	return (res);
}
