/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinhier@student.42Lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 12:25:00 by rpinheir          #+#    #+#             */
/*   Updated: 2025/12/16 12:27:26 by rpinheir         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "../libft/libft.h"
#include <limits.h>
#include <stdbool.h>

typedef struct stack {
  int value;
  int push_price;
  int position;
  bool cheapest;
  bool above_median;
  struct stack *target_node;
  struct stack *next;
  struct stack *prev;
} t_stack;
void free_stack(t_stack **stack);
int ft_listcount(t_stack **stack);
void swap(t_stack **stack);
void push(t_stack **dest, t_stack **source);
void reverse_rotate(t_stack **stack);
void rotate(t_stack **stack);
void append_node(t_stack **stack, int value);
#endif
