/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinheir@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 14:33:05 by rpinheir          #+#    #+#             */
/*   Updated: 2025/12/11 13:58:15 by rpinheir         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <limits.h>
# include <stdbool.h>

/*
** @brief Stack node structure.
** @param value Integer value.
** @param push_price Cost to push this node to the target stack.
** @param position Current index (0-based).
** @param cheapest True if this is the cheapest node to move.
** @param above_median True if node is above the stack median.
** @param target_node Pointer to the optimal target in the other stack.
** @param next Pointer to the next node.
** @param prev Pointer to the previous node.
*/
typedef struct stack
{
	int				value;
	int				push_price;
	int				position;
	bool			cheapest;
	bool			above_median;
	struct stack	*target_node;
	struct stack	*next;
	struct stack	*prev;
}					t_stack;
void				free_stack(t_stack **stack);
int					ft_listcount(t_stack **stack);
void				swap(t_stack **stack);
void				push(t_stack **dest, t_stack **source);
void				reverse_rotate(t_stack **stack);
void				rotate(t_stack **stack);
#endif