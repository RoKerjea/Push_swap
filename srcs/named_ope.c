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

void	actualpush(t_data *stackgiver, t_data *stackreceiver)
{
	//printf("gatepush, waitcount = %d\n", stackgiver->waitcount);
	while (stackgiver->waitcount > 0)
	{
		//printf("gatepush, waitcount = %d\n", stackgiver->waitcount);
		if (stackgiver->waitpushto == 'a')
			write (1, "pa\n", 3);
		else
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
	/*if (stackgiver && stackreceiver && order)
	{}*/
	if (order == 'x')
	{
		actualpush(stackgiver, stackreceiver);
	}
	else if (order == stackgiver->waitpushto && (order == 'a' || order == 'b'))
	{
		stackreceiver->waitcount++;
		stackgiver->waitcount++;
	}
	else if ((order == 'a' && stackgiver->waitpushto == 'b') || (order == 'b' && stackgiver->waitpushto == 'a'))
	{
		stackreceiver->waitcount--;
		stackgiver->waitcount--;
		if (stackgiver->waitcount == 0)
		{
			stackgiver->waitpushto = 'x';
			stackreceiver->waitpushto = 'x';
		}
	}
	else if (order != 'x' && stackgiver->waitpushto == 'x')
	{
		stackgiver->waitpushto = order;
		stackreceiver->waitpushto = order;
		stackreceiver->waitcount = 1;
		stackgiver->waitcount = 1;
	}
}

void	named_ope_push(t_data *stackgiver, t_data *stackreceiver)
{
	if (stackgiver->len > 0)
	{
		waitpush(stackgiver, stackreceiver, stackreceiver->name);
		ope_push(stackgiver, stackreceiver);
		/*if (stackreceiver->name == 'a')
			write (1, "pa\n", 3);
		else
			write (1, "pb\n", 3);*/
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
