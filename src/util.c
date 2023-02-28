/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunjkim <gunjkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 18:28:19 by gunjkim           #+#    #+#             */
/*   Updated: 2023/02/28 20:21:30 by gunjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/util.h"

void	error_exit(char *str)
{
	ft_printf("%s\n", str);
	exit(-1);
}

int	is_all_digit(char *arg)
{
	if (*arg == '-')
		arg++;
	while (*arg)
	{
		if (!ft_isdigit(*arg))
			return (0);
		arg++;
	}
	return (1);
}

void	quick_sort(int *arr, int start, int end)
{
	int	pivot;
	int	i;
	int	j;

	if (start >= end)
		return ;
	i = start + 1;
	j = end;
	pivot = arr[start];
	while (i <= j)
	{
		while (arr[i] < pivot)
			i++;
		while (arr[j] > pivot)
			j--;
		if (i < j)
			ft_swap(&arr[j], &arr[i]);
		else
			ft_swap(&arr[j], &arr[start]);
	}
	quick_sort(arr, start, j - 1);
	quick_sort(arr, j + 1, end);
}
