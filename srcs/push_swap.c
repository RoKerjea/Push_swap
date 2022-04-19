/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rokerjea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 15:40:05 by rokerjea          #+#    #+#             */
/*   Updated: 2022/04/05 15:40:07 by rokerjea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
/*
int	checkdup(t_link *stacka)
{
	int		i;
	t_link	*stacknext;

	i = 0;
	while (stacka)
	{
		stacknext = stacka->next;
		while (stacknext)
		{
			if (stacka->num == stacknext->num)
				return (-1);
			stacknext = stacknext->next;
		}
		stacka = stacka->next;
		i++;
	}
	return (1);
}

int	checkarg(char *str)
{
	int		i;
	int		j;
	long	l;

	i = 0;
	j = 0;
	while (str[i])
	{
		if ((str[i] < '0' || str[i] > '9') && str[i] != '-')
			return (-1);
		if (str[i] >= '0' && str[i] <= '9')
			j++;
		if (str[i] == '-' && str[i + 1] == '-')
			return (-1);
		i++;
	}
	if (j == 0)
		return (-1);
	l = ft_atol(str);
	if (l < -2147483648 || l > 2147483647)
	{
		return (-1);
	}
	return (1);
}
*/
void	ft_printstacks(t_link *stacka, t_link *stackb)
{
	write (1, "stacks first to last\n", 21);
	while (stacka || stackb)
	{
		if (stacka)
		{
			ft_putnbr_fd(stacka->num, 1);
			stacka = stacka->next;
		}
		write (1, " | ", 3);
		if (stackb)
		{
			ft_putnbr_fd(stackb->num, 1);
			stackb = stackb->next;
		}
		write (1, "\n", 1);
	}
	write (1, "\n", 1);
}

void	ft_printstacksrev(t_link *stacka, t_link *stackb)
{
	write (1, "stacks last to first\n", 21);
	while (stacka || stackb)
	{
		if (stacka)
		{
			ft_putnbr_fd(stacka->num, 1);
			stacka = stacka->prev;
		}
		write (1, " | ", 3);
		if (stackb)
		{
			ft_putnbr_fd(stackb->num, 1);
			stackb = stackb->prev;
		}
		write (1, "\n", 1);
	}
	write (1, "\n", 1);
}

int	issort(t_link *link)
{
	int	tmp;

	tmp = link->num;
	link = link->next;
	while (link)
	{
		if (tmp > link->num)
			return (-1);
		tmp = link->num;
		link = link->next;
	}
	return(1);
}

int	issortrev(t_link *link)
{
	int	tmp;

	tmp = link->num;
	link = link->prev;
	while (link)
	{
		if (tmp > link->num)
			return (-1);
		tmp = link->num;
		link = link->prev;
	}
	return(1);
}

void	push_swap(int argc, t_data stacka, t_data stackb)
{
	ft_printstacks(stacka.first, stackb.first);
	//ft_printstacksrev(stacka.last, stackb.last);
	if (argc == 3 && issort(stacka.first) != 1)
		ope_ra(&stacka);
	if (argc == 4 && issort(stacka.first) != 1)
		algo_3(&stacka);
	if (argc > 4 && argc <= 6 && issort(stacka.first) != 1)
		algo_5(argc, &stacka, &stackb);
	if (argc > 6 && argc <= 101)
		algo_100(&stacka, &stackb);
	//ope_sa (&stacka);
	//ope_rra (&stacka);
	//ope_pb(&stacka, &stackb);
	//ope_pb(&stacka, &stackb);
	//ope_rb(&stackb);
	//ft_printstacks(stacka.first, stackb.first);
	//ft_printstacksrev(stacka.last, stackb.last);
	if (issort(stacka.first) == 1 && stackb.first == NULL)
		printf ("stack is sorted!\n");
	else 
		printf ("stack isn't sorted\n");
}

void	printtab(int *tabint)
{
	int i;

	i = 0;
	printf ("printing *int\n");
	while (tabint[i])
	{
		printf("%d\n", tabint[i]);
		i++;
	}
	exit(0);
}

int	main(int argc, char **argv)
{
	t_data	stack[2];
	int		*tabint;

	if (argc == 1)
		return (0);
	tabint = make_tab_from_input(argc, argv);
	printtab(tabint);
	stack[0] = mkstacka(argc, argv);
	stack[1].first = NULL;
	stack[1].last = NULL;
	stack[1].count = 0;
/*	if (checkdup(stack[0].first) == -1)
	{
		printf("Error!!duplicate is found!!\n");
		//free all
		return(0);
	}*/
	push_swap(argc, stack[0], stack[1]);
	//freeeverything
	return (0);
}
