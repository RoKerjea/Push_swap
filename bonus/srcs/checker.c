#include "../include/checker.h"

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
		tmp = ft_strjoin(mapline, buffer);
		if (ft_strlen(mapline) > 1)
			free(mapline);
		if (!tmp)
		{
			free (buffer);
			free (mapline);
			return (NULL);
		}
		mapline = ft_strdup(tmp);
		free(tmp);
	}
	free (buffer);
	return (mapline);
}

int		checkcommands(char **commands)
{
	unsigned int	i;
	int res;

	i = 1;
	res = 1;
	while (commands[i])
	{
		if (commands[i][0] == 'p')
		{
			if (commands[i][1] != 'a' && commands[i][1] != 'b')
				res = 0;
			if (commands[i][2] != '\0')
				res = 0;
		}
		if (commands[i][0] == 's')
		{
			if (commands[i][1] != 'a' && commands[i][1] != 's' && commands[i][1] != 'b')
				res = 0;
			if (commands[i][2] != '\0')
				res = 0;
		}
		if (commands[i][0] == 'r')
		{
			if (commands[i][1] != 'a' && commands[i][1] != 'r' && commands[i][1] != 'b')
				res = 0;
			if (commands[i][1] == 'r' && commands[i][2] != '\0')
			{
				if (commands[i][2] != 'a' && commands[i][2] != 'r' && commands[i][2] != 'b')
					res = 0;
				if (commands[i][3] != '\0')
					res = 0;
			}
		}
		i++;
	}
	return (res);
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
	if (!checkcommands(res))
	{
		write (2, "Error\n", 6);
		ft_freetab (res);
		return (NULL);
	}
	return (res);
}

void	execcommands(t_data *stacka, t_data *stackb, char **commands)
{
	unsigned int	i;

	i = 0;
	while (commands[i])
	{
		if (commands[i][0] == 'p')
		{
			if (commands[i][1] == 'a')
				ope_push(stackb, stacka);
			else
				ope_push(stacka, stackb);
		}
		if (commands[i][0] == 's')
		{
			if (commands[i][1] == 'a' || commands[i][1] == 's')
				ope_swap(stacka);
			if (commands[i][1] == 'b' || commands[i][1] == 's')
				ope_swap(stackb);
		}
		if (commands[i][0] == 'r')
		{
			if (commands[i][1] == 'a' || (commands[i][1] == 'r' && commands[i][2] == '\0'))
				ope_rotate(stacka);
			if (commands[i][1] == 'b' || (commands[i][1] == 'r' && commands[i][2] == '\0'))
				ope_rotate(stackb);
			if (commands[i][1] == 'r' && commands[i][2] != '\0')
			{
				if (commands[i][2] == 'a' || commands[i][2] == 'r')
					ope_revrotate(stacka);
				if (commands[i][2] == 'b' || commands[i][2] == 'r')
					ope_revrotate(stackb);
			}
		}
		i++;
	}
}

void	checker(t_data *stacka, t_data *stackb)
{
	char	**commands;

	commands = readcommands();
	if (!commands)
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
