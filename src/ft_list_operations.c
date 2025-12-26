/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinhier@student.42Lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 12:18:08 by rpinheir          #+#    #+#             */
/*   Updated: 2025/12/16 12:19:10 by rpinheir         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdlib.h>

/*
** @brief Counts the number of nodes in a circular doubly linked list.
** @param stack Pointer to the stack (circular linked list).
** @return Number of nodes in the stack, or 0 if stack is NULL/empty.
** @note Traverses the list using next pointers until reaching the start.
*/
int	ft_listcount(t_stack **stack)
{
	int		count;
	t_stack	*first_node;
	t_stack	*node;

	if (!stack || !*stack)
		return (0);
	node = *stack;
	first_node = *stack;
	count = 1;
	while (node->next != first_node)
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
	t_stack	*next_node;
	t_stack	*current;

	if (!*stack)
		return ;
	current = *stack;
	current->prev->next = NULL;
	current->prev = NULL;
	while (current)
	{
		next_node = current->next;
		free(current);
		current = next_node;
	}
	*stack = NULL;
}

void	append_node(t_stack **stack, int value)
{
	t_stack	*node;
	t_stack	*first_node;

	first_node = *stack;
	node = malloc(sizeof(t_stack));
	if (!node)
		return ;
	if (!*stack)
	{
		node->prev = node;
		node->next = node;
		node->position = 0;
		*stack = node;
	}
	else
	{
		node->next = first_node;
		node->prev = first_node->prev;
		first_node->prev->next = node;
		first_node->prev = node;
		node->position = ft_listcount(stack) - 1;
	}
	node->value = value;
}

void	pos_change(t_stack **stack)
{
	t_stack	*node;
	int		i;

	if (!*stack || !stack)
		return ;
	i = 0;
	node = *stack;
	while (1)
	{
		node->position = i;
		node = node->next;
		i++;
		if (node == *stack)
			break ;
	}
}
