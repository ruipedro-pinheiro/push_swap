/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinheir@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 14:33:05 by rpinheir          #+#    #+#             */
/*   Updated: 2025/12/08 12:34:20 by rpinheir         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdbool.h>

/*
** @param	int				value;
** @param	int				push_price;
** @param	int				position;
** @param	bool			cheapest;
** @param	bool			above_median;
** @param	struct stack	*next;
** @param	struct stack	*prev;
*/
typedef struct stack
{
	int				value;
	int				push_price;
	int				position;
	bool			cheapest;
	bool			above_median;
	struct stack	*next;
	struct stack	*prev;
}					t_stack;

#endif