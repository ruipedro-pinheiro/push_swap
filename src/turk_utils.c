/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinhier@student.42Lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 20:27:18 by rpinheir          #+#    #+#             */
/*   Updated: 2025/12/26 14:20:44 by rpinheir         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	is_rot_sorted(t_stack *stack)
{
	t_stack	*max;

	if (!stack)
		return (0);
	max = find_max(stack);
	if (max->next != find_min(stack))
		return (0);
	if (stack != find_min(stack))
		return (0);
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

void	search_for_LIS(t_stack **stack)
{
	t_stack	*last_node;
	t_stack	*node;

	node = *stack;
	last_node = node;
	while (1)
	{
		if (node == *stack)
			break ;
		if (node->value < node->next->value)
		{
			node->is_sorted = true;
			node->next->is_sorted = true;
			last_node = node->next;
		}
		else if (node->value > last_node->value)
		{
			last_node = node;
			node->is_sorted = true;
		}
		node = node->next;
	}
}
