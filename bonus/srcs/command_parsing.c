/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope_parsing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rokerjea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:22:48 by rokerjea          #+#    #+#             */
/*   Updated: 2022/05/10 17:22:50 by rokerjea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

char	*freereturn(char *str)
{
	free(str);
	return (NULL);
}

char	*readmap(int fd)
{
	char	*mapline;
	char	*tmp;
	int		count;
	char	*buffer;

	tmp = NULL;
	mapline = "\n";
	count = 1;
	buffer = (char *)malloc(sizeof(char) * 101);
	if (!buffer)
		return (NULL);
	while (count > 0)
	{
		count = read(fd, buffer, 100);
		buffer[count] = '\0';
		tmp = ft_strjoin2(mapline, buffer);
		if (!tmp)
			return (freereturn(buffer));
		mapline = ft_strdup(tmp);
		free(tmp);
		if (!mapline)
			return (freereturn(buffer));
	}
	free (buffer);
	return (mapline);
}

int	check_r_ope(char *ope)
{
	if (ope[0] == 'r')
	{
		if (ope[1] != 'a' && ope[1] != 'b' && ope[1] != 'r')
			return (0);
		if (ope[1] != 'r' && ope[2] != '\0')
			return (0);
		if (ope[1] == 'r' && ope[2] != '\0')
		{
			if (ope[2] != 'a' && ope[2] != 'r' && ope[2] != 'b')
				return (0);
			if (ope[3] != '\0')
				return (0);
		}
	}
	return (1);
}

int	check_ope(char **ope)
{
	unsigned int	i;

	i = 0;
	while (ope[i])
	{
		if (ope[i][0] != 'p' && ope[i][0] != 's' && ope[i][0] != 'r')
			return (0);
		if (ope[i][0] == 'p'
			&& (ope[i][1] != 'a' && ope[i][1] != 'b'))
			return (0);
		else if (ope[i][0] == 'p' && ope[i][2] != '\0')
			return (0);
		else if (ope[i][0] == 's' && (ope[i][1] != 'a'
			&& ope[i][1] != 'b' && ope[i][1] != 's'))
			return (0);
		else if (ope[i][0] == 's' && ope[i][2] != '\0')
			return (0);
		else if (ope[i][0] == 'r')
			if (check_r_ope(ope[i]) == 0)
				return (0);
		i++;
	}
	return (1);
}

char	**readope(void)
{
	char	**res;
	char	*opeline;

	opeline = readmap(0);
	if (!opeline)
		return (NULL);
	if (lastchar(opeline) == 0)
	{
		free (opeline);
		write (2, "Error\n", 6);
		return (NULL);
	}
	res = ft_split(opeline, '\n');
	free (opeline);
	if (!res)
		return (NULL);
	if (check_ope(res) == 0)
	{
		write (2, "Error\n", 6);
		ft_freetab (res);
		return (NULL);
	}
	return (res);
}
