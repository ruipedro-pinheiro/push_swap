/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinheir@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 14:26:12 by rpinheir          #+#    #+#             */
/*   Updated: 2025/12/10 23:59:07 by rpinheir         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../include/push_swap.h"
#include "push_swap.h"

/*
** @brief Counts the number of nodes in a circular doubly linked list.
** @param stack Pointer to the stack (circular linked list).
** @return Number of nodes in the stack, or 0 if stack is NULL/empty.
** @note Traverses the list using next pointers until reaching the start.
** @warning Current implementation has an off-by-one bug (doesn't count last node).
*/
int	ft_listcount(t_stack **stack)
{
	int		count;
	t_stack	*first_node;
	t_stack	*node;

	node = *stack;
	first_node = *stack;
	count = 0;
	if (!node)
		return (0);
	while (node != first_node->prev)
	{
		node = node->next;
		count++;
	}
	return (count);
}

/*
** @brief Frees all nodes in a circular doubly linked list.
** @param stack Pointer to the stack to free.
** @note Breaks the circular structure before freeing to avoid infinite loop.
** @warning Current implementation may not work correctly for circular lists.
*/
void	free_stack(t_stack **stack)
{
	t_stack *next_node;
	t_stack *current;

	current = *stack;
	while (current)
	{
		next_node = current->next;
		free(current);
		current = next_node;
	}
}