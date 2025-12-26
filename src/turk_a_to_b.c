/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinhier@student.42Lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 14:19:59 by rpinheir          #+#    #+#             */
/*   Updated: 2025/12/26 14:20:46 by rpinheir         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
** Find target in B for node from A.
** B is kept in descending order.
** Target = largest node in B that is SMALLER than node_a.
** If node_a is smaller than all B, target = max of B.
*/
void	get_target_b(t_stack *node_a, t_stack **b)
{
	t_stack	*node;
	t_stack	*target;
	int		best_match;

	node = *b;
	target = NULL;
	best_match = INT_MIN;
	while (1)
	{
		if (node->value < node_a->value && node->value > best_match)
		{
			best_match = node->value;
			target = node;
		}
		node = node->next;
		if (node == *b)
			break ;
	}
	if (!target)
		target = find_max(*b);
	node_a->target_node = target;
}

/*
** Calculate total cost to push node from A to B.
** Cost = rotations for A + rotations for B (or max if same direction).
*/
void	calc_push_price(t_stack *node, t_stack *target, int size_a, int size_b)
{
	int	cost_a;
	int	cost_b;

	if (node->above_median)
		cost_a = node->position;
	else
		cost_a = size_a - node->position;
	if (target->above_median)
		cost_b = target->position;
	else
		cost_b = size_b - target->position;
	if (node->above_median == target->above_median)
	{
		if (cost_a > cost_b)
			node->push_price = cost_a;
		else
			node->push_price = cost_b;
	}
	else
		node->push_price = cost_a + cost_b;
}

void	init_nodes_a(t_stack **a, t_stack **b)
{
	t_stack	*node;
	int		size_a;
	int		size_b;

	size_a = ft_listcount(a);
	size_b = ft_listcount(b);
	node = *a;
	while (1)
	{
		get_target_b(node, b);
		calc_push_price(node, node->target_node, size_a, size_b);
		node = node->next;
		if (node == *a)
			break ;
	}
}

void	set_cheapest(t_stack **stack)
{
	t_stack	*node;
	t_stack	*cheapest;

	node = *stack;
	cheapest = node;
	while (1)
	{
		if (node->push_price < cheapest->push_price)
			cheapest = node;
		node = node->next;
		if (node == *stack)
			break ;
	}
	cheapest->cheapest = true;
}
