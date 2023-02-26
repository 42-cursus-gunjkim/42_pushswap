/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunjkim <gunjkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 15:18:30 by gunjkim           #+#    #+#             */
/*   Updated: 2023/02/26 18:04:38 by gunjkim          ###   ########.fr       */
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
		ft_printf("%d \n", cur->element);
		cur = cur->next;
	}
	ft_printf("%d \n", cur->element);
}

void	check_leak(void)
{
	system("leaks --list -- push_swap");
}

int	main(int argc, char *argv[])
{
	t_cdlst	*a;
	//t_cdlst	*b;

	if (argc < 2)
		return (0);
	a = (t_cdlst *)malloc(sizeof(t_cdlst));
	parse_argv(argc, argv, a);
	print_cdl(a);
	ft_rotate(a);
	print_cdl(a);
	ft_reverse_rotate(a);
	print_cdl(a);
	ft_switch(a);
	print_cdl(a);
	ft_switch(a);
	print_cdl(a);
	ft_cdlstclear(a);
	free(a);
	//b = (t_cdlst *)malloc(sizeof(t_cdlst));
	//sort_element(a, b);
	//lst free
	atexit(check_leak);
	return (0);
}
