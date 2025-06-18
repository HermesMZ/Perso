/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzimeris <mzimeris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 20:54:45 by mzimeris          #+#    #+#             */
/*   Updated: 2025/02/22 16:23:28 by mzimeris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	print_line(char end, char c, int len);
void	ft_putchar(char c);

void	rush(int x, int y)
{
	int	index_line;

	if (x > 0 && y > 0)
	{
		print_line('A', 'B', x);
		index_line = 1;
		while (index_line <= y - 1)
		{
			if (index_line < y - 1)
			{
				print_line('B', ' ', x);
			}
			else
			{
				print_line('C', 'B', x);
			}
			index_line += 1;
		}
	}	
}

void	print_line(char end, char c, int len)
{
	int	index_column;

	index_column = 0;
	while (index_column <= len - 1)
	{
		if (index_column == 0 || index_column == len -1)
		{
			ft_putchar(end);
		}
		else
		{
			ft_putchar(c);
		}
		index_column += 1;
	}
	ft_putchar('\n');
}
