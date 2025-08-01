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

#include "get_next_line_bonus.h"

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
	static char	*stash[MAX_FD];

	if (fd < 0 || fd >= MAX_FD)
		return (NULL);
	if (!stash[fd])
	{
		stash[fd] = ft_strdup("");
		if (!stash[fd])
			return (NULL);
	}
	if (ft_strchr(stash[fd], '\n'))
		return (extract_line(&stash[fd]));
	if (read_buffer(fd, &stash[fd]) == -1)
		return (NULL);
	if (!stash[fd] || ft_strlen(stash[fd]) == 0)
	{
		free(stash[fd]);
		stash[fd] = NULL;
		return (NULL);
	}
	return (extract_line(&stash[fd]));
}
