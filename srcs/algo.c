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
		named_ope_swap (stacka);
	else if (a > b && b > c && a > c)
	{
		named_ope_swap (stacka);
		named_ope_revrotate (stacka);
	}
	else if (a > b && b < c && a > c)
		named_ope_rotate (stacka);
	else if (a < b && b > c && a < c)
	{
		named_ope_swap (stacka);
		named_ope_rotate (stacka);
	}
	else if (a < b && b > c && a > c)
		named_ope_revrotate (stacka);
}

void	pushlinkrightplace(t_data *stacka, t_data *stackb)
{
	if (stackb->first->num < stacka->first->num)
	{
		named_ope_push (stackb, stacka);
		return ;
	}
	if (stackb->first->num > stacka->last->num)
	{
		named_ope_push (stackb, stacka);
		named_ope_rotate(stacka);
		return ;
	}
	while (stackb->first->num > stacka->first->num)
		named_ope_rotate(stacka);
	named_ope_push (stackb, stacka);
	while (issort(stacka->first, stacka->count) != 1)
		named_ope_rotate(stacka);
}
//need a smart rotate depending of most efficient cost!
void	algo_5(t_data *stacka, t_data *stackb)
{
	if (stacka->count == 5)
		named_ope_push (stacka, stackb);
	named_ope_push (stacka, stackb);
	algo_3(stacka);
	pushlinkrightplace(stacka, stackb);
	if (stackb->first != NULL)
		pushlinkrightplace(stacka, stackb);
}

int	biggerintinstack(int median, t_data *stack)
{
	t_link	*link;

	link = stack->first;
	while (link != NULL)
	{
		if (link->num > median)
			return (1);
		link = link->next;
	}
	return (0);
}

int	smallerintinstack(int median, t_data *stack)
{
	t_link	*link;

	link = stack->first;
	while (link != NULL)
	{
		if (link->num < median)
			return (1);
		link = link->next;
	}
	return (0);
}
