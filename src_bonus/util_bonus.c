/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunjkim <gunjkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 18:28:19 by gunjkim           #+#    #+#             */
/*   Updated: 2023/03/09 17:45:27 by gunjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc_bonus/util_bonus.h"

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
		while (arr[i] < pivot && i < end)
			i++;
		while (arr[j] > pivot && j >= 0)
			j--;
		if (i < j)
			ft_swap(&arr[j], &arr[i]);
		else
		{
			ft_swap(&arr[j], &arr[start]);
			break ;
		}
	}
	quick_sort(arr, start, j - 1);
	quick_sort(arr, j + 1, end);
}

int	is_same(char *input, char *rule)
{
	int	input_len;
	int	rule_len;

	input_len = ft_strlen(input);
	rule_len = ft_strlen(rule);
	if (!ft_strncmp(input, rule, input_len) && (input_len == rule_len))
		return (1);
	else
		return (0);
}
