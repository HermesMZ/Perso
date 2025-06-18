/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzimeris <mzimeris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 19:54:45 by mzimeris          #+#    #+#             */
/*   Updated: 2025/02/25 15:02:37 by mzimeris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

//char	*ft_strcapitalize(char *str);
int	is_alpha_num(char c);
int	is_lower(char c);
int	is_up(char c);
/*
int	main(void)
{
	char	str[100] = "salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un";
	ft_strcapitalize(str);
	printf("%s\n", str);
	return (0);
}
*/

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 1;
	if (is_lower(str[0]))
		str[0] -= 32;
	while (str[i] != '\0')
	{
		if (is_alpha_num(str[i]) == 1 && is_alpha_num(str[i - 1]) == 1)
		{
			if (is_up(str[i]))
			{
				str[i] += 32;
			}
		}
		if (is_alpha_num(str[i]) == 1 && is_alpha_num(str[i - 1]) == 0)
		{
			if (is_lower(str[i]))
			{
			str[i] -= 32;
			}
		}
	i++;
	}
	return (str);
}

int	is_lower(char c)
{
	if (c > 'a' && c < 'z')
		return (1);
	return (0);
}

int	is_up(char c)
{
	if (c > 'A' && c < 'Z')
		return (1);
	return (0);
}

int	is_alpha_num(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	else if (c >= 'A' && c <= 'Z' )
		return (1);
	else if (c >= '0' && c <= '9' )
		return (1);
	else
		return (0);
}
