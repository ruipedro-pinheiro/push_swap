/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinhier@student.42Lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 12:19:34 by rpinheir          #+#    #+#             */
/*   Updated: 2025/12/17 17:18:10 by rpinheir         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

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
	int		i;

	if (!stack || !*stack)
		return ;
	i = 0;
	first_node = *stack;
	node = first_node->next;
	while (node != first_node)
	{
		node->position = i;
		node = node->next;
		i++;
	}
	node->position = i;
	*stack = first_node->next;
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

void	rr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}
