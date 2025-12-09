/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinheir@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 15:29:40 by rpinheir          #+#    #+#             */
/*   Updated: 2025/12/09 15:59:19 by rpinheir         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../include/push_swap.h"

void	rotate(t_stack **stack)
{
	t_stack	*node;
	t_stack	*first_node;
	t_stack	*tmp;
	int		i;

	i = 0;
	first_node = *stack;
	node = first_node;
	while (node->next != first_node)
	{
		tmp = node;
		node = node->next;
		node->next->position = i;
		i++;
	}
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
