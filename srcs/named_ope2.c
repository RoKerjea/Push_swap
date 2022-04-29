/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   named_ope2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rokerjea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 17:29:05 by rokerjea          #+#    #+#             */
/*   Updated: 2022/04/12 17:29:07 by rokerjea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	named_ope_rotate(t_data *stack)
{
	/*if (stack->count < 2)
		printf("error rotate\n");*/
	if (stack->name == 'a')
	{
		if (stack->first != stack->last)
		{
			ope_rotate(stack);
			write(1, "ra\n", 3);
		}
	}
	else
	{
		if (stack->first != stack->last)
		{
			ope_rotate(stack);
			write(1, "rb\n", 3);
		}
	}
}

void	named_ope_revrotate(t_data *stack)
{
	/*if (stack->count < 2)
		printf("error revrotate\n");*/
	if (stack->name == 'a')
	{
		if (stack->first != stack->last)
		{
			ope_revrotate(stack);
			write(1, "rra\n", 4);
		}
	}
	else
	{
		if (stack->first != stack->last)
		{
			ope_revrotate(stack);
			write(1, "rrb\n", 4);
		}
	}
}
