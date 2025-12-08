/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listcount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinheir@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 14:26:12 by rpinheir          #+#    #+#             */
/*   Updated: 2025/12/08 14:58:36 by rpinheir         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../include/push_swap.h"

/*
** @brief Compte le nombre de nodes dans une liste chaînée
** @param node Pointeur vers un node de la liste
** @return int Nombre total de nodes dans la liste
** @note Parcourt la liste dans les deux sens (prev/next)
** @warning `node` ne doit pas être NULL
** @see t_stack structure définie dans push_swap.h
*/
int	ft_listcount(t_stack *stack)
{
	int	count;

	count = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		stack = stack->next;
		count++;
	}
	return (count);
}
