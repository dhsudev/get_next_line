/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrevin- <ltrevin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 20:31:21 by ltrevin-          #+#    #+#             */
/*   Updated: 2024/03/04 10:20:33 by ltrevin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(int fd, char *str)
{
	char	*buff;
	int		by_read;
	char	*line;
	int 	i;
	
	buff = malloc(sizeof(char)*(BUFFER_SIZE+1));
	//chech valid filedescriptor & buffersize
	// si al read le pongo 0 no lee pero puedo comprobar si el fd es valid
	if(fd < 0 || read(fd, buff, 0) < 0 || BUFFER_SIZE < 0)
		return (0);
	//check if line
	if(!str)
		return (NULL); // creo???
	
	// not sense rn pero lo tendra :'3
	while (!(ft_strchr(str, '\n'))) // read until tengo salto de linea
	{
		if(by_read = read(fd, buff, BUFFER_SIZE) < 0) // petao
			return (0);
		while (buff[i] != '\n')
			i++;
		ft_strlcpy(line, buff, i); // copiar lo que sirve
		i++;
		ft_strlcpy(str, buff[i], ft_strlen(buff[i])); // guardar lo demas pa luego
		return (line);
	}
	return (line)
}

char	*get_next_line(int fd)
{
	// comprovar cositas
	//TODO: reorganizar caos (prioridad 1) mirar como y cuando hay q llamar a ft_read
	// - intentar entender el bonus? se lo que hace pero no cómo 
	// - clean ft_read
	// - main to start checking things!
}