/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinhier@student.42Lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 14:19:59 by rpinheir          #+#    #+#             */
/*   Updated: 2025/12/17 17:42:57 by rpinheir         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	get_target_b(t_stack *node_a, t_stack **b)
{
	t_stack	*target;
	t_stack	*node;
	t_stack	*min;

	node = *b;
	min = node;
	while (1)
	{
		if (node->value > node_a->value && node->value < min->value)
			target = node;
		if (node == *b)
			break ;
	}
	node_a->target_node = target;
}

void	calc_push_price(t_stack *node, t_stack *target)
{
	if (node->above_median && target->above_median)
	{
		node->push_price = node->position + 1;
		target->push_price = target->position + 1;
	}
	else if (!node->above_median && !target->above_median)
	{
		node->push_price = ft_listcount(&node) - node->position + 1;
		target->push_price = ft_listcount(&target) - node->position + 1;
	}
	// et maintenant si node est au dessus et target en dessous
	if (node->above_median && !target->above_median)
	{
		node->push_price = node->position + 1;
		target->push_price = ft_listcount(&target) - node->position + 1;
	}
	else if (!node->above_median && target->above_median)
	{
		node->push_price = ft_listcount(&node) - node->position + 1;
		target->push_price = target->position + 1;
	}
}

void	init_nodes_a(t_stack **a, t_stack **b)
{
	t_stack	*node;

	node = *a;
	while (1)
	{
		get_target_b(node, b);
		calc_push_price(node, node->target_node);
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

void	rotate_both(t_stack **a, t_stack **b, t_stack *cheapest)
{
	int	i;
	int	min;
	int	rest;

	i = 0;
	if (cheapest->position < cheapest->target_node->position)
	{
		min = cheapest->position;
		rest = cheapest->target_node->position - cheapest->position;
	}
	min = cheapest->target_node->position;
	rest = cheapest->position - cheapest->target_node->position;
	// on fait l'operation rrr le nombre de fois de la poisiton la plus petite
	if (cheapest->above_median && cheapest->target_node->above_median)
	{
		while (i++ <= min)
			rrr(a, b);
	}
	else
	{
		while (i++ <= min)
			rr(a, b);
	}
}
