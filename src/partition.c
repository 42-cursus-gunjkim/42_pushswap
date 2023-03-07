/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partition.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunjkim <gunjkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 11:27:38 by gunjkim           #+#    #+#             */
/*   Updated: 2023/03/07 12:36:36 by gunjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/rule.h"
#include "../Inc/util.h"

void	smallest(t_cdlst *a, t_cdlst *b)
{
	(b->part_s)++;
	ft_push(b, a);
	ft_rotate(b, PRINT);
}

void	medium(t_cdlst *a, t_cdlst *b)
{
	ft_push(b, a);
	(b->part_m)++;
}

void	biggest(t_cdlst *a, t_cdlst *b)
{
	while (a->lst->next != a->lst)
	{
		if (a->lst->index == a->max_count - 1)
			ft_rotate(a, PRINT);
		else
		{
			ft_push(b, a);
			(b->part_l)++;
		}
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
			smallest(a, b);
		else if (a->lst->index < (pivot * 2) && a->lst->index > pivot)
			medium(a, b);
		else
			ft_rotate(a, PRINT);
		count++;
	}
	biggest(a, b);
}
