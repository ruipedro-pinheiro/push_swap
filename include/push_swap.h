/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinheir@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 14:33:05 by rpinheir          #+#    #+#             */
/*   Updated: 2025/11/27 15:27:30 by rpinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdbool.h>

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