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

static void	unlink_source(t_stack **source, t_stack *node)
{
	if (node->next == node)
		*source = NULL;
	else
	{
		node->prev->next = node->next;
		node->next->prev = node->prev;
		*source = node->next;
	}
}

static void	link_to_dest(t_stack **dest, t_stack *node)
{
	t_stack	*first;

	if (!dest || !*dest)
	{
		node->prev = node;
		node->next = node;
	}
	else
	{
		first = *dest;
		node->next = first;
		node->prev = first->prev;
		node->prev->next = node;
		first->prev = node;
	}
	*dest = node;
}

void	push(t_stack **dest, t_stack **source)
{
	t_stack	*node;

	if (!source || !*source)
		return ;
	node = *source;
	unlink_source(source, node);
	link_to_dest(dest, node);
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
