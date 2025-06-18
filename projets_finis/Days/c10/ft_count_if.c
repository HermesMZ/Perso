/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MZimeris <MZimeris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 16:52:19 by MZimeris          #+#    #+#             */
/*   Updated: 2025/03/24 16:52:21 by MZimeris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_count_if(char **tab, int length, int(*f)(char*))
{
    int i;
    int count;

    i = 0;
    count = 0;
    if (!tab || length <= 0)
        return (0);
    while (i < length)
    {
        if (f(tab[i++]))
            count++;
    }
    return (count);
}