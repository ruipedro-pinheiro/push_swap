/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinheir@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 15:29:40 by rpinheir          #+#    #+#             */
/*   Updated: 2025/12/11 16:43:42 by rpinheir         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../include/push_swap.h"

/*
** @brief Rotates the stack upward (first element becomes last).
** @param stack Pointer to the stack to rotate.
** @note Updates the stack pointer to point to the next node.
** @note Recalculates position indices for all nodes.
*/
void	rotate(t_stack **stack)
{
	t_stack	*node;
	t_stack	*first_node;
	t_stack	*tmp;
	int		i;

	i = 0;
	first_node = *stack;
	node = first_node->next;
	while (node != first_node)
	{
		tmp = node;
		node = node->next;
		node->position = i;
		i++;
	}
	*stack = first_node->prev;
}

void	ra(t_stack **a)
{
	rotate(a);
	write(1, "ra\n", 3);
}

void	rb(t_stack **b)
{
	rotate(b);
	write(1, "rb\n", 3);
}
