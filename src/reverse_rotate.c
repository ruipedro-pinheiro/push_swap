/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinheir@student.42lausanne.ch>    +#+  +:+
		+#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 14:22:40 by rpinheir          #+#    #+#             */
/*   Updated: 2025/12/10 14:22:47 by rpinheir         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
** @brief Reverse rotates the stack (last element becomes first).
** @param stack Pointer to the stack to reverse rotate.
** @note In a circular list, moves the stack pointer to the previous node.
** @note Recalculates position indices for all nodes.
*/
void	reverse_rotate(t_stack **stack)
{
	t_stack	*node;
	t_stack	*first_node;
	int		i;

	if (!stack || !*stack)
		return ;
	i = 0;
	first_node = *stack;
	node = first_node->prev;
	while (node->prev != first_node->prev)
	{
		node->position = i;
		node = node->prev;
		i++;
	}
	*stack = first_node->prev;
}

void	rra(t_stack **a)
{
	reverse_rotate(a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack **b)
{
	reverse_rotate(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	write(1, "rrr\n", 4);
}
