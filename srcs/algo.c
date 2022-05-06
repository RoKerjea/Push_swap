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

void	algo_3(t_data *stacka, t_data *stackb)
{
	int	a;
	int	b;
	int	c;

	a = stacka->first->num;
	b = stacka->first->next->num;
	c = stacka->first->next->next->num;
	if (a > b && b < c && a < c)
		named_ope_swap (stacka, stackb);
	else if (a > b && b > c && a > c)
	{
		named_ope_swap (stacka, stackb);
		named_ope_revrotate (stacka, stackb);
	}
	else if (a > b && b < c && a > c)
		named_ope_rotate (stacka, stackb);
	else if (a < b && b > c && a < c)
	{
		named_ope_swap (stacka, stackb);
		named_ope_rotate (stacka, stackb);
	}
	else if (a < b && b > c && a > c)
		named_ope_revrotate (stacka, stackb);
}
