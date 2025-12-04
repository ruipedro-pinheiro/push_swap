/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinheir@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 14:59:18 by rpinheir          #+#    #+#             */
/*   Updated: 2025/12/04 18:02:23 by rpinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../libft/libft.h"

/*
** @brief Lit le parametre `argv` depuis le main et le formatte en int
** @param argc  Compte combien de arguments sont donnes,
** @param argv  Tableau 2D de tous les arguments donnes
** @note `argc` compte en veriter les arguments depuis 1,
** 0 etant le nom du programme.
*/
int	arg_parser(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < argc && argv[i][j] && *argv[i])
	{
		while (argv[i][j] && *argv[i])
		{
			ft_printf("%c\n", argv[i][j]);
			j++;
		}
		j = 0;
		i++;
	}
}

/*
** @brief Fonction principale qui appelle le reste des fonctions necessaires
** @param argc  Compte combien de arguments sont donnes
** @param argv  Tableau 2D de tous les arguments donnes
** @note `argc` compte en veriter les arguments depuis 1,
** 0 etant le nom du programme.
*/
int	main(int argc, char **argv)
{
	ft_printf("Arguments = %i \n", argc - 1);
	arg_parser(argc, **argv);
}
