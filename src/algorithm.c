/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunjkim <gunjkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 17:44:27 by gunjkim           #+#    #+#             */
/*   Updated: 2023/02/28 20:19:14 by gunjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/rule.h"

void	partition(t_cdlst *a, t_cdlst *b)
{
	int		f_pivot;
	int		s_pivot;
	int		count;

	f_pivot = (int)(a->max_count / 3);
	s_pivot = f_pivot * 2;
	count = 0;
	while (count < a->max_count)
	{
		if (a->lst->index <= f_pivot)
		{
			ft_push(b, a);
			ft_rotate(b);
		}
		else if (a->lst->index < s_pivot && a->lst->index > f_pivot)
			ft_push(b, a);
		else
			ft_rotate(a);
		count++;
	}
	while (a->lst != NULL)
		ft_push(b, a);
}
// 그리디 이용해서 작성하기
// 정렬알고리즘 부분만 이제 작성하면 됨
// void	sort_element(t_cdlst *a, t_cdlst *b, int argc)
// {
// 	int	*index_arr;

// 	index_arr = (int *)malloc(sizeof(argc - 1));
	
// }
