/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_b_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinhier@student.42Lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 12:00:00 by rpinheir          #+#    #+#             */
/*   Updated: 2025/12/26 12:00:00 by rpinheir         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
** Find the target position in A for a node from B.
** Target = smallest node in A that is GREATER than B's value.
** If B is larger than all A nodes, target = minimum of A (wrap around).
*/
static void	get_target_a(t_stack *node_b, t_stack **a)
{
	t_stack	*node;
	t_stack	*target;
	int		best_match;

	node = *a;
	target = NULL;
	best_match = INT_MAX;
	while (1)
	{
		if (node->value > node_b->value && node->value < best_match)
		{
			best_match = node->value;
			target = node;
		}
		node = node->next;
		if (node == *a)
			break ;
	}
	if (!target)
		target = find_min(*a);
	node_b->target_node = target;
}

/*
** Initialize all nodes in B with their target positions in A.
** Also updates positions and above_median for both stacks.
*/
void	init_nodes_b(t_stack **a, t_stack **b)
{
	t_stack	*node;

	pos_change(a);
	pos_change(b);
	set_median(*a);
	set_median(*b);
	node = *b;
	while (1)
	{
		get_target_a(node, a);
		node = node->next;
		if (node == *b)
			break ;
	}
}

void	rotate_a_to_top(t_stack **a, t_stack *node)
{
	while (*a != node)
	{
		if (node->above_median)
			ra(a);
		else
			rra(a);
	}
}

void	rotate_b_to_top(t_stack **b, t_stack *node)
{
	while (*b != node)
	{
		if (node->above_median)
			rb(b);
		else
			rrb(b);
	}
}
