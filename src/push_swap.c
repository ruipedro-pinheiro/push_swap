/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinhier@student.42Lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 14:37:30 by rpinheir          #+#    #+#             */
/*   Updated: 2025/12/15 14:37:32 by rpinheir         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../libft/libft.h"
#include <stdlib.h>

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
	t_stack	*current;

	if (!a)
		return (0);
	current = a;
	while (1)
	{
		if (current->value == n)
			return (1);
		current = current->next;
		if (current == a)
			break ;
	}
	return (0);
}

static int	process_arg(t_stack **a, char *str)
{
	long long	val;
	char		*tmp;

	tmp = str;
	if (*tmp == '+' || *tmp == '-')
		tmp++;
	while (ft_isdigit(*tmp))
		tmp++;
	val = ft_atoll(str);
	if (*tmp || val > INT_MAX || val < INT_MIN || is_duplicate(*a, val))
		return (1);
	append_node(a, (int)val);
	return (0);
}

void	arg_parser(t_stack **a, char **argv)
{
	int		i;
	int		j;
	char	**input;

	i = 1;
	while (argv[i])
	{
		input = ft_split(argv[i], ' ');
		if (!input)
			return ;
		j = -1;
		while (input[++j])
		{
			if (process_arg(a, input[j]))
			{
				ft_putendl_fd("Error", 2);
				free_matrix(input);
				free_stack(a);
				exit(1);
			}
		}
		free_matrix(input);
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
