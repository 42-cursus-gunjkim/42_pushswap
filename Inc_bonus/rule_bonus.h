/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunjkim <gunjkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:48:18 by gunjkim           #+#    #+#             */
/*   Updated: 2023/03/09 17:04:41 by gunjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RULE_BONUS_H
# define RULE_BONUS_H

# include "cdlst_bonus.h"
# include "../libft/libft.h"

void	ft_switch(t_cdlst *cdlst);
void	ft_switch_both(t_cdlst *a, t_cdlst *b);
void	ft_push(t_cdlst *in, t_cdlst *out);
void	ft_rotate(t_cdlst *cdlst);
void	ft_rotate_both(t_cdlst *a, t_cdlst *b);
void	ft_reverse_rotate(t_cdlst *cdlst);
void	ft_reverse_rotate_both(t_cdlst *a, t_cdlst *b);

#endif