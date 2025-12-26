/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinhier@student.42Lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 12:00:00 by rpinheir          #+#    #+#             */
/*   Updated: 2025/12/26 14:21:11 by rpinheir         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*get_cheapest(t_stack *stack)
{
	t_stack	*node;

	node = stack;
	while (1)
	{
		if (node->cheapest)
			return (node);
		node = node->next;
		if (node == stack)
			break ;
	}
	return (stack);
}

void	reset_cheapest(t_stack *stack)
{
	t_stack	*node;

	if (!stack)
		return ;
	node = stack;
	while (1)
	{
		node->cheapest = false;
		node = node->next;
		if (node == stack)
			break ;
	}
}

void	rotate_both_rr(t_stack **a, t_stack **b, t_stack *node, t_stack *target)
{
	while (*a != node && *b != target)
		rr(a, b);
	while (*a != node)
		ra(a);
	while (*b != target)
		rb(b);
}

void	rotate_both_rrr(t_stack **a, t_stack **b, t_stack *node,
		t_stack *target)
{
	while (*a != node && *b != target)
		rrr(a, b);
	while (*a != node)
		rra(a);
	while (*b != target)
		rrb(b);
}

void	move_and_push(t_stack **a, t_stack **b, t_stack *cheapest)
{
	t_stack	*target;

	target = cheapest->target_node;
	if (cheapest->above_median && target->above_median)
		rotate_both_rr(a, b, cheapest, target);
	else if (!cheapest->above_median && !target->above_median)
		rotate_both_rrr(a, b, cheapest, target);
	else
	{
		rotate_a_to_top(a, cheapest);
		rotate_b_to_top(b, target);
	}
	pb(a, b);
}
