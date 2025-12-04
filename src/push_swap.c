/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinheir@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 14:59:18 by rpinheir          #+#    #+#             */
/*   Updated: 2025/12/04 19:49:24 by rpinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** @brief Parse les arguments de la ligne de commande
** @param argc Nombre d'arguments passes au programme
** @param argv Tableau de chaines contenant les arguments
** @return int (a implementer: code de retour)
** @note `argc` inclut le nom du programme (argv[0]),
** donc argc - 1 = nombre d'arguments reels
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
** @brief Point d'entree du programme push_swap
** @param argc Nombre d'arguments (incluant le nom du programme)
** @param argv Tableau de chaines des arguments
** @return int 0 si succes, 1 si erreur
** @see arg_parser() pour le parsing des arguments
** @warning Les arguments doivent etre des entiers valides
** @example ./push_swap 3 2 1
*/
int	main(int argc, char **argv)
{
	ft_printf("Arguments = %i \n", argc - 1);
	arg_parser(argc, **argv);
}
