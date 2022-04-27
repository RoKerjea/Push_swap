/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   named_ope1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rokerjea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 17:28:59 by rokerjea          #+#    #+#             */
/*   Updated: 2022/04/12 17:29:01 by rokerjea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	named_ope_swap(t_data *stack)
{
	if (stack->name == 'a')
	{
		if (stack->first != NULL && stack->first != stack->last)
		{
			ope_swap(stack);
			write (1, "sa\n", 3);
		}
	}
	else
	{
		if (stack->first != NULL && stack->first != stack->last)
		{
			ope_swap(stack);
			write (1, "sb\n", 3);
		}
	}
}

void	ope_sa(t_data *stacka)
{
	if (stacka->first != NULL && stacka->first != stacka->last)
	{
		ope_swap(stacka);
		write (1, "sa\n", 3);
	}
}

void	ope_sb(t_data *stackb)
{
	if (stackb->first != NULL && stackb->first != stackb->last)
	{
		ope_swap(stackb);
		write (1, "sb\n", 3);
	}
}

void	named_ope_push(t_data *stackgiver, t_data *stackreceiver)
{
	if (stackreceiver->name == 'a')
	{
		if (stackgiver->first != NULL)
		{
			ope_push(stackgiver, stackreceiver);
			write (1, "pa\n", 3);
		}
	}
	else
	{
		if (stackgiver->first != NULL)
		{
			ope_push(stackgiver, stackreceiver);
			write (1, "pb\n", 3);
		}
	}
}

void	ope_pa(t_data *stacka, t_data *stackb)
{
	if (stackb->first != NULL)
	{
		ope_push(stackb, stacka);
		write (1, "pa\n", 3);
	}
}

void	ope_pb(t_data *stacka, t_data *stackb)
{
	if (stacka->first != NULL)
	{
		ope_push(stacka, stackb);
		write (1, "pb\n", 3);
	}
}
