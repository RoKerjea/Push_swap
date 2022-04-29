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
	datastack.count = 0;
	datastack.name = 'b';
	return (datastack);
}

t_data	mkstacka(t_tabint tabint)
{
	unsigned int	i;
	t_data			stacka;
	t_link			*prevlink;
	t_link			*nowlink;

	stacka = mkdata();
	stacka.name = 'a';
	stacka.first = mkstacklink();//to protect!!
	prevlink = stacka.first;
	prevlink->num = tabint.tab[0];
	i = 1;
	while (i < tabint.count)
	{
		nowlink = mkstacklink();//to protect!!
		nowlink->num = tabint.tab[i];
		if (prevlink)
			forgelink(prevlink, nowlink);
		i++;
		prevlink = prevlink->next;
	}
	stacka.count = i;
	stacka.last = nowlink;
	return (stacka);
}
