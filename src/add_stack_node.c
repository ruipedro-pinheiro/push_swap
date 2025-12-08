/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_stack_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinheir@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 12:49:04 by rpinheir          #+#    #+#             */
/*   Updated: 2025/12/08 15:17:31 by rpinheir         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../include/push_swap.h"

/*
** @brief Finds the last node of the stack.
** @param head Pointer to the first node.
** @return Pointer to the last node, or NULL if empty.
*/
static t_stack	*find_last_node(t_stack *head)
{
	if (!head)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head);
}

/*
** @brief Appends a new node with value 'n' to the stack.
** @param stack Pointer to the stack head.
** @param n The integer value to add.
*/
void	append_node(t_stack **stack, int n)
{
	t_stack	*node;
	t_stack	*last_node;

	if (!stack)
		return ;
	node = malloc(sizeof(t_stack));
	if (!node)
		return ;
	node->next = NULL;
	node->value = n;
	if (*stack == NULL)
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = find_last_node(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}
