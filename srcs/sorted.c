/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rokerjea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 12:40:27 by rokerjea          #+#    #+#             */
/*   Updated: 2022/04/27 12:40:29 by rokerjea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	isstacksort(t_data *stack, unsigned int size)
{
	if (size == 0 || size == 1)
		return (1);
	if (stack->name == 'a')
		return (issort(stack->first, size));
	if (stack->name == 'b')
		return (issortrev(stack->first, size));
	return (-1);
}

int	issort(t_link *link, unsigned int size)
{
	int	tmp;

	tmp = link->num;
	link = link->next;
	while (--size && link)
	{
		if (tmp > link->num)
			return (-1);
		tmp = link->num;
		link = link->next;
	}
	return (1);
}

int	issortrev(t_link *link, unsigned int size)
{
	int	tmp;

	if (link == NULL)
		return (-1);
	tmp = link->num;
	link = link->next;
	while (--size && link)
	{
		if (tmp < link->num)
			return (-1);
		tmp = link->num;
		link = link->next;
	}
	return (1);
}
