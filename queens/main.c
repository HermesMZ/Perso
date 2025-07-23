/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzimeris <mzimeris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 18:10:27 by mzimeris          #+#    #+#             */
/*   Updated: 2025/07/23 18:42:17 by mzimeris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queens.h"

int	main(int argc, char *argv[])
{
	int	*table;
	int	size;

	if (argc != 2)
		return (1);
	size = ft_atoi(argv[1]);
	if (size < 1)
		return (2);
	table = init_table(size);
	if (!table)
		return (1);
	n_queens(table, size);
	return (0);
}
