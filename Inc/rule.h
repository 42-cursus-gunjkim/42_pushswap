/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunjkim <gunjkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:48:18 by gunjkim           #+#    #+#             */
/*   Updated: 2023/03/07 11:26:16 by gunjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RULE_H
# define RULE_H

# include "cdlst.h"
# include "../libft/libft.h"

# define PRINT 1
# define NO_PRINT 0

void	ft_switch(t_cdlst *cdlst);
void	ft_switch_both(t_cdlst *a, t_cdlst *b);
void	ft_push(t_cdlst *in, t_cdlst *out);
void	ft_rotate(t_cdlst *cdlst, int flag);
void	ft_rotate_both(t_cdlst *a, t_cdlst *b);
void	ft_reverse_rotate(t_cdlst *cdlst, int flag);
void	ft_reverse_rotate_both(t_cdlst *a, t_cdlst *b);

#endif