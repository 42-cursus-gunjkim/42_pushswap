/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cdlst.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunjkim <gunjkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 13:14:01 by gunjkim           #+#    #+#             */
/*   Updated: 2023/03/14 16:04:13 by gunjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cdlst.h"

t_node	*ft_cdlst_get_front(t_cdlst *cdl)
{
	t_node	*ret;

	if (cdl->lst == NULL)
		return (NULL);
	ret = cdl->lst;
	if (ret -> next == ret)
		cdl->lst = NULL;
	else
	{
		ret->prev->next = ret->next;
		ret->next->prev = ret->prev;
		cdl->lst = ret->next;
	}
	return (ret);
}

t_node	*ft_cdlstnew(int e)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node -> element = e;
	new_node -> index = -1;
	new_node -> next = NULL;
	new_node -> prev = NULL;
	return (new_node);
}

void	ft_cdlstclear(t_cdlst *cdl)
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
	if (cdl->lst == NULL)
	{
		cdl->lst = new_node;
		new_node->next = new_node;
		new_node->prev = new_node;
	}
	else if (cdl->lst != NULL)
	{
		cdl->lst->prev->next = new_node;
		new_node->prev = cdl->lst->prev;
		new_node->next = cdl->lst;
		cdl->lst->prev = new_node;
	}
}

void	ft_cdlst_add_front(t_cdlst *cdl, t_node *new_node)
{
	if (cdl->lst == NULL)
	{
		cdl->lst = new_node;
		new_node->next = new_node;
		new_node->prev = new_node;
	}
	else if (cdl->lst != NULL)
	{
		cdl->lst->prev->next = new_node;
		new_node->prev = cdl->lst->prev;
		new_node->next = cdl->lst;
		cdl->lst->prev = new_node;
		cdl->lst = new_node;
	}
}
