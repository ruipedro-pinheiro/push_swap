/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinheir@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 13:40:04 by rpinheir          #+#    #+#             */
/*   Updated: 2025/12/09 15:34:14 by rpinheir         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../include/push_swap.h"

/*
** @brief Push function that will move top element in stack to another
** @param a the stack a
** @param b the stack b
** @note This is the general function.
**      The real push functions for specific stacks are above
*/
void	push(t_stack **a, t_stack **b)
{
	t_stack	*first_node_a;
	t_stack	*first_node_b;

	first_node_a = *a;
	first_node_b = *b;
	first_node_b->prev = NULL;
	first_node_b->next = first_node_a;
	first_node_a->prev = first_node_b;
	first_node_b->position = 1; // 0 ou 1 ?
}

void	pa(t_stack **a, t_stack **b)
{
	push(a, b);
	write(1, "pa\n", 3);
}

void	pb(t_stack **a, t_stack **b)
{
	push(b, a);
	write(1, "pb\n", 3);
}
