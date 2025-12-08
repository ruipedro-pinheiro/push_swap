/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinheir@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 14:33:05 by rpinheir          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2025/12/08 14:53:03 by rpinheir         ###   ########.fr       */
=======
/*   Updated: 2025/12/08 14:36:31 by rpinheir         ###   ########.fr       */
>>>>>>> 6f55bc8a8414c4d0b66e33152fd38364a9806e0c
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
	int					value;
	int					push_price;
	int					position;
	bool				cheapest;
	bool				above_median;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}						t_stack;
void					append_node(t_stack **stack, int n);
#endif