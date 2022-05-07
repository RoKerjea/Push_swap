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
	if (stacka->len == 2)
		named_ope_rotate(stacka, stackb);
	if (stacka->len == 3)
		algo_3(stacka, stackb);
	if (stacka->len >= 4)
		double_pi_quicksort(stacka, stackb, stacka->len);
	actualpush(stacka, stackb);
/*	if (isstacksort(stacka, stacka->len) != 1 || stackb->len > 0)
		printf("ceci est un vrai probleme et pas un probleme d'affichage!\n");*/
}

void	freestack(t_data *stacka)
{
	t_link	*link;
	t_link	*nextlink;

	link = stacka->first;
	nextlink = link->next;
	while (link)
	{
		free (link);
		link = nextlink;
		if (nextlink)
			nextlink = link->next;
		stacka->len--;
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
	stacka = mkstacka(tabint);
	free(tabint.tab);
	if (stacka.name == 'c')
	{
		if (stacka.first)
			freestack(&stacka);
		return (0);
	}
	stackb = mkdata();
	if (issort(stacka.first, stacka.len) != 1)
		push_swap(&stacka, &stackb);
	freestack(&stacka);
	return (0);
}
