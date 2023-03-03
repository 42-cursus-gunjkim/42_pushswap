/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunjkim <gunjkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 15:34:20 by gunjkim           #+#    #+#             */
/*   Updated: 2023/03/03 14:16:58 by gunjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/rule.h"

void	ft_rotate(t_cdlst *cdlst, int flag)
{
	if (cdlst->lst == NULL)
		return ;
	cdlst->lst = cdlst->lst->next;
	if (flag == 1)
		ft_printf("r%s\n", cdlst->name);
}

void	ft_rotate_both(t_cdlst *a, t_cdlst *b)
{
	ft_rotate(a, 0);
	ft_rotate(b, 0);
	ft_printf("rr\n");
}

void	ft_reverse_rotate(t_cdlst *cdlst, int flag)
{
	if (cdlst->lst == NULL)
		return ;
	cdlst->lst = cdlst->lst->prev;
	if (flag == 1)
		ft_printf("rr%s\n", cdlst->name);
}

void	ft_reverse_rotate_both(t_cdlst *a, t_cdlst *b)
{
	ft_reverse_rotate(a, 0);
	ft_reverse_rotate(b, 0);
	ft_printf("rrr\n");
}
