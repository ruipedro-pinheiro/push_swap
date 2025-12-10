/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_stack_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir rpinheir@student.42lausanne.ch    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 12:49:04 by rpinheir          #+#    #+#             */
/*   Updated: 2025/12/10 13:51:53 by rpinheir         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../include/push_swap.h"

/*
** @brief Appends a new node with value 'n' to the stack.
** @param stack Pointer to the stack head.
** @param n The integer value to add.
*/
void	append_node(t_stack **stack, int n)
{
	t_stack	*node;
	t_stack	*last_node;
	int		i;

	i = 0;
	if (!stack)
		return ;
	node = malloc(sizeof(t_stack));
	if (!node)
		return ;
	node->next = *stack;
	node->value = n;
	node->position = i;
	if (*stack == NULL)
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		node = *stack;
		last_node = node->prev;
		last_node->next = node;
		node->prev = last_node;
	}
}
