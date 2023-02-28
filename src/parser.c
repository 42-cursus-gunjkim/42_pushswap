/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunjkim <gunjkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 17:13:21 by gunjkim           #+#    #+#             */
/*   Updated: 2023/02/28 20:18:00 by gunjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../Inc/cdlst.h"
#include "../Inc/util.h"

int	arg_check(char *arg)
{
	int		tmp;
	int		flag;

	if (!is_all_digit(arg))
		return (-1);
	if (ft_strlen(arg) > 11)
		return (-1);
	if (*arg == '-')
		flag = -1;
	else
		flag = 1;
	tmp = ft_atoi(arg);
	if (flag == -1 && tmp >= 0)
		return (-1);
	if (flag == 1 && tmp < 0)
		return (-1);
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

int	is_duplicated(int *arr, int n)
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
				return (1);
			next_i++;
		}
		index++;
	}
	return (0);
}

void	parse_argv(char **argv, t_cdlst *a)
{
	int		index;
	int		*arr_index;
	t_node	*new;
	int		tmp;

	index = 1;
	arr_index = (int *)malloc(sizeof(int) * a->max_count);
	if (arr_index == NULL)
		error_exit("ERROR!");
	while (index <= a->max_count)
	{
		if (arg_check(argv[index]) == -1)
			error_exit("ERROR!");
		tmp = ft_atoi(argv[index]);
		arr_index[index - 1] = tmp;
		new = ft_cdlstnew(tmp);
		if (new == NULL)
			error_exit("ERROR!");
		ft_cdlst_add_back(a, new);
		index++;
	}
	if (is_duplicated(arr_index, a->max_count))
		error_exit("ERROR!");
	replace_v_to_i(arr_index, a, a->max_count);
	free(arr_index);
}
