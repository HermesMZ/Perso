/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MZimeris <MZimeris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 18:06:17 by MZimeris          #+#    #+#             */
/*   Updated: 2025/05/30 18:06:19 by MZimeris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*add_to_stash(char **stash, char *buffer)
{
	size_t	buffer_len;
	char	*new_stash;

	buffer_len = ft_strlen(buffer);
	if (buffer_len == 0)
		return (*stash);
	new_stash = ft_strjoin(*stash, buffer);
	if (!new_stash)
	{
		free(*stash);
		*stash = NULL;
		return (NULL);
	}
	free(*stash);
	*stash = new_stash;
	return (*stash);
}

static int	read_buffer(int fd, char **stash)
{
	char	*buffer;
	int		bytes;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (-1);
	while (ft_strchr(*stash, '\n') == NULL)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(buffer);
			free(*stash);
			*stash = NULL;
			return (-1);
		}
		if (bytes == 0)
			break ;
		buffer[bytes] = '\0';
		if (!add_to_stash(stash, buffer))
			return (-1);
	}
	free(buffer);
	return (1);
}

static char	*extract_line(char **stash)
{
	char	*line;
	char	*new_stash;
	size_t	line_len;
	size_t	stash_len;

	stash_len = ft_strlen(*stash);
	line_len = ft_strchr(*stash, '\n') - *stash + 1;
	line = ft_substr(*stash, 0, line_len);
	if (!line)
	{
		free (*stash);
		*stash = NULL;
		return (NULL);
	}
	new_stash = ft_substr(*stash, line_len, stash_len - line_len);
	if (!new_stash)
	{
		free (*stash);
		free (line);
		return (NULL);
	}
	free(*stash);
	*stash = new_stash;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*stash;

	if (fd < 0)
		return (NULL);
	if (!stash)
	{
		stash = ft_strdup("");
		if (!stash)
			return (NULL);
	}
	if (ft_strchr(stash, '\n'))
		return (extract_line(&stash));
	if (read_buffer(fd, &stash) == -1)
		return (NULL);
	if (!stash || ft_strlen(stash) == 0)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	return (extract_line(&stash));
}

#include <fcntl.h>
#include <sys/types.h>

int main(int ac, char **av)
{
	char	*str;

	if (ac == 1)
		return (1);
	int fd = open(av[1], O_RDONLY);
	if (fd < 0)
		return (1);
	while ((str = get_next_line(0)))
	{
		printf("%s", str);
		free(str);
	}
	close(fd);
	return (0);
}