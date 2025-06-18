/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzimeris <mzimeris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 20:54:45 by mzimeris          #+#    #+#             */
/*   Updated: 2025/02/22 19:00:52 by mzimeris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	print_line(char first, char c, char last, int len);
void	ft_putchar(char c);

void	rush(int x, int y)
{
	int	index_line;

	if (x > 0 && y > 0)
	{
		index_line = 0;
		while (index_line <= y - 1)
		{
			if (index_line == y - 1 || index_line == 0)
			{
				print_line('A', 'B', 'C', x);
			}
			else
			{
				print_line('B', ' ', 'B', x);
			}
			index_line += 1;
		}
	}	
}

void	print_line(char first, char c, char last, int len)
{
	int	index_column;

	ft_putchar(first);
	index_column = 1;
	while (index_column <= len - 1)
	{
		if (index_column < len -1)
		{
			ft_putchar(c);
		}
		else
		{
			ft_putchar(last);
		}
		index_column += 1;
	}
	ft_putchar('\n');
}
