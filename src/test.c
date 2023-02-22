/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunjkim <gunjkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:05:05 by gunjkim           #+#    #+#             */
/*   Updated: 2023/02/22 16:11:46 by gunjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/cdlst.h"
#include "stdio.h"

void	print(t_cdlst *cdl)
{
	t_node	*cur;

	cur = cdl->lst;
	if (cdl->lst == NULL)
	{
		printf("list is empty\n");
		return ;
	}
	while (cur->next != cdl->lst)
	{
		printf("%d \n", cur->element);
		cur = cur->next;
	}
	printf("%d \n", cur->element);
}

void	check_leak(void)
{
	system("leaks --list -- a.out");
}

int	main(void)
{
	t_cdlst	*cdl;
	t_node	*new;

	cdl = (t_cdlst *)malloc(sizeof(cdl));
	cdl->name = 'a';
	cdl->lst = NULL;
	ft_cdlst_add_front(cdl, ft_cdlstnew(1));
	ft_cdlst_add_front(cdl, ft_cdlstnew(2));
	ft_cdlst_add_front(cdl, ft_cdlstnew(3));
	ft_cdlst_add_front(cdl, ft_cdlstnew(4));
	ft_cdlst_add_back(cdl, ft_cdlstnew(5));
	print(cdl);
	new = ft_cdlst_get_front(cdl);
	printf("%d : get\n", new->element);
	free(new);
	new = ft_cdlst_get_front(cdl);
	printf("%d : get\n", new->element);
	free(new);
	new = ft_cdlst_get_front(cdl);
	printf("%d : get\n", new->element);
	free(new);
	new = ft_cdlst_get_front(cdl);
	printf("%d : get\n", new->element);
	free(new);
	new = ft_cdlst_get_front(cdl);
	printf("%d : get\n", new->element);
	free(new);
	new = ft_cdlst_get_front(cdl);
	free(new);
	print(cdl);
	ft_lstclear(cdl);
	print(cdl);
	free(cdl);
	atexit(check_leak);
}
