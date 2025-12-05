/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinheir@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 14:59:18 by rpinheir          #+#    #+#             */
/*   Updated: 2025/12/05 17:51:32 by rpinheir         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../include/push_swap.h"
#include "../libft/libft.h"
#include <limits.h>

/*
** @brief Parse les arguments de la ligne de commande
** @param argc Nombre d'arguments passes au programme
** @param argv Tableau de chaînes contenant les arguments
** @return int (a implémenter: code de retour)
** @note `argc` inclut le nom du programme (argv[0]),
** donc argc - 1 = nombre d'arguments réels
*/
int	arg_parser(char **argv)
{
	int			i;
	int			x;
	int			y;
	long long	output;
	char		**input;

	i = 0;
	x = 0;
	y = 0;
	output = 0;
	while (argv[1][i])
	// 1 ici = le premier argument réellement pas le nom du programme
	{
		if (ft_isdigit(argv[1][i]) == 0)
		{
			input = ft_split(argv[1], ' ');
			if (!input)
				free(input);
			while (input[x][y])
			{
				output = ft_atoll(&input[x][0]);
				x++;
			}
			if (output < INT_MIN || output > INT_MAX)
				ft_putendl_fd("Error", 1);
		}
		else
		{
			/* TODO: on input les int SANS parser de ascii en int
			**	Cela n'est pas nécessaire, vu qu'on *SAIT*
			**	que c'est des int et pas du ascii
			*/
		}
		i++;
	}
	return (output);
}

/*
** @brief Point d’entrée du programme push_swap
** @param argc Nombre d'arguments (incluant le nom du programme)
** @param argv Tableau de chaînes des arguments
** @return int 0 si succès, 1 si erreur
** @see arg_parser() pour le parsing des arguments
** @warning Les arguments doivent être des entiers valides
** @example ./push_swap 3 2 1
*/
int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		ft_printf("Output %i \n", arg_parser(argv));
	}
}
