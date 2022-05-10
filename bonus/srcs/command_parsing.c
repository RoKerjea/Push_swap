/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_parsing.c                                  :+:      :+:    :+:   */
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

int	checkrcommands(char *command)
{
	if (command[0] == 'r')
	{
		if (command[1] != 'a' && command[1] != 'b' && command[1] != 'r')
			return (0);
		if (command[1] == 'r' && command[2] != '\0')
		{
			if (command[2] != 'a' && command[2] != 'r' && command[2] != 'b')
				return (0);
			if (command[3] != '\0')
				return (0);
		}
	}
	return (1);
}

int	checkcommands(char **commands)
{
	unsigned int	i;

	i = 0;
	while (commands[i])
	{
		if (commands[i][0] == 'p'
			&& (commands[i][1] != 'a' && commands[i][1] != 'b'))
			return (0);
		else if (commands[i][0] == 'p' && commands[i][2] != '\0')
			return (0);
		else if (commands[i][0] == 's' && (commands[i][1] != 'a'
			&& commands[i][1] != 'b' && commands[i][1] != 's'))
			return (0);
		else if (commands[i][0] == 's' && commands[i][2] != '\0')
			return (0);
		else if (commands[i][0] == 'r')
		{
			if (checkrcommands(commands[i]) == 0)
				return (0);
		}
		i++;
	}
	return (1);
}

char	**readcommands(void)
{
	char	**res;
	char	*commandline;

	commandline = readmap(0);
	if (!commandline)
		return (NULL);
	res = ft_split(commandline, '\n');
	free (commandline);
	if (!res)
		return (NULL);
	if (checkcommands(res) == 0)
	{
		write (2, "Error\n", 6);
		ft_freetab (res);
		return (NULL);
	}
	return (res);
}
