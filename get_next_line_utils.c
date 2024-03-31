/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrevin- <ltrevin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 20:30:01 by ltrevin-          #+#    #+#             */
/*   Updated: 2024/03/31 17:27:48 by ltrevin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "stdio.h"

int	search_nl(const char *s)
{
	size_t		i;

	//printf("Searching in %s.\n", s);
	if (!s)
		return (-1);
	i = 0;
	while (s[i])
	{
		if (s[i] == '\n' || s[i] == EOF)
			return (i);
		i++;
	}
	//if (s[i] == '\n' || s[i] == EOF)
	//		return (i);
	return (-1);
}

char	*join_strs(char *s1, char *s2)
{
	char	*join;
	size_t	s1len;
	size_t	s2len;

	//printf("Starting join...\n");
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	join = malloc(sizeof(char) * (s1len + s2len + 1));
	if (!join)
		return (NULL);
	ft_strlcpy(join, s1, s1len+1);
	if(s2)
		ft_strlcpy(join + s1len, s2, s2len + 1);
	//printf("joined s1: %s. s2: %s. result: %s.\n", s1, s2, join);
	//free(s1);
	return (join);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	src_size;

	i = 0;
	src_size = ft_strlen(src);
	if (size != 0)
	{
		while (src[i] != '\0' && i < size - 1)
		{
			dest[i] = src[i];
			i ++;
		}
		dest[i] = '\0';
	}
	return (src_size);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;
	
	i = 0;
	if(!s)
		return(0);
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	slen;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (slen <= start)
	{
		sub = malloc(ft_strlen("") * (sizeof(char) + 1));
		if (!sub)
			return (NULL);
		ft_strlcpy(sub, "", ft_strlen("") + 1);
		return (sub);
	}
	if (len > (slen - start))
		len = slen - start;
	sub = malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	ft_strlcpy(sub, s + start, len + 1);
	return (sub);
}
