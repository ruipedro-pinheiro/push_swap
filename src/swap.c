/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinhier@student.42Lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 12:19:57 by rpinheir          #+#    #+#             */
/*   Updated: 2025/12/16 12:20:29 by rpinheir         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

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
	t_stack	*first;
	t_stack	*second;
	t_stack	*last;

	first = *stack;
	if (!first || first->next == first)
		return ;
	second = first->next;
	last = first->prev;
	first->next = second->next;
	first->next->prev = first;
	first->prev = second;
	second->next = first;
	second->prev = last;
	last->next = second;
	*stack = second;
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
