/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrevin- <ltrevin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 12:13:30 by ltrevin-          #+#    #+#             */
/*   Updated: 2024/03/11 17:45:47 by ltrevin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_line(int fd)
{
	char	*readed;
	int		bytes_read;

	readed = malloc(BUFFER_SIZE * sizeof(char));
	if (!readed)
		return (NULL);
	bytes_read = read(fd, readed, BUFFER_SIZE);
	if (bytes_read > 0)
		return (readed);
	if(bytes_read == 0)// TODO: Do smthg with the EOF
		bytes_read = 0;
	free(readed);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*current;
	char		*line;
	int			index_nl;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	current = read_line(fd);
	if (!current)
		return (NULL);
	while (search_nl(line) == -1 && current)
	{
		current = read_line(fd);
		if (!current)
			return (NULL);
		index_nl = search_nl(current);
		if (index_nl > 0)
		{
			save = ft_substr(current, index_nl + 1, ft_strlen(current));
			if (!save)
				return (NULL);
			line = join_strs(line, ft_substr(line, 0, index_nl - 1));
			if (!line)
				return (NULL);
			break ;
			
		}
		line = join_strs(line, current);
	}
	if (!line)
		return (NULL);
	return (line);
}
