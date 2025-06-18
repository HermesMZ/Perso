/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzimeris <mzimeris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 17:32:46 by mzimeris          #+#    #+#             */
/*   Updated: 2025/03/04 17:32:52 by mzimeris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strdup(char *src)
{
	int		src_len;
	char	*copy;
	int		i;

	if (!src)
		return (NULL);
	src_len = 0;
	while (src[src_len])
		src_len++;
	copy = malloc(sizeof(char) * (src_len + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < src_len)
	{
		copy[i] = src[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
