#include "../include/push_swap.h"

int	checkdup(int *tabint)
{
	int	i;
	int j;

	i = 0;
	while (tabint[i])
	{
		j = i + 1;
		while (tabint[j])
		{
			if (tabint[i] == tabint[j])
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
	printf("gate join\n");
	char	*lineres;
	char	*tmp;
	int	i;

	lineres = " ";
	i = 2;
	while (i < argc - 1 && lineres)
	{
		tmp = ft_strjoin(lineres, argv[i]);
		if (ft_strlen(lineres) > 1)
			free (lineres);
		if (!tmp)
			return (NULL);
		lineres = ft_strjoin(tmp, " ");
		free (tmp);
	}
	return(lineres);
}

int	*atol_table(char **table)
{
	int *tabint;
	int i;

	while(table[i])
		i++;
	tabint = malloc(sizeof(int) * i);
	while (i > 0)
	{
		if (checkarg(table[i]) == 1)
			tabint[i] = ft_atol(table[i]);
		i--;
	}
	return (tabint);
}

int	*make_tab_from_input(int argc, char **argv)
{
	printf("gate tab main\n");
	int		*tabres;
	char	*line;
	char	**chartab;

	line = join_input(argc, argv);
	printf("gate join done\n");
	if (line == NULL)
		return (NULL);
	chartab = ft_split(line, ' ');
	free (line);
	if (chartab == NULL)
		return (NULL);
	tabres = atol_table(chartab);
	ft_freetab(chartab);
	if (checkdup(tabres) == 1)
	{
		printf("Error!duplicate found\n");
		free(tabres);
		return (NULL);
	}
	return(tabres);
}