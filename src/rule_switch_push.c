/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_switch_push.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunjkim <gunjkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:55:59 by gunjkim           #+#    #+#             */
/*   Updated: 2023/02/22 16:09:02 by gunjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/rule.h"

void	sa(t_stack	*stack)
{
	int	tmp;

	tmp = stack->a->element;
	stack->a->element = stack->a->next->element;
	stack->a->next->element = tmp;
}

void	sb(t_stack	*stack)
{
	int	tmp;

	tmp = stack->b->element;
	stack->b->element = stack->b->next->element;
	stack->b->next->element = tmp;
}

void	ss(t_stack *stack)
{
	sa(stack);
	sb(stack);
}

void	pa(t_stack *stack)
{
	t_node	*tmp;

	if (stack->b == NULL)
		return ;
	tmp = ft_cdlst_get_front(&(stack->b));
	ft_cdlst_add_front(&(stack->a), tmp);
}

void	pb(t_stack *stack)
{
	t_node	*tmp;

	if (stack->a == NULL)
		return ;
	tmp = ft_cdlst_get_front(&(stack->a));
	ft_cdlst_add_front(&(stack->b), tmp);
}
