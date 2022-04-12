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

void	ft_printstacks(t_link *stacka, t_link *stackb)
{
	write (1, "stacks first to last\n", 21);
	while (stacka)
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
	while (stacka)
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

int	issort(t_link *stack)
{
	int	tmp;

	tmp = stack->num;
	stack = stack->next;
	while (stack)
	{
		if (tmp > stack->num)
			return (-1);
		tmp = stack->num;
		stack = stack->next;
	}
	return(1);
}

void	push_swap(int argc, t_data stacka, t_data stackb)
{
	ft_printstacks(stacka.first, stackb.first);
	ft_printstacksrev(stacka.last, stackb.last);
	if (argc == 3 && issort(stacka.first) != 1)
		ope_ra(&stacka);
	if (argc == 4 && issort(stacka.first) != 1)
		algo_3(&stacka);
	if (argc > 4 && argc <= 6 && issort(stacka.first) != 1)
		algo_5(argc, &stacka, &stackb);
	if (argc > 6 && argc <= 101)
		algo_100(argc, &stacka, &stackb);
	//ope_sa (&stacka);
	//ope_rra (&stacka);
	//ope_pb(&stacka, &stackb);
	//ope_pa(&stacka, &stackb);
	ft_printstacks(stacka.first, stackb.first);
	ft_printstacksrev(stacka.last, stackb.last);
	if (issort(stacka.first) == 1 && stackb.first == NULL)
		printf ("stack is sorted!\n");
	else 
		printf ("stack isn't sorted\n");
}

int	main(int argc, char **argv)
{
	t_data stacka;
	t_data stackb;

	if (argc == 1)
		return (0);
	stacka = mkstacka(argc, argv);
	stackb.first = NULL;
	stackb.last = NULL;
	if (checkdup(stacka.first) == -1)
	{
		//delete stacks
		printf("!!duplicate is found!!\n");
	}
	push_swap(argc, stacka, stackb);
	return (0);
}
