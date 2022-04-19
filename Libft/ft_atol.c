/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rokerjea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 17:09:35 by rokerjea          #+#    #+#             */
/*   Updated: 2022/04/19 17:09:39 by rokerjea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long	ft_atol(const char *str)
{
	long	res;
	int		i;
	int		min;

	i = 0;
	min = 0;
	res = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\r' || str[i] == '\f')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			min = 1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10;
		res += str[i] - '0';
		i++;
	}
	if (min == 1)
		res *= -1;
	return (res);
}
/*
#include <stdio.h>

int	main(int argc, char **argv)
{
	long	i;

	i = ft_atol(argv[1]);
	if (i < -2147483648 || i > 2147483647)
	{
		printf("Error");
		return (0);
	}
	int j = i;
	printf("%d", j);
	return (0);
}*/
