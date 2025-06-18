/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MZimeris <MZimeris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 16:58:21 by MZimeris          #+#    #+#             */
/*   Updated: 2025/03/24 16:58:23 by MZimeris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_is_sort(int *tab, int length, int(*f)(int, int))
{
    int i;
    int order;

    if (length <= 1)
        return (1);
    order = f(tab[0], tab[1])
    i = 2;
    while (i < length)
    {
        if (order > 0 && f(tab[i - 1], tab[i]) < 0)
            return (0);
        if (order < 0 && f(tab[i - 1], tab[i]) > 0)
            return (0);
        if (f(tab[i - 1], tab[i]) != 0)
            order = f(tab[i - 1], tab[i]);
        i++;
    }
    return (1);
}