#include "../include/push_swap.h"

void	checker(t_data *stacka, t_data *stackb, char **)
{

	if (isstacksort(stacka) == 1 && stackb->len == 0)
		write(1, 'OK\n', 3);
	else
		write(1, 'KO\n', 3);
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
	if (issort(stacka.first, stacka.len) != 1)
		checker(&stacka, &stackb);
	freestack(&stacka);
	return (0);
}
