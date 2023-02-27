/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunjkim <gunjkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 17:13:21 by gunjkim           #+#    #+#             */
/*   Updated: 2023/02/27 11:48:52 by gunjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../Inc/cdlst.h"

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

void	parse_argv(int argc, char **argv, t_cdlst *a)
{
	int		index;
	t_node	*new;
	int		tmp;

	index = 1;
	while (index < argc)
	{
		if (arg_check(argv[index]) == -1)
		{
			ft_cdlstclear(a);
			ft_printf("ERROR!\n");
			exit(-1);
		}
		tmp = ft_atoi(argv[index]);
		new = ft_cdlstnew(tmp);
		if (new == NULL)
		{
			ft_cdlstclear(a);
			ft_printf("node malloc fail\n");
			exit(-1);
		}
		ft_cdlst_add_back(a, new);
		index++;
	}
}
