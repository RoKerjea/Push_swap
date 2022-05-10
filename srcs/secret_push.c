/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   secret_push.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rokerjea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:40:56 by rokerjea          #+#    #+#             */
/*   Updated: 2022/05/10 17:40:58 by rokerjea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	actualpush(t_data *stackgiver, t_data *stackreceiver)
{
	while (stackgiver->waitcount > 0)
	{
		if (stackgiver->waitpushto == 'a')
			write (1, "pa\n", 3);
		else if (stackgiver->waitpushto == 'b')
			write (1, "pb\n", 3);
		stackreceiver->waitcount--;
		stackgiver->waitcount--;
	}
	stackgiver->waitpushto = 'x';
	stackreceiver->waitpushto = 'x';
	stackgiver->waitcount = 0;
	stackreceiver->waitcount = 0;
}

void	waitpush(t_data *stackgiver, t_data *stackreceiver, char order)
{
	if (order == 'x' && stackgiver->waitcount != 0)
		actualpush(stackgiver, stackreceiver);
	if (order == stackgiver->waitpushto && (order == 'a' || order == 'b'))
	{
		stackreceiver->waitcount++;
		stackgiver->waitcount++;
	}
	if (stackgiver->waitpushto == 'x' && (order == 'a' || order == 'b'))
	{
		stackgiver->waitpushto = order;
		stackreceiver->waitpushto = order;
		stackreceiver->waitcount = 1;
		stackgiver->waitcount = 1;
	}
	if (order != stackgiver->waitpushto && stackgiver->waitcount > 0
		&& (order == 'a' || order == 'b'))
	{
		stackreceiver->waitcount--;
		stackgiver->waitcount--;
		if (stackgiver->waitcount <= 0)
		{
			stackgiver->waitpushto = 'x';
			stackreceiver->waitpushto = 'x';
		}
	}
}
