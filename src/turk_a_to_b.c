/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinhier@student.42Lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 14:19:59 by rpinheir          #+#    #+#             */
/*   Updated: 2025/12/16 15:05:09 by rpinheir         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	get_target_b(t_stack *node_a, t_stack **b)
{
	t_stack	*target;
	t_stack	*node;
	int		min;

	node = *b;
	while (1)
	{
		if (node == *b)
			break ;
		if (node->value > node_a->value && node->value < min)
			target = node;
	}
	node_a->target_node = target;
}

void	calc_push_price(t_stack *node, t_stack *target)
{
	int	price;

	price = 0;
}
