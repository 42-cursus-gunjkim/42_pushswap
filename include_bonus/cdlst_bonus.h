/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cdlst_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunjkim <gunjkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 13:15:13 by gunjkim           #+#    #+#             */
/*   Updated: 2023/03/09 16:54:46 by gunjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CDLST_BONUS_H
# define CDLST_BONUS_H

# include <stdlib.h>

typedef struct s_node
{
	int				element;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_cdlst
{
	t_node	*lst;
	char	*name;
	int		max_count;
	int		count;
}	t_cdlst;

t_node	*ft_cdlstnew(int e);
void	ft_cdlstclear(t_cdlst *cdl);
void	ft_cdlst_add_back(t_cdlst *cdl, t_node *new_node);
void	ft_cdlst_add_front(t_cdlst *cdl, t_node *new_node);
t_node	*ft_cdlst_get_front(t_cdlst *cdl);

#endif