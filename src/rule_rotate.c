/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunjkim <gunjkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 15:34:20 by gunjkim           #+#    #+#             */
/*   Updated: 2023/03/14 16:04:11 by gunjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rule.h"

void	ft_rotate(t_cdlst *cdlst, int flag)
{
	if (cdlst->lst == NULL)
		return ;
	cdlst->lst = cdlst->lst->next;
	if (flag == PRINT)
		ft_printf("r%s\n", cdlst->name);
}

void	ft_rotate_both(t_cdlst *a, t_cdlst *b)
{
	ft_rotate(a, NO_PRINT);
	ft_rotate(b, NO_PRINT);
	ft_printf("rr\n");
}

void	ft_reverse_rotate(t_cdlst *cdlst, int flag)
{
	if (cdlst->lst == NULL)
		return ;
	cdlst->lst = cdlst->lst->prev;
	if (flag == PRINT)
		ft_printf("rr%s\n", cdlst->name);
}

void	ft_reverse_rotate_both(t_cdlst *a, t_cdlst *b)
{
	ft_reverse_rotate(a, NO_PRINT);
	ft_reverse_rotate(b, NO_PRINT);
	ft_printf("rrr\n");
}
