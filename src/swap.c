/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinheir@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 17:26:35 by rpinheir          #+#    #+#             */
/*   Updated: 2025/12/10 14:34:30 by rpinheir         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../include/push_swap.h"
#include <unistd.h>

/*
** @brief Swaps the first two elements in a circular stack.
** @param stack Pointer to the stack to swap.
** @note Does nothing if stack has less than 2 elements.
** @note Updates prev/next pointers to maintain circular structure.
*/
void	swap(t_stack **stack)
{
	t_stack	*first_node;
	t_stack	*second_node;
	t_stack	*tmp;

	tmp = *stack;
	if (!tmp || tmp->next == tmp)
		return ;
	first_node = tmp;
	second_node = first_node->next;
	first_node->next = second_node->next;
	first_node->prev = second_node;
	second_node->next = tmp;
	second_node->prev = tmp->prev;
	*stack = second_node;
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
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
}
