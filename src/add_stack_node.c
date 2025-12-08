/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_stack_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinheir@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 12:49:04 by rpinheir          #+#    #+#             */
/*   Updated: 2025/12/08 13:10:09 by rpinheir         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "libft/libft.h"
#include "push_swap.h"

void	add_stack_node(char **argv)
{
	int		i;
	int		j;
	t_stack	node;
	t_stack	current;
	t_stack	*ptr;

	while (argv[i][0])
	{
		while (argv[i][j])
		{
			current->value = argv[i][j];
			current->position = i;
			j++;
		}
		j = 0;
		i++;
	}
}
