/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunjkim <gunjkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 15:18:30 by gunjkim           #+#    #+#             */
/*   Updated: 2023/03/14 16:36:14 by gunjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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

void	clear_all(t_cdlst *a, t_cdlst *b, int argc, char **argv)
{
	ft_cdlstclear(a);
	ft_cdlstclear(b);
	free(a);
	free(b);
	if (argc == 2)
		ft_double_free(argv);
}

void	parse_sort_clear(t_cdlst *a, t_cdlst *b, int argc, char **element_list)
{
	parse_argv(element_list, a);
	partition(a, b);
	sort_element(a, b);
	clear_all(a, b, argc, element_list);
}

int	main(int argc, char *argv[])
{
	t_cdlst	*a;
	t_cdlst	*b;
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
	a = alloc_init_cdl("a", num_of_element);
	b = alloc_init_cdl("b", num_of_element);
	parse_sort_clear(a, b, argc, element_list);
	return (0);
}
