/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunjkim <gunjkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 17:44:27 by gunjkim           #+#    #+#             */
/*   Updated: 2023/03/07 20:19:18 by gunjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/push_swap.h"

void	rotate_both_for_minnode(int *count, t_node *tmp, t_cdlst *a, t_cdlst *b)
{
	while (*count < ft_min(ft_abs(tmp->ra), ft_abs(tmp->rb)))
	{
		if (tmp->ra < 0)
			ft_reverse_rotate_both(a, b);
		else
			ft_rotate_both(a, b);
		(*count)++;
	}
}

void	rotate_stack_for_minnode(int count, t_node *tmp, t_cdlst *lst)
{
	while (count < ft_abs(tmp->ra))
	{
		if (tmp->ra < 0)
			ft_reverse_rotate(lst, PRINT);
		else
			ft_rotate(lst, PRINT);
		count++;
	}
}

void	rotate_stack_a_to_zerotop(t_cdlst *a)
{
	int		zero_loc;
	int		count;
	t_node	*tmp;

	tmp = a->lst;
	count = 0;
	zero_loc = 0;
	while (tmp->index != 0)
	{
		zero_loc++;
		tmp = tmp->next;
	}
	if (zero_loc > a->max_count / 2)
		zero_loc = -(a->max_count - zero_loc);
	while (count < ft_abs(zero_loc))
	{
		count++;
		if (zero_loc > 0)
			ft_rotate(a, PRINT);
		else
			ft_reverse_rotate(a, PRINT);
	}
}

void	sort_element(t_cdlst *a, t_cdlst *b)
{
	t_node	*tmp;
	int		ra;
	int		rb;

	while (b->lst != NULL)
	{
		ra = 0;
		rb = 0;
		cal_greedy(a, b);
		tmp = get_min_node(b);
		if (tmp->ra * tmp->rb > 0)
		{
			rotate_both_for_minnode(&ra, tmp, a, b);
			rb = ra;
		}
		rotate_stack_for_minnode(ra, tmp, a);
		rotate_stack_for_minnode(rb, tmp, b);
		ft_push(a, b);
	}
	rotate_stack_a_to_zerotop(a);
}
