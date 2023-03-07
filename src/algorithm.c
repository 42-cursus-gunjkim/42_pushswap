/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunjkim <gunjkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 17:44:27 by gunjkim           #+#    #+#             */
/*   Updated: 2023/03/07 13:03:10 by gunjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/rule.h"
#include "../Inc/util.h"

int	get_a_rotate_count(t_cdlst *a, int index)
{
	t_node	*tmp;
	int		count;

	count = 0;
	tmp = a->lst;
	if (tmp == NULL)
		return (0);
	while (1)
	{
		if (tmp->index > index && tmp->prev->index < index)
			break ;
		if (tmp->index > index && tmp->prev->index == a->max_count - 1)
			break ;
		count++;
		tmp = tmp->next;
	}
	if (count > a->count / 2)
		count = -(a->count - count);
	return (count);
}

void	cal_greedy(t_cdlst *a, t_cdlst *b)
{
	int		i;
	int		max_i;
	t_node	*tmp;

	i = 0;
	// max_i = b->part_l;
	// if (max_i == 0)
	// 	max_i = b->part_m;
	// if (max_i == 0)
	// 	max_i = b->part_l;
	tmp = b->lst;
	max_i = b->count;
	while (i < max_i)
	{
		if (i <= (b->count / 2))
			tmp->rb = i;
		else
			tmp->rb = -(b->count - i);
		tmp->ra = get_a_rotate_count(a, tmp->index);
		tmp = tmp->next;
		i++;
	}
}

t_node	*get_min_node(t_cdlst *b)
{
	t_node	*ret;
	t_node	*tmp;
	int		minimum;
	int		min_tmp;

	ret = b->lst;
	tmp = b->lst->next;
	minimum = ft_abs(ret->ra) + ft_abs(ret->rb) + 1;
	if (ret->ra * ret->rb > 0)
		minimum = minimum - ft_min(ft_abs(ret->ra), ft_abs(ret->rb));
	while (tmp != b->lst)
	{
		min_tmp = ft_abs(tmp->ra) + ft_abs(tmp->rb) + 1;
		if (tmp->ra * tmp->rb > 0)
			min_tmp = min_tmp - ft_min(ft_abs(tmp->ra), ft_abs(tmp->rb));
		if (min_tmp < minimum)
		{
			minimum = min_tmp;
			ret = tmp;
		}
		tmp = tmp->next;
	}
	return (ret);
}

void	sort_element(t_cdlst *a, t_cdlst *b)
{
	t_node	*tmp;
	int		ra;
	int		rb;
	int		zero_loc;

	zero_loc = 0;
	while (b->lst != NULL)
	{
		ra = 0;
		rb = 0;
		cal_greedy(a, b);
		tmp = get_min_node(b);
		if (tmp->ra * tmp->rb > 0)
		{
			while (ra < ft_min(ft_abs(tmp->ra), ft_abs(tmp->rb)))
			{
				if (tmp->ra < 0)
					ft_reverse_rotate_both(a, b);
				else
					ft_rotate_both(a, b);
				ra++;
			}
			rb = ra;
		}
		while (ra < ft_abs(tmp->ra))
		{
			if (tmp->ra < 0)
				ft_reverse_rotate(a, PRINT);
			else
				ft_rotate(a, PRINT);
			ra++;
		}
		ra = 0;
		while (rb < ft_abs(tmp->rb))
		{
			if (tmp->rb < 0)
				ft_reverse_rotate(b, PRINT);
			else
				ft_rotate(b, PRINT);
			rb++;
		}
		ft_push(a, b);
	}
	tmp = a->lst;
	ra = 0;
	while (tmp->index != 0)
	{
		zero_loc++;
		tmp = tmp->next;
	}
	if (zero_loc > a->max_count / 2)
		zero_loc = -(a->max_count - zero_loc);
	while (ra < ft_abs(zero_loc))
	{
		ra++;
		if (zero_loc > 0)
			ft_rotate(a, PRINT);
		else
			ft_reverse_rotate(a, PRINT);
	}
}
