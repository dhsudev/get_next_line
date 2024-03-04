/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrevin- <ltrevin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 20:31:21 by ltrevin-          #+#    #+#             */
/*   Updated: 2024/03/04 10:16:54 by ltrevin-         ###   ########.fr       */
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
		
	}
	return (line)
	
}

char	*get_next_line(int fd)
{
	char	*buff;
	int		i;
	char	*pre;
	char	*line;

	// comprovar cositas
	 //TODO: reorganizar caos (prioridad 1)
	read(fd, buff, BUFFER_SIZE);
	buff = ft_strjoin(pre, buff); // unir lo que acabo de leer a lo que tenia anter
	if (ft_strchr(buff, '\n')) // comprobar si lo que tengo es devolvible
	{
		while (buff[i] != '\n')
			i++;
		ft_strlcpy(line, buff, i); // copiar lo que sirve
		i++;
		ft_strlcpy(pre, buff[i], ft_strlen(buff[i])); // guardar lo demas pa luego
		return (line);
	}
	else
	{
		// Guardar pa luego i seguir leyendo mas
		ft_strlcpy(pre, buff[i], ft_strlen(buff[i]));
		get_next_line(fd);
	}
}