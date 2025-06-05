/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admoufle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 13:44:39 by admoufle          #+#    #+#             */
/*   Updated: 2025/03/02 14:18:35 by mzimeris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH01_H
# define RUSH01_H

bool	check_views(char **tab, int *pos, int size);
bool	check_line(char **tab, int *pos, int size);
bool	check_double(char **tab, int *pos, int val, int size);
bool	is_empty(char c);
char	**cp_tab(char **tab, int x);
char	**create_tab(int x);
void	free_tab(char **tab);
void	print_tab(char **tab, int size);
int		check_input(char *str);
void	fill_view(char **tab, char *str, int x);
void	prefill(char **tab, int x);
bool	resolve(char **tab, int size, int *pos);

#endif /*RUSH01_H*/
