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

int	checkdup(t_stack stacka)
{
	int		i;
	t_stack	stacknext;

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

void	ft_printstacks(t_stack *stacka, t_stack *stackb)
{
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
}
/*
int	issort(t_stack stack)
{
	int	tmp;

	tmp = stack->num;
	while (stack)
	{
		if (tmp > stack->num)
			return (-1);
		tmp = stack->num;
		stack = stack->next;
	}
	return(1);
}
*/
void	push_swap(t_data stacka)
{
	ft_printstacks(stacka.first);
}

int	main(int argc, char **argv)
{
	t_data stacka;
	t_data stackb;

	if (argc == 1)
		return (0);
	stacka = mkstacka(argc, argv);
	stackb = mkdata();
	if (checkdup(stacka.first) == -1)
	{
		//problem;
		printf("dup found\n");
	}
	push_swap(stacka);
	return (0);
}
