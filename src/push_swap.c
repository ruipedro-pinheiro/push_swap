/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinheir@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 14:59:18 by rpinheir          #+#    #+#             */
/*   Updated: 2025/12/08 13:20:55 by rpinheir         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

/*
** @brief Parse les arguments de la ligne de commande
** @param argc Nombre d'arguments passes au programme
** @param argv Tableau de chaines contenant les arguments
** @return int (a implementer: code de retour)
** @note `argc` inclut le nom du programme (argv[0]),
** donc argc - 1 = nombre d'arguments reels
*/
void	arg_parser(char **argv)
{
	int			i;
	int			x;
	int			y;
	long long	output;
	char		**input;

	i = 1;
	x = 0;
	y = 0;
	output = 0;
	while (argv[i][i])
	{
		if (ft_isdigit(argv[1][i]) == 0)
		{
			input = ft_split(argv[1], ' ');
			if (!input)
				free(input);
			if (ft_atoll(&input[x][0] < INT_MIN
				|| ft_atoll(&input[x][0] > INT_MAX)
				ft_putendl_fd("Error", 1);
			while (input[x][y])
			{
				##node_in_stack = ft_atoll(&input[x][0]);
				x++;
			}
		}
		else
		{
		}
	}
}

/*
** @brief Point d’entrée du programme push_swap
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
