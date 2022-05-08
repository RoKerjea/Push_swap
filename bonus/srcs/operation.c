/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rokerjea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 17:28:50 by rokerjea          #+#    #+#             */
/*   Updated: 2022/04/12 17:28:52 by rokerjea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

void	ope_swap(t_data *datastack)
{
	t_link	*link1;
	t_link	*link2;
	t_link	*link3;

	link1 = datastack->first;
	link2 = link1->next;
	link3 = link2->next;
	if (link3)
		link3->prev = link1;
	link1->next = link3;
	link2->prev = NULL;
	link1->prev = link2;
	link2->next = link1;
	datastack->first = link2;
	if (datastack->len == 2)
		datastack->last = link1;
}

void	ope_rotate(t_data *datastack)
{
	t_link	*link1;
	t_link	*link2;

	link1 = datastack->first;
	link2 = datastack->last;
	datastack->first = link1->next;
	datastack->last = link1;
	datastack->first->prev = NULL;
	link1->next = NULL;
	link2->next = link1;
	link1->prev = link2;
}

void	ope_revrotate(t_data *datastack)
{
	t_link	*link1;
	t_link	*link2;

	link1 = datastack->first;
	link2 = datastack->last;
	datastack->last = link2->prev;
	datastack->last->next = NULL;
	datastack->first = link2;
	link2->prev = NULL;
	link2->next = link1;
	link1->prev = link2;
}

void	ope_push(t_data *stackgiver, t_data *stackreceiver)
{
	t_link	*link;

	link = stackgiver->first;
	if (stackgiver->last == stackgiver->first)
		stackgiver->last = NULL;
	stackgiver->first = link->next;
	if (stackgiver->first)
		stackgiver->first->prev = NULL;
	link->next = stackreceiver->first;
	if (stackreceiver->first)
		stackreceiver->first->prev = link;
	stackreceiver->first = link;
	if (!stackreceiver->last)
		stackreceiver->last = link;
	stackgiver->len--;
	stackreceiver->len++;
}
