/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cdlst.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunjkim <gunjkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 13:15:13 by gunjkim           #+#    #+#             */
/*   Updated: 2023/03/03 14:17:03 by gunjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CDLST_H
# define CDLST_H

# include <stdlib.h>

typedef struct s_node
{
	int				element;
	int				index;
	int				ra;
	int				rb;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_cdlst
{
	t_node	*lst;
	char	*name;
	int		max_count;
	int		count;
	int		part_s;
	int		part_m;
	int		part_l;
}	t_cdlst;

t_node	*ft_cdlstnew(int e);
void	ft_cdlstclear(t_cdlst *cdl);
void	ft_cdlst_add_back(t_cdlst *cdl, t_node *new_node);
void	ft_cdlst_add_front(t_cdlst *cdl, t_node *new_node);
t_node	*ft_cdlst_get_front(t_cdlst *cdl);

#endif