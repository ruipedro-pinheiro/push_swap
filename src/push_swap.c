/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinheir@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 14:59:18 by rpinheir          #+#    #+#             */
/*   Updated: 2025/12/11 13:12:11 by rpinheir         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../include/push_swap.h"
#include "../libft/libft.h"

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
	long long	val;
	int			i;

	input = ft_split(arg_str, ' ');
	if (!input)
		return ;
	i = -1;
	while (input[++i])
	{
		arg_str = input[i];
		if (*arg_str == '+' || *arg_str == '-')
			arg_str++;
		while (ft_isdigit(*arg_str))
			arg_str++;
		val = ft_atoll(input[i]);
		if (*arg_str || val > INT_MAX || val < INT_MIN || is_duplicate(*a, val))
		{
			ft_putendl_fd("Error", 2);
			free_matrix(input);
			free_stack(a);
		}
		// append_node(a, (int)val); FIXME
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
