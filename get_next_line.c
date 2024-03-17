/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrevin- <ltrevin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 15:45:30 by ltrevin-          #+#    #+#             */
/*   Updated: 2024/03/17 20:32:51 by ltrevin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "stdio.h"

char	*read_buff(int fd)
{
	char	*readed; 		// The readed chars
	int		bytes_read;		// The return of the read

	readed = malloc(BUFFER_SIZE * (sizeof(char)));
	if (!readed) // Malloc protec
		return (NULL);
	bytes_read = read(fd, readed, BUFFER_SIZE);
	if (bytes_read > 0) // Correct Read
	{
		return(readed);
	}
	free(readed);
	//if (bytes_read == 0) // EOF
	//{
	//	ft_strlcpy(readed, "\n", 2);
	//	return(readed);
	//}
	return(NULL);
}

char	*get_next_line(int fd)
{
	static char	*save;		// What i readed the last call
	char		*line; 		// The line that i will return
	char		*current;	// To save each read

	// Check valid filedescriptor and buffersize to prevent crash
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	current = read_buff(fd);
	//printf("First read: %s.\n", current);
	line = "";
	if(save)
		current = join_strs(save, current);
	save = "";
	while(search_nl(current) == -1 && current) // While not having nl 
	{
		//printf("return of the search_nl: %d\n", search_nl(line));
		line = join_strs(line, current);
		//printf("line: %s\n", line);
		current = read_buff(fd);
	}
	line = join_strs(line, current);
	save = ft_substr(line, search_nl(line)+1, ft_strlen(line));
	//printf("Saved 4 later: %s.\n", save);
	line = ft_substr(line, 0, search_nl(line));
	return(line);
}