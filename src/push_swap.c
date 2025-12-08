/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinheir@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 14:59:18 by rpinheir          #+#    #+#             */
/*   Updated: 2025/12/05 00:56:33 by rpinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
** @brief Parse les arguments de la ligne de commande
** @param argc Nombre d'arguments passes au programme
** @param argv Tableau de chaines contenant les arguments
** @return t_stack* Pointeur vers le premier node de stack_a (ou NULL si erreur)
** @note `argc` inclut le nom du programme (argv[0])
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
** @brief Point d’entrée du programme push_swap
** @param argc Nombre d'arguments (incluant le nom du programme)
** @param argv Tableau de chaînes des arguments
** @return int 0 si succès, 1 si erreur
*/
int	main(int argc, char **argv)
{
	ft_printf("Arguments = %i \n", argc - 1);
	arg_parser(argc, argv);
}
