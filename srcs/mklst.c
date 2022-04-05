#include "../include/push_swap.h"

void	forgelink(t_stack *prev, t_stack *now)
{
	prev->next = now;
	now->prev = prev;
}

t_stack	*mkstacklink(void)
{
	t_stack *stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->next = NULL;
	stack->prev = NULL;
	return (stack);
}

t_data mkdata(void)
{
	t_data datastack;

	//datastack = malloc(sizeof(t_data));
	/*if (!datastack)
		return (NULL);*/
	datastack.first = mkstacklink();
	datastack.last = NULL;
	return (datastack);
}

t_data	mkstacka(int argc, char **argv)
{
	int	i;
	t_data	stacka;
	t_stack	*prevlink;
	t_stack	*nowlink;

	stacka = mkdata();
	prevlink = stacka.first;
	if (checkarg(argv[1]) == 1)
	prevlink->num =  ft_atol(argv[1]);
	/*else
		return (NULL);*/
	i = 2;
	while (i < argc)
	{
		nowlink = mkstacklink();
		/*if (!nowlink)
			return (NULL);*/
		if (checkarg(argv[i]) == 1)
			nowlink->num = ft_atol(argv[i]);
		/*else
			return (NULL);*/
		if (prevlink)
			forgelink(prevlink, nowlink);
		i++;
		prevlink = prevlink->next;
	}
	stacka.last = nowlink;
	return (stacka);
}