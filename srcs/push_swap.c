/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rokerjea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 15:40:05 by rokerjea          #+#    #+#             */
/*   Updated: 2022/04/05 15:40:07 by rokerjea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	push_swap(t_data *stacka, t_data *stackb)
{
	//ft_printstacks(stacka->first, stackb->first);
	//ft_printstacksrev(stacka.last, stackb.last);
	if (stacka->count == 2 && issort(stacka->first, 0) != 1)
		ope_ra(stacka);
	if (stacka->count == 3 && issort(stacka->first, 0) != 1)
		algo_3(stacka);
	if (stacka->count >= 4 && stacka->count <= 5 && issort(stacka->first, 0) != 1)
		algo_5(stacka, stackb);
	if (stacka->count >= 6)
		double_pi_quicksort(stacka, stackb, stacka->count);
		//algo_100(stacka, stackb);
	//ope_sa (&stacka);
	//ope_rra (&stacka);
	//ope_pb(&stacka, &stackb);
	//ope_pb(&stacka, &stackb);
	//ope_rb(&stackb);
	ft_printstacks(stacka, stackb);
	//ft_printstacksrev(stacka->last, stackb->last);
	if (issort(stacka->first, 0) == 1 && stackb->first == NULL)
		printf ("stack is sorted!\n");
	else
		printf ("stack isn't sorted\n");
}

void	freestack(t_data *stacka)
{
	t_link	*link;
	t_link	*nextlink;

	link = stacka->first;
	nextlink = link->next;
	while (stacka->count)
	{
		free (link);
		link = nextlink;
		if (nextlink)
			nextlink = link->next;
		stacka->count--;
	}
	stacka->first = NULL;
	stacka->last = NULL;
}

int	main(int argc, char **argv)
{
	t_data		stacka;
	t_data		stackb;
	t_tabint	tabint;

	if (argc == 1)
		return (0);
	tabint = make_tab_from_input(argc, argv);
	if (tabint.tab == NULL)
		return (0);
	//printtab(tabint);
	stacka = mkstacka(tabint);
	stackb = mkdata();
	push_swap(&stacka, &stackb);
	//ft_printstacks(stacka.first, stackb.first);
	freestack(&stacka);
	free(tabint.tab);
	return (0);
}
