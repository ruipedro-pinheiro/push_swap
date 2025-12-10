/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinheir@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 17:26:35 by rpinheir          #+#    #+#             */
/*   Updated: 2025/12/10 12:36:07 by rpinheir         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../include/push_swap.h"

void	swap(t_stack **stack)
{
	t_stack	*first_node;
	t_stack	*second_node;
	t_stack	*ptr;
	t_stack	*tmp;

	tmp = *stack;
	if (!tmp || !tmp->next)
		return ;
	first_node = tmp;
	second_node = first_node->next;
	ptr = first_node;
	first_node->next = second_node->next;
	first_node->prev = second_node;
	second_node->next = ptr;
	second_node->prev = tmp->prev;
}

void	sa(t_stack **a)
{
	swap(a);
	write(1, "sa\n", 3);
}

void	sb(t_stack **b)
{
	swap(b);
	write(1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b)
{
	sa(a);
	sb(b);
	write(1, "ss\n", 3);
}
