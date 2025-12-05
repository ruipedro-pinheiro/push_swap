/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinheir@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 14:59:18 by rpinheir          #+#    #+#             */
/*   Updated: 2025/12/05 13:45:54 by rpinheir         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../include/push_swap.h"
#include "../libft/libft.h"

/*
** @brief Parse les arguments de la ligne de commande
** @param argc Nombre d'arguments passes au programme
** @param argv Tableau de chaînes contenant les arguments
** @return int (a implémenter: code de retour)
** @note `argc` inclut le nom du programme (argv[0]),
** donc argc - 1 = nombre d'arguments réels
*/
int	arg_parser(int argc, char **argv)
{
	int		i;
	int		j;
	char	*input;

	i = 0;
	j = 0;
	input = '\0';
	if (ft_isdigit(argv[i][j]) == 0)
	{
		input = ft_split(argv[i], " ");
		if (!input)
			free(input);
	}
	else
	{
		/* TODO: on input les int SANS parser de ascii en int
		**	Cela n'est pas nécessaire, vu qu'on *SAIT*
		**	que c'est des int et pas du ascii
		*/
	}
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
	ft_printf("Arguments = %i \n", argc - 1);
	arg_parser(argc, argv);
}
