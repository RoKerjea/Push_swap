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

void	sorttab3(int *tab)
{
	int temp;
	int i;

	while (tab[0] > tab[1] || tab[0] > tab[2] || tab[1] > tab[2])
	{
		i = 0;
		while (i <= 2)
		{
			if (tab[i] > tab[i + 1] && i < 2)
			{
				temp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = temp;
			}
			i++;
		}
	}
	printf("int in tab of 3 after sort are : %d %d %d\n", tab[0], tab[1], tab[2]);
}

int	find_median_of_3(t_link *link, int chunksize)
{
	int	*tab;
	int	i;

	i = 0;
	tab = malloc(sizeof(int) * 3);
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
	sorttab3(tab);
	//printf("int in tab of 3 are : %d %d %d\n", tab[0], tab[1], tab[2]);
	i = tab[1];
	free(tab);
	return (i);
}

int biggerintinstack(int median,  t_data *stack)
{
	t_link	*link;

	link = stack->first;
	while (link != NULL)
	{
		if (link->num > median)
			return(1);
		link = link->next;
	}
	return(0);
}

int smallerintinstack(int median,  t_data *stack)
{
	t_link	*link;

	link = stack->first;
	while (link != NULL)
	{
		if (link->num < median)
			return(1);
		link = link->next;
	}
	return(0);
}

void	push_smaller_mediana(t_data *stackgiver, t_data *stackreceiver, int chunksize)
{
	printf("gate media\n");
	int median;

	median = find_median_of_3(stackgiver->first, chunksize);
	printf("mediana of actual chunk is :%d\n", median);

	ft_printstacks(stackgiver->first, stackreceiver->first);
	while (smallerintinstack(median, stackgiver))
	{
		if (stackgiver->first->num < median)
			ope_pb(stackgiver, stackreceiver);
		else if (stackgiver->last->num < median)
			ope_rra(stackgiver);
		else
			ope_ra(stackgiver);
		chunksize--;
	}
	printf("gate end of media\n");
}

void	push_bigger_medianb(t_data *stackgiver, t_data *stackreceiver, int chunksize)
{
	printf("gate medib\n");
	int median;

	median = find_median_of_3(stackgiver->first, chunksize);
	printf("medianb of actual chunk is :%d\n", median);
	while (biggerintinstack(median, stackgiver))
	{
		if (stackgiver->first->num > median)
			ope_pa(stackreceiver, stackgiver);
		else if (stackgiver->last->num > median)
			ope_rrb(stackgiver);
		else
			ope_rb(stackgiver);
		chunksize--;
	}
	printf("gate end of medib\n");
}

void	quicksort(t_data *stacka, t_data *stackb)
{
	int chunksize;

	chunksize = stacka->count / 2;
	printf("stackacount = %d\n", stacka->count);
	if (issort(stacka->first) != 1)
		push_smaller_mediana(stacka, stackb, stacka->count);
	if (stacka->count > 3 && issort(stacka->first) != 1)
		quicksort(stacka, stackb);
	else if (stacka->count == 3)
		algo_3(stacka);
	else if (stacka->count == 2 && issort(stacka->first) != 1)
		ope_ra(stacka);
	ft_printstacks(stacka->first, stackb->first);
	if (issortrev(stackb->last) == 1)
		while (stackb->first)
			ope_pa(stacka, stackb);
	else if (stackb->first != NULL && stackb->count >= 3)
		push_bigger_medianb(stackb, stacka, chunksize);
	else if (stackb->count < 3 && issortrev(stackb->last) == -1)
		ope_rb(stackb);
}

void	algo_100(t_data *stacka, t_data *stackb)
{
	while (issort(stacka->first) != 1 || stackb->first != NULL)
	{
		quicksort(stacka, stackb);
		printf("One complete quicksort cycle has been done\n");
		ft_printstacks(stacka->first, stackb->first);
	}
}