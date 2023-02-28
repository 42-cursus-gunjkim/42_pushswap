/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunjkim <gunjkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:45:05 by gunjkim           #+#    #+#             */
/*   Updated: 2023/02/28 20:12:27 by gunjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "rule.h"

void	parse_argv(char **argv, t_cdlst *a);
void	sort_element(t_cdlst *a, t_cdlst *b);
void	partition(t_cdlst *a, t_cdlst *b);

#endif
 