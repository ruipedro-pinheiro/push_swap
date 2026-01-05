/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinhier@student.42Lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 12:58:16 by rpinheir          #+#    #+#             */
/*   Updated: 2025/12/17 17:19:42 by rpinheir         ###   ########.ch       */
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
	bool			is_sorted;
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
void				pos_change(t_stack **stack);

void				rr(t_stack **a, t_stack **b);
void				rb(t_stack **b);
void				ra(t_stack **a);

void				rra(t_stack **a);
void				rrb(t_stack **b);
void				rrr(t_stack **a, t_stack **b);
void				search_for_LIS(t_stack **stack);

/* swap.c */
void				sa(t_stack **a);
void				sb(t_stack **b);
void				ss(t_stack **a, t_stack **b);

/* push.c */
void				pa(t_stack **a, t_stack **b);
void				pb(t_stack **a, t_stack **b);

/* three_sort.c */
void				three_sort(t_stack **stack);

/* turk_utils.c */
int					is_sorted(t_stack *stack);
t_stack				*find_min(t_stack *stack);
t_stack				*find_max(t_stack *stack);
void				set_median(t_stack *stack);

/* turk_a_to_b.c */
void				init_nodes_a(t_stack **a, t_stack **b);
void				set_cheapest(t_stack **stack);

/* turk_b_to_a.c */
void				init_nodes_b(t_stack **a, t_stack **b);
void				rotate_a_to_top(t_stack **a, t_stack *node);
void				rotate_b_to_top(t_stack **b, t_stack *node);

/* sort.c */
void				sort_stack(t_stack **a, t_stack **b);

/* sort_utils.c */
t_stack				*get_cheapest(t_stack *stack);
void				reset_cheapest(t_stack *stack);
void				rotate_both_rr(t_stack **a, t_stack **b, t_stack *n,
						t_stack *t);
void				rotate_both_rrr(t_stack **a, t_stack **b, t_stack *n,
						t_stack *t);
void				move_and_push(t_stack **a, t_stack **b, t_stack *c);

#endif
