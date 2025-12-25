/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinhier@student.42Lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 12:19:20 by rpinheir          #+#    #+#             */
/*   Updated: 2025/12/16 12:19:27 by rpinheir         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	pos_change(t_stack **stack);

/*
** @brief Pushes the top element from source stack to destination stack.
** @param dest Pointer to the destination stack.
** @param source Pointer to the source stack.
** @note Moves the first node from source to the top of dest.
** @note Updates the prev/next pointers for circular doubly linked list.
*/
void	push(t_stack **dest, t_stack **source)
{
	t_stack	*first_node_dest;
	t_stack	*first_node_source;

	if (!source || !*source)
		return ;
	first_node_source = *source;
	first_node_source->prev->next = first_node_source->next;
	first_node_source->next->prev = first_node_source->prev;
	if (!dest || !*dest)
	{
		first_node_source->prev = first_node_source;
		first_node_source->next = first_node_source;
	}
	else
	{
		first_node_dest = *dest;
		first_node_source->next = first_node_dest;
		first_node_source->prev = first_node_dest->prev;
		first_node_source->prev->next = first_node_source;
		first_node_dest->prev = first_node_source;
	}
	*source = first_node_source->next;
	*dest = first_node_source;
	pos_change(source);
	pos_change(dest);
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
