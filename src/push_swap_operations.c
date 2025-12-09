/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinheir@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 17:26:35 by rpinheir          #+#    #+#             */
/*   Updated: 2025/12/09 12:57:59 by rpinheir         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../include/push_swap.h"

void	sa(t_stack **stack)
{
	t_stack	*first_node;
	t_stack	*second_node;
	t_stack	*ptr;

	first_node = *stack;
	second_node = first_node->next;
	ptr = first_node;
	first_node->next = second_node->next;
	first_node->prev = second_node;
	second_node->next = ptr;
	second_node->prev = NULL;
}
