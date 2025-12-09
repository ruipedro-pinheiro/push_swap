/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinheir@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 14:59:18 by rpinheir          #+#    #+#             */
/*   Updated: 2025/12/09 16:57:26 by rpinheir         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../include/push_swap.h"
#include "../libft/libft.h"

/*
** TODO
**
** 1. OPERATIONS (src/operations/)
**    [DONE] Implement swap (sa, sb, ss)
**    [DONE] Implement push (pa, pb)
**    [DONE] Implement rotate (ra, rb, rr)
**    [ ] Implement reverse rotate (rra, rrb, rrr)
**
** 2. ERROR HANDLING & MEMORY
**    [DONE] Implement free_stack(t_stack **stack) to free the list
**    [DONE] Implement error_exit(t_stack **stack)
**		that prints "Error\n" and frees
**    [DONE] Check for DUPLICATES in process_arg (crucial!)
**
** 3. SORTING ALGORITHM (src/sort/)
**    [ ] Implement sort_three(t_stack **a) for small stacks
**    [ ] Implement Turk Algorithm for large stacks:
**        - init_nodes_a (set indices, etc.)
**        - init_nodes_b (find targets in A)
**        - current_index (update positions)
**        - set_cheapest (calculate cost)
**        - push_swap (main algo loop)
*/

/*
** @brief Frees a NULL-terminated array of strings.
** @param argv The array to free.
*/
void	free_matrix(char **argv)
{
	int	i;

	i = 0;
	if (argv == NULL || *argv == NULL)
		return ;
	while (argv[i])
		free(argv[i++]);
	free(argv);
}

static int	is_duplicate(t_stack *a, int n)
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->value == n)
			return (1);
		a = a->next;
	}
	return (0);
}

/*
** @brief Processes an argument string and adds numbers to stack A.
** Handles both single numbers and space-separated strings.
** @param a Pointer to Stack A.
** @param arg_str The string to process.
*/
static void	process_arg(t_stack **a, char *arg_str)
{
	char		**input;
	int			i;
	long long	val;

	input = ft_split(arg_str, ' ');
	if (!input)
		return ;
	i = 0;
	while (input[i])
	{
		val = ft_atoll(input[i]);
		if (val > INT_MAX || val < INT_MIN || is_duplicate(*a, (int)val))
		{
			ft_putendl_fd("Error", 2);
			free_matrix(input);
			free_stack(a);
			exit(1);
		}
		append_node(a, (int)val);
		i++;
	}
	free_matrix(input);
}

/*
** @brief Main argument parsing loop.
** Iterates through argv and populates Stack A.
** @param a Pointer to Stack A.
** @param argv Command line arguments.
*/
void	arg_parser(t_stack **a, char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		process_arg(a, argv[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_stack	*a;

	a = NULL;
	(void)argc;
	if (argc < 2)
		return (0);
	arg_parser(&a, argv);
	return (0);
}
