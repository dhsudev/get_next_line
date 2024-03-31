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

char *freeee(char **s){
	free(*s);
	*s = NULL;
	return(NULL);	
}
char	*read_buff(int fd)
{
	char	*readed; 		// The readed chars
	int		bytes_read;		// The return of the read

	readed = malloc(BUFFER_SIZE * (sizeof(char)+1));
	if (!readed){ // Malloc protec
		return (freeee(&readed));
	}
	bytes_read = read(fd, readed, BUFFER_SIZE);
	//printf("%s\n",readed);
	if (bytes_read > 0) // Correct Read
	{
		readed[bytes_read] = '\0';
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
	if(!current){
		return (NULL);
	}
	while(search_nl(current) == -1 && current) // While not having nl 
	{
		//printf("return of the search_nl with (%s): %d\n",current, search_nl(current));
		line = join_strs(line, current);
		//printf("line: %s\n", line);
		current = read_buff(fd);
	}
	//printf("return of the search_nl with (%s): %d\n",current, search_nl(current));
	//printf("final join %s. + %s.\n", line, current);
	save = ft_substr(current, search_nl(current)+1, ft_strlen(current));
	current = ft_substr(current, 0, search_nl(current)+1);
	line = join_strs(line, current);
	free(current);
	//printf("Saved 4 later: %s.\n", save);
	//line = ft_substr(line, 0, search_nl(line));
	return(line);
}