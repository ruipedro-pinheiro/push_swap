/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinhier@student.42Lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 20:27:18 by rpinheir          #+#    #+#             */
/*   Updated: 2025/12/15 20:47:15 by rpinheir         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	is_sorted(t_stack **stack)
{
	t_stack	*node;
	t_stack	*first_node;

	if (!stack || !*stack)
		return (0);
	first_node = *stack;
	node = first_node;
	while (node->next != first_node)
	{
		if (node->prev->value < node->value)
			continue ;
		else if (node->prev->value > node->value)
			return (0);
	}
	return (1);
}

void	find_min(t_stack **stack)
{
	t_stack	*first_node;
	t_stack	*smaller;
	t_stack	*node;

	first_node = *stack;
	node = first_node;
	smaller = first_node;
	while (1)
	{
		if (node == *stack)
			break ;
		if (node->value < smaller->value)
			smaller = node;
		node = node->next;
	}
}
