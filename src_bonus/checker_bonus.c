/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunjkim <gunjkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 16:40:46 by gunjkim           #+#    #+#             */
/*   Updated: 2023/03/14 16:36:42 by gunjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/checker_bonus.h"

t_cdlst	*alloc_init_cdl(char *name, int max_count)
{
	t_cdlst	*new;

	new = (t_cdlst *)malloc(sizeof(t_cdlst));
	if (new == NULL)
		error_exit();
	new->name = name;
	new->max_count = max_count;
	new->lst = NULL;
	new->count = 0;
	return (new);
}

void	exec_rule(char *rule, t_cdlst *a, t_cdlst *b)
{
	if (is_same(rule, "sa\n"))
		ft_switch(a);
	else if (is_same(rule, "sb\n"))
		ft_switch(b);
	else if (is_same(rule, "ss\n"))
		ft_switch_both(a, b);
	else if (is_same(rule, "pa\n"))
		ft_push(a, b);
	else if (is_same(rule, "pb\n"))
		ft_push(b, a);
	else if (is_same(rule, "ra\n"))
		ft_rotate(a);
	else if (is_same(rule, "rb\n"))
		ft_rotate(b);
	else if (is_same(rule, "rr\n"))
		ft_rotate_both(a, b);
	else if (is_same(rule, "rra\n"))
		ft_reverse_rotate(a);
	else if (is_same(rule, "rrb\n"))
		ft_reverse_rotate(b);
	else if (is_same(rule, "rrr\n"))
		ft_reverse_rotate_both(a, b);
	else
		error_exit();
}

int	is_sorted(t_cdlst *a, t_cdlst *b)
{
	int		index;
	t_node	*tmp;

	tmp = a->lst;
	index = 0;
	if (b->count != 0)
		return (0);
	while (index < a->max_count - 1)
	{
		if (tmp->index > tmp->next->index)
			return (0);
		index++;
		tmp = tmp->next;
	}
	if (a->count != a->max_count)
		return (0);
	return (1);
}

void	check(int num_of_element, char **element_list)
{
	char	*rule;
	t_cdlst	*a;
	t_cdlst	*b;

	a = alloc_init_cdl("a", num_of_element);
	b = alloc_init_cdl("b", num_of_element);
	parse_argv(element_list, a);
	rule = get_next_line(0);
	while (rule != NULL)
	{
		exec_rule(rule, a, b);
		free(rule);
		rule = get_next_line(0);
	}
	free(rule);
	if (is_sorted(a, b))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	clear_all(a, b);
}

int	main(int argc, char *argv[])
{
	int		num_of_element;
	char	**element_list;

	if (argc < 2)
		return (0);
	num_of_element = 0;
	if (argc == 2)
	{
		element_list = ft_split_white(argv[1]);
		if (element_list == NULL)
			error_exit();
		while (element_list[num_of_element] != NULL)
			num_of_element++;
	}
	else
	{
		num_of_element = argc - 1;
		element_list = argv + 1;
	}
	check(num_of_element, element_list);
	if (argc == 2)
		ft_double_free(element_list);
	return (0);
}
