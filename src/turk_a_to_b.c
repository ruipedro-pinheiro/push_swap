/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinhier@student.42Lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 14:19:59 by rpinheir          #+#    #+#             */
/*   Updated: 2025/12/17 15:14:55 by rpinheir         ###   ########.ch       */
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
