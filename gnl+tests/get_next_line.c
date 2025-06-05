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

static int	read_buffer(int fd, char **stash, char *buffer)
{
	char	*newline_pos;
	int		bytes;

	newline_pos = ft_strchr(*stash, '\n');
	while (newline_pos == NULL)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(*stash);
			*stash = NULL;
			return (-1);
		}
		if (bytes == 0)
			break ;
		buffer[bytes] = '\0';
		if (!add_to_stash(stash, buffer))
			return (-1);
		newline_pos = ft_strchr(*stash, '\n');
	}
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
	char		*buffer;

	if (!stash)
	{
		stash = ft_strdup("");
		if (!stash)
			return (NULL);
	}
	if (ft_strchr(stash, '\n'))
		return (extract_line(&stash));
	else
	{
		buffer = malloc(BUFFER_SIZE + 1);
		if (!buffer)
			return (NULL);
	}	
	if (read_buffer(fd, &stash, buffer) == -1)
		return (NULL);
	if (!stash || ft_strlen(stash) == 0)
	{
		free(buffer);
		free(stash);
		return (NULL);
	}
	free(buffer);
	return (extract_line(&stash));
}
