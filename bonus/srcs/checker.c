/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rokerjea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 18:48:51 by rokerjea          #+#    #+#             */
/*   Updated: 2022/05/08 18:48:53 by rokerjea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

void	execrcommand(t_data *stacka, t_data *stackb, char *command)
{
	if (command[1] == 'a' || (command[1] == 'r' && command[2] == '\0'))
		ope_rotate(stacka);
	if (command[1] == 'b' || (command[1] == 'r' && command[2] == '\0'))
		ope_rotate(stackb);
	if (command[1] == 'r' && command[2] != '\0')
	{
		if (command[2] == 'a' || command[2] == 'r')
			ope_revrotate(stacka);
		if (command[2] == 'b' || command[2] == 'r')
			ope_revrotate(stackb);
	}
}

void	execcommands(t_data *stacka, t_data *stackb, char **commands)
{
	unsigned int	i;

	i = 0;
	while (commands[i])
	{
		if (commands[i][0] == 'p' && commands[i][1] == 'a')
			ope_push(stackb, stacka);
		else if (commands[i][0] == 'p' && commands[i][1] == 'b')
			ope_push(stacka, stackb);
		if (commands[i][0] == 's'
			&& (commands[i][1] == 'a' || commands[i][1] == 's'))
			ope_swap(stacka);
		if (commands[i][0] == 's'
			&& (commands[i][1] == 'b' || commands[i][1] == 's'))
			ope_swap(stackb);
		if (commands[i][0] == 'r')
			execrcommand(stacka, stackb, commands[i]);
		i++;
	}
}

void	checker(t_data *stacka, t_data *stackb)
{
	char	**commands;

	commands = readcommands();
	if (commands == NULL)
		return ;
	execcommands(stacka, stackb, commands);
	ft_freetab(commands);
	if (isstacksort(stacka, stacka->len) == 1 && stackb->len == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

void	freestack(t_data *stacka)
{
	t_link	*link;
	t_link	*nextlink;

	link = stacka->first;
	nextlink = link->next;
	while (link)
	{
		free (link);
		link = nextlink;
		if (nextlink)
			nextlink = link->next;
		stacka->len--;
	}
	stacka->first = NULL;
	stacka->last = NULL;
}

int	main(int argc, char **argv)
{
	t_data		stacka;
	t_data		stackb;
	t_tabint	tabint;

	if (argc == 1)
		return (0);
	tabint = make_tab_from_input(argc, argv);
	if (tabint.tab == NULL)
		return (0);
	stacka = mkstacka(tabint);
	free(tabint.tab);
	if (stacka.name == 'c')
	{
		if (stacka.first)
			freestack(&stacka);
		return (0);
	}
	stackb = mkdata();
	checker(&stacka, &stackb);
	freestack(&stacka);
	if (stackb.len > 0)
		freestack(&stackb);
	return (0);
}
