/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunjkim <gunjkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 18:37:37 by gunjkim           #+#    #+#             */
/*   Updated: 2023/03/14 15:18:30 by gunjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_BONUS_H
# define UTIL_BONUS_H

# include "cdlst_bonus.h"
# include "stdlib.h"
# include "../libft/libft.h"

void	error_exit(void);
int		is_all_digit(char *arg);
void	quick_sort(int *arr, int start, int end);
int		is_same(char *input, char *rule);
int		ps_atoi(const char *str);
void	clear_all(t_cdlst *a, t_cdlst *b);

#endif
