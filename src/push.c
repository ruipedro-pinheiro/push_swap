/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinheir@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 13:40:04 by rpinheir          #+#    #+#             */
/*   Updated: 2025/12/10 16:34:49 by rpinheir         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../include/push_swap.h"

/*
** @brief Push function that will move top element in stack to another
** @param a the stack a
** @param b the stack b
** 	@note `first_node_source->next = first_node_dest`
	// On dit que le node apres le node source
	//est AVANT le premier node de la stack dest
	`first_node_dest->prev = first_node_source`
	// On dit au ancien premier node de la
	// stack dest qu'il y a le nouveau node avant
*/
void	push(t_stack **dest, t_stack **source)
{
	t_stack	*first_node_dest;
	t_stack	*first_node_source;

	first_node_dest = *dest;
	first_node_source = *source;
	first_node_source->prev = first_node_dest->prev;
	// on link le dernier element de la stack dest au node de la stack source
	first_node_source->next = first_node_dest;
	first_node_dest->prev = first_node_source;
	first_node_dest->prev->next = first_node_source;
	*dest = first_node_source;
	first_node_dest->position = 1;
	first_node_source->position = 0;
	first_node_dest->prev->position++;
	// FIXME il faut modifer tout le reste de la liste et pas un seul
	*source = first_node_source->next;
	first_node_source->next->position = 0;
	first_node_source->next->position--;
	// FIXME il faut modifer tout le reste de la liste et pas un seul
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
