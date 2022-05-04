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
	unsigned int	pivoti;
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

void	mediancycle(int *tab, t_medindex medindex, t_median *res)
{
	unsigned int	pivotindex;

	if (medindex.start <= medindex.end)
	{
		pivotindex = getpivotindexafterpart(tab, medindex.start, medindex.end);
		if (pivotindex == medindex.res)
			res->b = tab[pivotindex];
		if (pivotindex == medindex.res - 1)
			res->a = tab[pivotindex];
		if (res->b != -2147483649 && res->a != -2147483649)
			return ;
		if (pivotindex >= medindex.res)
		{
			medindex.end = pivotindex - 1;
			mediancycle(tab, medindex, res);
		}
		else
		{
			medindex.start = pivotindex + 1;
			mediancycle(tab, medindex, res);
		}
	}
	return ;
}

int	oddevenmedian(int *tab, unsigned int chunksize, float aim)
{
	t_median	res;
	t_medindex	medindex;

	medindex.start = 0;
	medindex.end = chunksize - 1;
	medindex.res = chunksize * aim;
	res.a = -2147483649;
	res.b = -2147483649;
	mediancycle(tab, medindex, &res);
	//printf("aim position = %d resa = %li, resb = %li\n", medindex.res, res.a, res.b);
	if (chunksize % 2 == 1)
		return (res.b);
	else
		return ((res.b + res.a) / 2);
}

int	findmedianofchunk(t_link *link, unsigned int chunksize, float aim)
{
	int				*tab;
	int				res;
	unsigned int	i;

	i = 0;
	tab = malloc(sizeof(int) * chunksize);
	while (i < chunksize)
	{
		tab[i] = link->num;
		link = link->next;
		i++;
	}
	res = oddevenmedian(tab, i, aim);
	free(tab);
	return (res);
}
