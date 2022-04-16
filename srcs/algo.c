/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rokerjea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 17:28:33 by rokerjea          #+#    #+#             */
/*   Updated: 2022/04/12 17:28:38 by rokerjea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	algo_3(t_data *stacka)
{
	int	a;
	int	b;
	int	c;

	a = stacka->first->num;
	b = stacka->first->next->num;
	c = stacka->first->next->next->num;
	if (a > b && b < c && a < c)
		ope_sa (stacka);
	else if (a > b && b > c && a > c)
	{
		ope_sa (stacka);
		ope_rra (stacka);
	}
	else if (a > b && b < c && a > c)
		ope_ra (stacka);
	else if (a < b && b > c && a < c)
	{
		ope_sa (stacka);
		ope_ra (stacka);
	}
	else if (a < b && b > c && a > c)
		ope_rra (stacka);
}

void	pushlinkrightplace(t_data *stacka, t_data *stackb)
{
	while (stackb->first->num > stacka->first->num && stackb->first->num < stacka->last->num)
		ope_ra(stacka);
	ope_pa(stacka, stackb);
	if (issort(stacka->first) != 1)
		ope_ra(stacka);
}

void	algo_5(int argc, t_data *stacka, t_data *stackb)
{
	ope_pb(stacka, stackb);
	if (argc == 6)
		ope_pb(stacka, stackb);
	algo_3(stacka);
	pushlinkrightplace(stacka, stackb);
	if (stackb->first != NULL)
		pushlinkrightplace(stacka, stackb);
}

int	find_median_of_3(t_link *link, int chunksize)
{
	int	tab[3];
	int	i;

	i = 0;
	tab[0] = link->num;
	while (i < chunksize)
	{
		if (i == (chunksize - 1) / 2)
			tab[1] = link->num;
		if (i == chunksize - 1)
			tab[2] = link->num;
		link = link->next;
		i++;
	}
	sorttab3(&tab);
	return (tab[1]);
}

void	sorttab3(tab[3])
{
	int temp;

	if (tab[0] > tab[1] && tab[0] > tab[2])
	{
		temp = tab[2];
		tab[2] = tab[0];
		tab[0] = temp;
	}
	if (tab[0] > tab[1] && tab[0] < tab[2])
	{
		temp = tab[1];
		tab[1] = tab[0];
		tab[0] = temp;
	}
	if (tab[1] > tab[2])
	{
		temp = tab[2];
		tab[2] = tab[1];
		tab[1] = temp;
	}
}

void	quicksort(t_data *stacka, t_data *stackb)
{
	int chunksize;

	chunksize = stacka->count / 2;
	push_low_median(stacka, stackb, chunksize);
	if (stacka->count > 3)
		quicksort(stacka, stackb);
	else if (stacka->count == 3)
		algo_3(stacka);
	else if (stacka->count == 2 && issort(stacka) != 1)
		ope_ra(stacka);
	push_low_median(stackb, stacka, chunksize);
}

void	algo_100(int argc, t_data *stacka, t_data *stackb)
{
	int	median;

	while (issort(stacka) != 1 || stackb->first != NULL)
	{
		median = find_median_of_3(stacka->first, stacka->count);
		push_up_median(stacka, stackb, median);
	}
	/*phase 1
	find median
	push everything > median to b
	keep int sizeto move for corresponding phase 2 chunk
	recursive phase 1
	until a is sorted
	phase 2
	from last chunk added to b
	find median
	push > median to a
	from next chunk added to b
	repeat
	*/
}