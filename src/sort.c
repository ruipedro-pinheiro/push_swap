/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinhier@student.42Lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 12:21:00 by rpinheir          #+#    #+#             */
/*   Updated: 2025/12/26 14:22:11 by rpinheir         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
** Push nodes from A to B until only 3 remain in A.
** Uses cost-based selection to minimize operations.
*/
static void	a_to_b(t_stack **a, t_stack **b)
{
	t_stack	*cheapest;

	cheapest = *a;
	while (ft_listcount(a) > 3)
	{
		if (ft_listcount(b) < 2)
		{
			pb(a, b);
			continue ;
		}
		reset_cheapest(*a);
		search_for_LIS(a);
		pos_change(a);
		pos_change(b);
		set_median(*a);
		set_median(*b);
		init_nodes_a(a, b);
		set_cheapest(a);
		cheapest = get_cheapest(*a);
		move_and_push(a, b, cheapest);
	}
}

/*
** Push all nodes from B back to A in sorted order.
*/
static void	b_to_a(t_stack **a, t_stack **b)
{
	while (*b)
	{
		init_nodes_b(a, b);
		rotate_a_to_top(a, (*b)->target_node);
		pa(a, b);
	}
}

/*
** Rotate A until the minimum value is at the top.
*/
static void	final_rotate(t_stack **a)
{
	t_stack	*min;

	min = find_min(*a);
	pos_change(a);
	set_median(*a);
	while (*a != min)
	{
		if (min->above_median)
			ra(a);
		else
			rra(a);
	}
}

/*
** Main sorting function.
** Handles edge cases and orchestrates the Turk algorithm.
*/
void	sort_stack(t_stack **a, t_stack **b)
{
	int		size;
	t_stack	*node;

	node = *a;
	size = ft_listcount(a);
	if (size <= 1 || is_sorted(*a))
		return ;
	if (size == 2)
	{
		if ((*a)->value > (*a)->next->value)
			sa(a);
		return ;
	}
	if (size == 3)
	{
		three_sort(a);
		return ;
	}
	a_to_b(a, b);
	b_to_a(a, b);
	final_rotate(a);
}
