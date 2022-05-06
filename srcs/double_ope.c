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

void	ope_ss(t_data *stackgiver, t_data *stackreceiver)
{
	if (stackreceiver->len > 1 && stackgiver->len > 1)
	{
		waitpush(stackgiver, stackreceiver, 'x');
		if (stackgiver->len > 1)
			ope_swap(stackgiver);
		if (stackreceiver->len > 1)
			ope_swap(stackreceiver);
		write (1, "ss\n", 3);
	}
}

void	ope_rr(t_data *stackgiver, t_data *stackreceiver)
{
	if (stackreceiver->len > 1 && stackgiver->len > 1)
	{
		waitpush(stackgiver, stackreceiver, 'x');
		ope_rotate(stackgiver);
		ope_rotate(stackreceiver);
		write (1, "rr\n", 3);
	}
}

void	ope_rrr(t_data *stackgiver, t_data *stackreceiver)
{
	if (stackreceiver->len > 1 && stackgiver->len > 1)
	{
		waitpush(stackgiver, stackreceiver, 'x');
		ope_revrotate(stackgiver);
		ope_revrotate(stackreceiver);
		write (1, "rrr\n", 4);
	}
}
