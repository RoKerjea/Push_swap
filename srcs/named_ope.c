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

void	named_ope_push(t_data *stackgiver, t_data *stackreceiver)
{
	if (stackgiver->len > 0)
	{
		waitpush(stackgiver, stackreceiver, stackreceiver->name);
		ope_push(stackgiver, stackreceiver);
	}
}

void	named_ope_swap(t_data *stackgiver, t_data *stackreceiver)
{
	if (stackgiver->len > 1)
	{
		waitpush(stackgiver, stackreceiver, 'x');
		ope_swap(stackgiver);
		if (stackgiver->name == 'a')
			write (1, "sa\n", 3);
		else
			write (1, "sb\n", 3);
	}
}

void	named_ope_rotate(t_data *stackgiver, t_data *stackreceiver)
{
	if (stackgiver->len > 1)
	{
		waitpush(stackgiver, stackreceiver, 'x');
		ope_rotate(stackgiver);
		if (stackgiver->name == 'a')
			write(1, "ra\n", 3);
		else
			write(1, "rb\n", 3);
	}
}

void	named_ope_revrotate(t_data *stackgiver, t_data *stackreceiver)
{
	if (stackgiver->len > 1)
	{
		waitpush(stackgiver, stackreceiver, 'x');
		ope_revrotate(stackgiver);
		if (stackgiver->name == 'a')
			write(1, "rra\n", 4);
		else
			write(1, "rrb\n", 4);
	}
}
