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
** Compte combien de nodes il y a sur une liste chainee.
** @param node: le node existant dans une liste.
** Fonction: Compte combien de nodes il y a sur toute la liste.
** et retourne un int avec le nombre de nodes trouves
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
