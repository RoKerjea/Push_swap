/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_ope.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rokerjea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 17:29:13 by rokerjea          #+#    #+#             */
/*   Updated: 2022/04/12 17:29:15 by rokerjea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ope_ss(t_data *stacka, t_data *stackb)
{
	if (stacka->first != NULL && stacka->first != stacka->last)
		ope_swap(stacka);
	if (stackb->first != NULL && stackb->first != stackb->last)
		ope_swap(stackb);
	write (1, "ss\n", 3);
}

void	ope_rr(t_data *stacka, t_data *stackb)
{
	ope_rotate(stacka);
	ope_rotate(stackb);
	write (1, "rr\n", 3);
}

void	ope_rrr(t_data *stacka, t_data *stackb)
{
	ope_revrotate(stacka);
	ope_revrotate(stackb);
	write (1, "rrr\n", 4);
}
