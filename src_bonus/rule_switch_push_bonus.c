/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_switch_push_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunjkim <gunjkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:55:59 by gunjkim           #+#    #+#             */
/*   Updated: 2023/03/14 16:04:07 by gunjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/rule_bonus.h"

void	ft_switch(t_cdlst *cdlst)
{
	int	tmp;

	tmp = cdlst->lst->element;
	cdlst->lst->element = cdlst->lst->next->element;
	cdlst->lst->next->element = tmp;
	tmp = cdlst->lst->index;
	cdlst->lst->index = cdlst->lst->next->index;
	cdlst->lst->next->index = tmp;
}

void	ft_switch_both(t_cdlst *a, t_cdlst *b)
{
	ft_switch(a);
	ft_switch(b);
}

void	ft_push(t_cdlst *in, t_cdlst *out)
{
	t_node	*tmp;

	if (out->lst == NULL)
		return ;
	tmp = ft_cdlst_get_front(out);
	ft_cdlst_add_front(in, tmp);
	(out->count)--;
	(in->count)++;
}
