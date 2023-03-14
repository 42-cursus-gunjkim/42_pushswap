/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunjkim <gunjkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 17:13:21 by gunjkim           #+#    #+#             */
/*   Updated: 2023/03/14 16:04:13 by gunjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../include/cdlst.h"
#include "../include/util.h"

int	arg_check(char *arg)
{
	int		flag;

	if (!is_all_digit(arg))
		return (-1);
	if (ft_strlen(arg) > 11)
		return (-1);
	if (*arg == '-')
		flag = -1;
	else
		flag = 1;
	return (1);
}

void	replace_v_to_i(int *arr_index, t_cdlst *a, int max_count)
{
	int		index;
	t_node	*tmp;

	index = 0;
	quick_sort(arr_index, 0, max_count - 1);
	while (index < max_count)
	{
		tmp = a->lst;
		while (tmp->element != arr_index[index])
			tmp = tmp->next;
		tmp->index = index;
		index++;
	}
}

void	is_duplicated(int *arr, int n)
{
	int	tmp;
	int	index;
	int	next_i;

	index = 0;
	while (index < n)
	{
		tmp = arr[index];
		next_i = index + 1;
		while (next_i < n)
		{
			if (tmp == arr[next_i])
				error_exit();
			next_i++;
		}
		index++;
	}
}

void	is_sorted(int *arr, int n)
{
	int	flag;
	int	index;

	flag = 1;
	index = 0;
	if (n == 1 || n == 0)
		exit(0);
	while (index < n - 1)
	{
		if (arr[index] > arr[index + 1])
			flag *= 0;
		index++;
	}
	if (flag != 0)
		exit(0);
}

void	parse_argv(char **argv, t_cdlst *a)
{
	int		index;
	int		*arr_index;
	t_node	*new;

	index = 0;
	arr_index = (int *)malloc(sizeof(int) * a->max_count);
	if (arr_index == NULL)
		error_exit();
	while (index < a->max_count)
	{
		if (arg_check(argv[index]) == -1)
			error_exit();
		arr_index[index] = ps_atoi(argv[index]);
		new = ft_cdlstnew(arr_index[index]);
		if (new == NULL)
			error_exit();
		ft_cdlst_add_back(a, new);
		(a->count)++;
		index++;
	}
	is_duplicated(arr_index, a->max_count);
	is_sorted(arr_index, a->max_count);
	replace_v_to_i(arr_index, a, a->max_count);
	free(arr_index);
}
