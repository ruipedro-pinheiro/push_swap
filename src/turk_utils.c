/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinhier@student.42Lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 20:27:18 by rpinheir          #+#    #+#             */
/*   Updated: 2025/12/16 19:58:57 by rpinheir         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	is_sorted(t_stack *stack)
{
	t_stack	*node;
	t_stack	*first_node;

	if (!stack)
		return (0);
	first_node = stack;
	node = first_node;
	while (node->next != first_node)
	{
		if (node->next->value < node->value)
			return (0);
		node = node->next;
	}
	return (1);
}

t_stack	*find_min(t_stack *stack)
{
	t_stack	*first_node;
	t_stack	*smaller;
	t_stack	*node;

	first_node = stack;
	node = first_node;
	smaller = first_node;
	while (1)
	{
		if (node->value < smaller->value)
			smaller = node;
		node = node->next;
		if (node == stack)
			break ;
	}
	return (smaller);
}

t_stack	*find_max(t_stack *stack)
{
	t_stack	*first_node;
	t_stack	*node;
	t_stack	*biggest;

	first_node = stack;
	node = first_node;
	biggest = node;
	while (1)
	{
		if (node->value > biggest->value)
			biggest = node;
		node = node->next;
		if (node == stack)
			break ;
	}
	return (biggest);
}

void	set_median(t_stack *stack)
{
	t_stack	*node;
	int		median;

	node = stack;
	median = ft_listcount(&stack) / 2;
	while (1)
	{
		node->above_median = (node->position < median);
		node = node->next;
		if (node == stack)
			break ;
	}
}
void	rotate_to_top()
{
}
