/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunjkim <gunjkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 17:44:27 by gunjkim           #+#    #+#             */
/*   Updated: 2023/03/02 20:47:20 by gunjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/rule.h"

int	get_a_rotate_count(t_cdlst *a, int index)
{
	t_node	*tmp;
	int		count;

	count = 0;
	tmp = a->lst;
	if (tmp == NULL || (tmp->index > index && tmp->next == tmp))
		return (0);
	while (1)
	{
		if (tmp->index > index && tmp->prev->index < index)
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
			ft_rotate(b);
		}
		else if (a->lst->index < (pivot * 2) && a->lst->index > pivot)
		{
			ft_push(b, a);
			(b->part_m)++;
		}
		else
			ft_rotate(a);
		count++;
	}
	while (a->lst->next != a->lst)
	{
		if (a->lst->index == a->max_count - 1)
			ft_rotate(a);
		else
			ft_push(b, a);
	}
	b->part_l = b->max_count - b->part_m - b->part_s;
	a->count = 0;
	b->count = b->max_count;
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

	partition(a, b);
	while (b->lst != NULL)
	{
		rb_c = 0;
		ra_c = 0;
		cal_greedy(a, b);
		min_node = get_min_node(b);
		while (rb_c < abs(min_node->rb))
		{
			if (min_node->rb < 0)
				ft_reverse_rotate(b);
			else
				ft_rotate(b);
			rb_c++;
		}
		while (ra_c < abs(min_node->ra))
		{
			if (min_node->ra < 0)
				ft_reverse_rotate(a);
			else
				ft_rotate(a);
			ra_c++;
		}
		ft_push(a, b);
		(b->count)--;
	}
	while (a->lst->index != 0)
		ft_rotate(a);
}
