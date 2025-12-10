/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinheir@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 14:26:12 by rpinheir          #+#    #+#             */
/*   Updated: 2025/12/10 13:00:18 by rpinheir         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../include/push_swap.h"
#include "push_swap.h"

/*
** @brief Compte le nombre de nodes dans une liste chaînée
** @param node Pointeur vers un node de la liste
** @return int Nombre total de nodes dans la liste
** @note Parcourt la liste dans les deux sens (prev/next)
** @warning `node` ne doit pas être NULL
** @see t_stack structure définie dans push_swap.h
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
		error_exit(&node);
	while (node != first_node->prev)
	{
		node = node->next;
		count++;
	}
	return (count);
}

void	free_stack(t_stack **stack)
{
	t_stack	*next_node;
	t_stack	*current;

	current = *stack;
	while (current)
	{
		next_node = current->next;
		free(current);
		current = next_node;
	}
}

void	error_exit(t_stack **stack)
{
	if (stack)
		free_stack(stack);
	ft_putendl_fd("Error", 2);
}
