/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_stack_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinheir@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 12:49:04 by rpinheir          #+#    #+#             */
/*   Updated: 2025/12/08 13:02:24 by rpinheir         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "libft/libft.h"
#include "push_swap.h"

void	add_stack_node(char **argv)
{
	t_stack	node;
	t_stack	current;
	t_stack	*ptr;

	while (argv[i][j])
	{
		current->value = argv[i][j++];
		current->position = i;
		i++;
		current->next = node->next;
	}
}
