/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrevin- <ltrevin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 20:31:21 by ltrevin-          #+#    #+#             */
/*   Updated: 2024/02/26 16:38:57 by ltrevin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*buff;
	int		i;
	char	*pre;
	char	*line;

	// comprovar cositas
	
	// allocar memoria pal buff
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