/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mklst.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rokerjea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 17:29:32 by rokerjea          #+#    #+#             */
/*   Updated: 2022/04/12 17:29:34 by rokerjea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	forgelink(t_link *prev, t_link *now)
{
	prev->next = now;
	now->prev = prev;
}

t_link	*mkstacklink(void)
{
	t_link	*link;

	link = malloc(sizeof(t_link));
	if (!link)
		return (NULL);
	link->next = NULL;
	link->prev = NULL;
	return (link);
}

t_data	mkdata(void)
{
	t_data	datastack;

	datastack.first = NULL;
	datastack.last = NULL;
	datastack.len = 0;
	datastack.name = 'b';
	return (datastack);
}

void	fill_stacka(t_data *stacka, t_tabint tabint)
{
	t_link			*nowlink;
	t_link			*prevlink;

	prevlink = stacka->first;
	prevlink->num = tabint.tab[0];
	stacka->len = 1;
	while (stacka->len < tabint.count)
	{
		nowlink = mkstacklink();
		if (nowlink == NULL)
		{
			stacka->name = 'c';
			return ;
		}
		nowlink->num = tabint.tab[stacka->len];
		if (prevlink)
			forgelink(prevlink, nowlink);
		stacka->len++;
		prevlink = prevlink->next;
	}
	stacka->last = nowlink;
}

t_data	mkstacka(t_tabint tabint)
{
	t_data			stacka;

	stacka = mkdata();
	stacka.name = 'a';
	stacka.first = mkstacklink();
	if (stacka.first == NULL)
	{
		stacka.name = 'c';
		return (stacka);
	}
	fill_stacka(&stacka, tabint);
	return (stacka);
}
