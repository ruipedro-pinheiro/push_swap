/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinhier@student.42Lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< HEAD
/*   Created: 2025/12/16 12:55:17 by rpinheir          #+#    #+#             */
/*   Updated: 2025/12/16 12:55:40 by rpinheir         ###   ########.ch       */
=======
/*   Created: 2025/12/16 12:36:35 by rpinheir          #+#    #+#             */
/*   Updated: 2025/12/16 12:40:51 by rpinheir         ###   ########.ch       */
>>>>>>> 6056927962b44f950e9b08984c1907dbd85b10ce
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <limits.h>
# include <stdbool.h>

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
void				append_node(t_stack **stack, int value);
#endif
