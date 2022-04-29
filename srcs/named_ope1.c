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
/*	if (stack->count < 2)
		printf("error swap\n");*/
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
