/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   another_util_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunjkim <gunjkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 13:31:58 by gunjkim           #+#    #+#             */
/*   Updated: 2023/03/14 16:04:08 by gunjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/util_bonus.h"

void	clear_all(t_cdlst *a, t_cdlst *b)
{
	ft_cdlstclear(a);
	ft_cdlstclear(b);
	free(a);
	free(b);
}

static int	ft_isspace(int c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

int	ps_atoi(const char *str)
{
	int			sign;
	long long	result;

	sign = 1;
	result = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (ft_isdigit(*str))
	{
		result = result * 10 + (*str - '0');
		if (result < -2147483648 || result > 2147483647)
			error_exit();
		str++;
	}
	return (result * sign);
}
