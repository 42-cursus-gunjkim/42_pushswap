/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_rotate_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunjkim <gunjkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 15:34:20 by gunjkim           #+#    #+#             */
/*   Updated: 2023/03/09 17:09:03 by gunjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc_bonus/rule_bonus.h"

void	ft_rotate(t_cdlst *cdlst)
{
	if (cdlst->lst == NULL)
		return ;
	cdlst->lst = cdlst->lst->next;
}

void	ft_rotate_both(t_cdlst *a, t_cdlst *b)
{
	ft_rotate(a);
	ft_rotate(b);
}

void	ft_reverse_rotate(t_cdlst *cdlst)
{
	if (cdlst->lst == NULL)
		return ;
	cdlst->lst = cdlst->lst->prev;
}

void	ft_reverse_rotate_both(t_cdlst *a, t_cdlst *b)
{
	ft_reverse_rotate(a);
	ft_reverse_rotate(b);
}
