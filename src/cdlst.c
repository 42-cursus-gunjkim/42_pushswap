/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cdlst.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunjkim <gunjkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 13:14:01 by gunjkim           #+#    #+#             */
/*   Updated: 2023/02/22 16:09:02 by gunjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/cdlst.h"

t_node	*ft_cdlst_get_front(t_cdlst *cdl)
{
	t_node	*head;

	if (cdl->lst == NULL)
		return (NULL);
	head = cdl->lst;
	if (head -> next == head)
		cdl->lst = NULL;
	else
	{
		head->prev->next = head->next;
		head->next->prev = head->prev;
		cdl->lst = head->next;
	}
	return (head);
}

t_node	*ft_cdlstnew(int e)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node -> element = e;
	new_node -> next = NULL;
	new_node -> prev = NULL;
	return (new_node);
}

void	ft_lstclear(t_cdlst *cdl)
{
	t_node	*cur;
	t_node	*tmp;

	if (cdl->lst == NULL)
		return ;
	else
	{
		cur = cdl->lst->next;
		while (cur != cdl->lst)
		{
			tmp = cur->next;
			free(cur);
			cur = tmp;
		}
		free(cdl->lst);
	}
	cdl->lst = NULL;
}

void	ft_cdlst_add_back(t_cdlst *cdl, t_node *new_node)
{
	t_node	*cur;

	if (cdl->lst == NULL)
	{
		cdl->lst = new_node;
		new_node->next = new_node;
		new_node->prev = new_node;
	}
	else if (cdl->lst != NULL)
	{
		cur = cdl->lst;
		while (cur->next != cdl->lst)
			cur = cur->next;
		cur->next = new_node;
		new_node->next = cdl->lst;
		cdl->lst->prev = new_node;
		new_node->prev = cur;
	}
}

void	ft_cdlst_add_front(t_cdlst *cdl, t_node *new_node)
{
	t_node	*cur;

	if (cdl->lst == NULL)
	{
		cdl->lst = new_node;
		new_node->next = new_node;
		new_node->prev = new_node;
	}
	else if (cdl->lst != NULL)
	{
		cur = cdl->lst;
		new_node->next = cur;
		new_node->prev = cur->prev;
		cur->prev->next = new_node;
		cur->prev = new_node;
		cdl->lst = new_node;
	}
}
