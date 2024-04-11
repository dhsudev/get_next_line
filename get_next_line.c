/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrevin- <ltrevin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 15:45:30 by ltrevin-          #+#    #+#             */
/*   Updated: 2024/03/31 17:28:03 by ltrevin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "stdio.h"

void freeee(char *s){
	if (!s)
		return ;
	free(s);
	s = NULL;
}
char	*read_buff(int fd, char* save)
{
	char	*readed;
	int		bytes_read;

	readed = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!readed)
		return(NULL);
	bytes_read = read(fd, readed, BUFFER_SIZE);
	if (bytes_read > 0)
	{
		readed[bytes_read] = '\0';
		return(readed);
	}
	if(bytes_read == -1)
		freeee(save);
	freeee(readed);
	return(NULL);
}

char	*get_next_line(int fd)
{
	static char	*save = NULL;
	char		*line;
	char		*current;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	current = read_buff(fd, save);
	if(save)
		current = join_strs(save, current, 3);
	if(!current)
		return (NULL);
	line = malloc(sizeof(char) * 1);
	if (!line)
		return (freeee(current), NULL);
	line[0] = '\0';
	while(search_nl(current) == -1 && current)
	{
		line = join_strs(line, current, 1);
		//if 
		freeee(current);
		current = read_buff(fd, save);
	}
	save = ft_substr(current, search_nl(current) + 1, ft_strlen(current), 0);
	current = ft_substr(current, 0, search_nl(current) + 1, 1);
	line = join_strs(line, current, 1);
	freeee(current);
	if (line[0] == '\0')
		return (freeee(line), NULL);
	return(line);
}
