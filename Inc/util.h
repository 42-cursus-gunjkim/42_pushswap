/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunjkim <gunjkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 18:37:37 by gunjkim           #+#    #+#             */
/*   Updated: 2023/02/28 20:09:43 by gunjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_H
# define UTIL_H

# include "cdlst.h"
# include "stdlib.h"
# include "../libft/libft.h"

void	error_exit(char *str);
int		is_all_digit(char *arg);
void	quick_sort(int *arr, int start, int end);

#endif
