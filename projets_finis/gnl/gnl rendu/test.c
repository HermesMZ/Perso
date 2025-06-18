/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MZimeris <MZimeris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 18:05:58 by MZimeris          #+#    #+#             */
/*   Updated: 2025/05/30 18:06:01 by MZimeris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>         // Pour printf
#include <fcntl.h>         // Pour open
#include <unistd.h>        // Pour close et read

// clear && cc -Wall -Wextra -Werror *.c -g3 -D BUFFER_SIZE=3000 && valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all ./a.out get_next_line.c


int	main(int argc, char **argv)
{
	int		fd;
	char	*line;

	if (argc != 2)
	{
		printf("Usage: %s <filename>\n", argv[0]);
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	printf("\ndebug ============ fd : %d ============\n", fd);
	if (fd == -1)
	{
		perror("Error opening file");
		return (1);
	}
	printf("--- Reading lines from %s ---\n", argv[1]);
	line = get_next_line(fd);
	while ((line) != NULL)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	if (line == NULL)
		printf("\n--- End of file or error ---\n");

	close(fd);
	return (0);
}
