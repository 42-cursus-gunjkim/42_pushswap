/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunjkim <gunjkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 11:27:38 by gunjkim           #+#    #+#             */
/*   Updated: 2023/03/14 19:38:42 by gunjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rule.h"
#include "../include/util.h"

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

void	big_three(t_cdlst *a, t_cdlst *b)
{
	int	tmp;
	int	max;

	max = a->max_count - 1;
	while (a->count != 3)
	{
		tmp = a->lst->index;
		if (tmp == max || tmp == max - 1 || tmp == max - 2)
			ft_rotate(a, PRINT);
		else
			ft_push(b, a);
	}
}

void	partition(t_cdlst *a, t_cdlst *b)
{
	int		pivot;
	int		count;
	int		big;

	big = a->max_count - 1;
	pivot = (int)(a->max_count / 3);
	count = 0;
	while (count < a->max_count && a->count > 3)
	{
		if (a->lst->index == big || a->lst->index == big - 1 \
		|| a->lst->index == big - 2)
			ft_rotate(a, PRINT);
		else if (a->lst->index < pivot)
		{
			ft_push(b, a);
			ft_rotate(b, PRINT);
		}
		else if (a->lst->index < (pivot * 2) && a->lst->index >= pivot)
			ft_push(b, a);
		else
			ft_rotate(a, PRINT);
		count++;
	}
	if (a->count > 3)
		big_three(a, b);
}
