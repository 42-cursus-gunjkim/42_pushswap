/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cdlst.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunjkim <gunjkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 13:15:13 by gunjkim           #+#    #+#             */
/*   Updated: 2023/02/26 15:04:07 by gunjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CDLST_H
# define CDLST_H

# include <stdlib.h>

typedef struct s_node
{
	int				element;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_cdlst
{
	t_node	*lst;
	char	*name;
}	t_cdlst;

t_node	*ft_cdlst(t_cdlst *cdl);
t_node	*ft_cdlstnew(int e);
void	ft_cdlstclear(t_cdlst *cdl);
void	ft_cdlst_add_back(t_cdlst *cdl, t_node *new_node);
void	ft_cdlst_add_front(t_cdlst *cdl, t_node *new_node);
t_node	*ft_cdlst_get_front(t_cdlst *cdl);

#endif