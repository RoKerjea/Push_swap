/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rokerjea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 17:31:24 by rokerjea          #+#    #+#             */
/*   Updated: 2022/04/19 17:31:26 by rokerjea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	checkdup(t_tabint tabint)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (i < tabint.count)
	{
		j = i + 1;
		while (j < tabint.count)
		{
			if (tabint.tab[i] == tabint.tab[j])
				return (-1);
			j++;
		}
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
		if ((str[i] >= '0' && str[i] <= '9') && str[i + 1] == '-')
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

char	*join_input(int argc, char **argv)
{
	char	*lineres;
	char	*tmp;
	int		i;

	lineres = " ";
	i = 1;
	while (i < argc && lineres)
	{
		tmp = ft_strjoin(lineres, argv[i]);
		if (ft_strlen(lineres) > 1)
			free (lineres);
		if (!tmp)
			return (NULL);
		lineres = ft_strjoin(tmp, " ");
		free (tmp);
		i++;
	}
	//printf("joined line =\'%s\'\n", lineres);
	return (lineres);
}

t_tabint	atol_table(char **table)
{
	t_tabint		tabint;
	unsigned int	i;

	tabint.count = 0;
	while (table[tabint.count])
		tabint.count++;
	tabint.tab = malloc(sizeof(int) * tabint.count);
	if (tabint.tab == NULL)
		return (tabint);
	i = 0;
	while (i < tabint.count)
	{
		if (checkarg(table[i]) == 1)
		{
			tabint.tab[i] = ft_atol(table[i]);
			//printf("int number %d is %d\n", i, tabint.tab[i]);
		}
		else
		{
			write (2, "Error\n", 6);
			ft_freetab(table);
			free(tabint.tab);
			exit (0);
		}
		i++;
	}
	//printf("end of atolconv\n");
	return (tabint);
}

t_tabint	make_tab_from_input(int argc, char **argv)
{
	t_tabint	tabres;
	char		*line;
	char		**chartab;

	tabres.tab = NULL;
	line = join_input(argc, argv);
	if (line == NULL)
		return (tabres);
	chartab = ft_split(line, ' ');
	free (line);
	if (chartab == NULL)
		return (tabres);
	tabres = atol_table(chartab);
	ft_freetab(chartab);
	if (checkdup(tabres) == -1)
	{
		write(2, "Error\n", 6);
		free(tabres.tab);
		tabres.tab = NULL;
		return (tabres);
	}
	return (tabres);
}
