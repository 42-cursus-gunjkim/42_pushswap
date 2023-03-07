/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunjkim <gunjkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 15:18:30 by gunjkim           #+#    #+#             */
/*   Updated: 2023/03/07 12:40:04 by gunjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/push_swap.h"

void	print_cdl(t_cdlst *cdl)
{
	t_node	*cur;

	cur = cdl->lst;
	ft_printf("This is cdl : %s\n", cdl->name);
	if (cdl->lst == NULL)
	{
		ft_printf("list is empty\n");
		return ;
	}
	while (cur->next != cdl->lst)
	{
		ft_printf("value : %d, index : %d, r : %d, %d\n", cur->element, cur->index, cur->ra, cur->rb);
		cur = cur->next;
	}
	ft_printf("value : %d, index : %d, r : %d, %d\n", cur->element, cur->index, cur->ra, cur->rb);
}

void	init_cdl(t_cdlst *cdl, char *name, int max_count)
{
	cdl->name = name;
	cdl->max_count = max_count;
	cdl->lst = NULL;
	cdl->count = 0;
	cdl->part_l = 0;
	cdl->part_m = 0;
	cdl->part_s = 0;
}

void	clear_two_stack(t_cdlst *a, t_cdlst *b)
{
	ft_cdlstclear(a);
	ft_cdlstclear(b);
	free(a);
	free(b);
}

void	check_leak(void)
{
	system("leaks --list -- push_swap");
}

int	main(int argc, char *argv[])
{
	t_cdlst	*a;
	t_cdlst	*b;

	if (argc < 2)
		return (0);
	a = (t_cdlst *)malloc(sizeof(t_cdlst));
	if (a == NULL)
		error_exit("ERROR!\n");
	init_cdl(a, "a", argc - 1);
	parse_argv(argv, a);
	a->count = argc - 1;
	b = (t_cdlst *)malloc(sizeof(t_cdlst));
	if (b == NULL)
		error_exit("ERROR!\n");
	init_cdl(b, "b", argc -1);
	partition(a, b);
	sort_element(a, b);
	clear_two_stack(a, b);
	return (0); 
}
