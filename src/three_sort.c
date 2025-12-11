/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinheir@student.42lausanne.ch>    +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 17:53:22 by rpinheir          #+#    #+#             */
/*   Updated: 2025/12/11 17:56:54 by rpinheir         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** @brief function to sort 3 nodes in a stack ascending (smaller to bigger)
** @param stack the stack containing the 3 nodes
** @return does not return anything
** [1] [2] [3] | [2] [1] [3] | [3] [2] [1] | [3] [1] [2]
*/
void	three_sort(t_stack **stack)
{
	t_stack		*first_node;
	long long	val;

	first_node = *stack;
	if (first_node->value > first_node->next->value
		&& first_node->prev > first_node->value)
		reverse_rotate(stack);
	else if (first_node->next->value > first_node->prev->value)
		rotate(stack);
}
