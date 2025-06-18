/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzimeris <mzimeris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 22:20:19 by mzimeris          #+#    #+#             */
/*   Updated: 2025/03/10 23:02:08 by mzimeris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

void free_struct(struct s_stock_str *stock) {
    int i;

	i = 0;
    if (stock == NULL)
        return;
    while (stock[i].str != NULL)
	{
		free(stock[i].str);
        free(stock[i].copy);
        i++;
    }
    free(stock);
}

char	*ft_strndup(char *str, int size)
{
	char *temp;
	int	i;

	if (!str)
		return (NULL);
	temp = malloc(sizeof(char) * size + 1);
	if (!temp)
		return (NULL);
	i = 0;
	while (i < size)
		temp[i] = str[i++];
	temp[i] = '\0';
	return (temp);
}

struct s_stock_str *create_stock(int size)
{
	struct s_stock_str *stock;

	if (!size)
		return (NULL);
	stock = malloc(sizeof(struct s_stock_str) * (size + 1));
	if (!stock)
		return (NULL);
	return (stock);
}

struct s_stock_str *ft_strs_to_tab(int ac, char **av)
{
	int i;
	int j;
	struct s_stock_str *stock;
	
	i = 0;
	j = 0;
	stock = create_stock(ac);
	if (!stock)
		return (NULL);
	while (i < ac)
	{
		while (av[i][j])
			j++;
			stock[i].size = j;
			stock[i].str = ft_strndup(av[i], j);
			stock[i].copy = ft_strndup(av[i], j);
		j = 0;
		i++;
	}
	stock[i].str = NULL;
    stock[i].copy = NULL;
	return (stock)
}
