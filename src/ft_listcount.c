/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listcount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinheir@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 14:26:12 by rpinheir          #+#    #+#             */
/*   Updated: 2025/11/27 14:37:49 by rpinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
** @brief Compte le nombre de nodes dans une liste chainee
** @param node Pointeur vers un node de la liste
** @return int Nombre total de nodes dans la liste
** @note Parcourt la liste dans les deux sens (prev/next)
** @warning `node` ne doit pas etre NULL
** @see t_stack structure definie dans push_swap.h
*/
int	ft_listcount(t_stack *node)
{
	int		pos;
	int		count;
	t_stack	*ptr;

	pos = node->position;
	if (pos > 0)
	{
		count += pos;
		if (node->next)
			ptr->next = node->next;
	}
	if (node->next || node->prev)
	{
		while (node->prev)
		{
			ptr->next = node->next;
			count++;
		}
	}
	return (count);
}
