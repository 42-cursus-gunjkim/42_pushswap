/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_switch_push.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunjkim <gunjkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:55:59 by gunjkim           #+#    #+#             */
/*   Updated: 2023/02/27 11:48:53 by gunjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/rule.h"

void	ft_switch(t_cdlst *cdlst)
{
	int	tmp;

	tmp = cdlst->lst->element;
	cdlst->lst->element = cdlst->lst->next->element;
	cdlst->lst->next->element = tmp;
	ft_printf("s%s\n", cdlst->name);
}

void	ft_switch_both(t_cdlst *a, t_cdlst *b)
{
	ft_switch(a);
	ft_switch(b);
	ft_printf("ss\n");
}

void	ft_push(t_cdlst *in, t_cdlst *out)
{
	t_node	*tmp;

	if (out->lst == NULL)
		return ;
	tmp = ft_cdlst_get_front(out);
	ft_cdlst_add_front(in, tmp);
	ft_printf("p%s\n", in->name);
}
