/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunjkim <gunjkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 15:18:30 by gunjkim           #+#    #+#             */
/*   Updated: 2023/03/02 19:28:53 by gunjkim          ###   ########.fr       */
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
	a->name = "a";
	a->max_count = argc - 1;
	a->lst = NULL;
	a->part_l = 0;
	a->part_m = 0;
	a->part_s = 0;
	parse_argv(argv, a);
	b = (t_cdlst *)malloc(sizeof(t_cdlst));
	b->name = "b";
	b->max_count = argc - 1;
	b->lst = NULL;
	b->part_l = 0;
	b->part_m = 0;
	b->part_s = 0;
	sort_element(a, b);
	print_cdl(b);
	print_cdl(a);
	ft_cdlstclear(a);
	ft_cdlstclear(b);
	free(a);
	free(b);
	//atexit(check_leak);
	return (0);
}
