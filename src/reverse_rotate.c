/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinheir@student.42lausanne.ch>    +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 13:00:30 by rpinheir          #+#    #+#             */
/*   Updated: 2025/12/10 13:00:33 by rpinheir         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/* @brief le dernier devient premier
**@note `first_node = *stack;` // on connait donc le node qui commence la stack
**@note `first_node->prev;`    // on commence avec le dernier
*/
void	reverse_rotate(t_stack **stack)
{
	t_stack	*node;
	t_stack	*first_node;
	t_stack	*tmp;
	int		i;

	i = 0;
	first_node = *stack;
	node = first_node->prev;
	while (node->prev != first_node->prev)
	{
		tmp = node;
		node->position = i;
		node = node->prev;
		i++;
	}
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
	rra(a);
	rrb(b);
	write(1, "rrr\n", 4);
}
