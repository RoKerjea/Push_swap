#include "../include/push_swap.h"

void	ft_freetab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	while (i >= 0)
	{
		if (tab[i])
			free(tab[i]);
		i--;
	}
	free(tab);
}
