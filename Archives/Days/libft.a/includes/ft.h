/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzimeris <mzimeris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 21:16:38 by mzimeris          #+#    #+#             */
/*   Updated: 2025/03/10 21:20:39 by mzimeris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

int     ft_atoi(char *str);
void	ft_putchar(char c);
void	ft_putnbr(int nb);
void	ft_putstr(char *str);
void	ft_sort_int_tab(int *tab, int size);
char	**ft_split(char *str, char *charset);
char	*ft_strcat(char *dest, char *src);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strdup(char *src);
char	*ft_strjoin(int size, char **strs, char *sep);
int		ft_strlen(char *str);
char	*ft_strndup(char *str, int size);
void	ft_swap(int *a, int *b);

#endif /*FT_H*/
