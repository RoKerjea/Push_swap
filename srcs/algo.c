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
	printf ("were are inside algo 5 before taking last link from stackb\n");
	ft_printstacks(stacka->first, stackb->first);
	ft_printstacksrev(stacka->last, stackb->last);
	if (stackb->first != NULL)
		pushlinkrightplace(stacka, stackb);
}