/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MZimeris <MZimeris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 16:27:45 by MZimeris          #+#    #+#             */
/*   Updated: 2025/03/24 16:27:46 by MZimeris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int *ft_map(int *tab, int length, int(*f)(int))
{
    int *tmp;
    int i;

    if (!tab || length <= 0)
        return (NULL);
    tmp = (int *)malloc(sizeof(int) * (length));
    if (!tmp)
        return (NULL);
    i = 0;
    while (i < length)
    {
        tmp[i] = f(tab[i]);
        i++;
    }
    return (tmp);
}
