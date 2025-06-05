/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzimeris <mzimeris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 13:46:33 by mzimeris          #+#    #+#             */
/*   Updated: 2025/03/02 15:33:46 by admoufle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <unistd.h>
#include "rush01.h"

int	main(int argc, char **argv)
{
	int		nb;
	char	**tab;
	int		ret_val;

	if (argc != 2)
		return (write(2, "Error\n", 6), 1);
	nb = check_input(argv[1]);
	if (nb == -1)
		return (1);
	tab = create_tab(nb);
	if (!tab)
		return (write(2, "Error\n", 6), 1);
	fill_view(tab, argv[1], nb);
	prefill(tab, nb);
	ret_val = resolve(tab, nb, (int []){1, 1});
	if (!ret_val)
		write(2, "Error\n", 6);
	free_tab(tab);
	return (!ret_val);
}
