/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunjkim <gunjkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 15:34:20 by gunjkim           #+#    #+#             */
/*   Updated: 2023/02/27 11:48:53 by gunjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/rule.h"

void	ft_rotate(t_cdlst *cdlst)
{
	if (cdlst->lst == NULL)
		return ;
	cdlst->lst = cdlst->lst->next;
	ft_printf("r%s\n", cdlst->name);
}

void	ft_rotate_both(t_cdlst *a, t_cdlst *b)
{
	ft_rotate(a);
	ft_rotate(b);
	ft_printf("rr\n");
}

void	ft_reverse_rotate(t_cdlst *cdlst)
{
	if (cdlst->lst == NULL)
		return ;
	cdlst->lst = cdlst->lst->prev;
	ft_printf("rr%s\n", cdlst->name);
}

void	ft_reverse_rotate_both(t_cdlst *a, t_cdlst *b)
{
	ft_reverse_rotate(a);
	ft_reverse_rotate(b);
	ft_printf("rrr\n");
}
