/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinhier@student.42Lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 14:19:59 by rpinheir          #+#    #+#             */
/*   Updated: 2025/12/16 19:43:32 by rpinheir         ###   ########.ch       */
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
		if (node->value > node_a->value && node->value < min)
			target = node;
		if (node == *b)
			break ;
	}
	node_a->target_node = target;
}

void	calc_push_price(t_stack *node, t_stack *target)
{
	int		price;
	t_stack	*stack;
	t_stack	*target_stack;

	stack = node;
	target_stack = target;
	price = 0;
	if (!stack)
		price++;
	if (target == stack)
		price++;
	while (1)
	{
		if (node->target_node == target_stack)
			break ;
		if (price > ft_listcount(&target_stack) / 2)
			price = ft_listcount(&target_stack) / 2;
		price++;
	}
}
