/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunjkim <gunjkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 17:44:27 by gunjkim           #+#    #+#             */
/*   Updated: 2023/03/03 14:16:59 by gunjkim          ###   ########.fr       */
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

void	partition(t_cdlst *a, t_cdlst *b)
{
	int		pivot;
	int		count;

	pivot = (int)(a->max_count / 3);
	count = 0;
	while (count < a->max_count)
	{
		if (a->lst->index <= pivot)
		{
			(b->part_s)++;
			ft_push(b, a);
			ft_rotate(b, 1);
		}
		else if (a->lst->index < (pivot * 2) && a->lst->index > pivot)
		{
			ft_push(b, a);
			(b->part_m)++;
		}
		else
			ft_rotate(a, 1);
		count++;
	}
	while (a->lst->next != a->lst)
	{
		if (a->lst->index == a->max_count - 1)
			ft_rotate(a, 1);
		else
			ft_push(b, a);
	}
	b->part_l = b->max_count - b->part_m - b->part_s;
	a->count = 1;
	b->count = b->max_count - 1;
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
	t_node	*min_node;
	int		rb_c;
	int		ra_c;
	int		zero_count;
	int		i;
	int		j;
	t_node	*tmp;

	i = 0;
	j = 0;
	zero_count = 0;
	partition(a, b);
	while (b->lst != NULL)
	{
		rb_c = 0;
		ra_c = 0;
		cal_greedy(a, b);
		min_node = get_min_node(b);
		if (rb_c * ra_c > 0)
		{
			while (j < ft_min(ft_abs(min_node->ra), ft_abs(min_node->rb)))
			{
				if (min_node->ra < 0)
					ft_reverse_rotate_both(a, b);
				else
					ft_rotate_both(a, b);
				rb_c++;
				ra_c++;
			}
		}
		while (rb_c < abs(min_node->rb))
		{
			if (min_node->rb < 0)
				ft_reverse_rotate(b, 1);
			else
				ft_rotate(b, 1);
			rb_c++;
		}
		while (ra_c < abs(min_node->ra))
		{
			if (min_node->ra < 0)
				ft_reverse_rotate(a, 1);
			else
				ft_rotate(a, 1);
			ra_c++;
		}
		ft_push(a, b);
		(a->count)++;
		(b->count)--;
	}
	tmp = a->lst;
	while (tmp->index != 0)
	{
		tmp = tmp->next;
		zero_count++;
	}
	if (zero_count > a->max_count / 2)
		zero_count = a->max_count - zero_count;
	while (i < zero_count)
	{
		i++;
		ft_rotate(a, 1);
	}
}
