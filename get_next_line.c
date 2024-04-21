/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrevin- <ltrevin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:36:35 by ltrevin-          #+#    #+#             */
/*   Updated: 2024/04/21 19:02:46 by ltrevin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

void	lst_show(t_list **lst)
{
	t_list	*temp;
	int		i;

	i = 0;
	temp = *lst;
	while (temp != NULL)
	{
		//printf("[%d] - |%s|\n", i, temp->content);
		i++;
		temp = temp->next;
	}
}

int	has_nl(t_list **lst, int *line_size)
{
	int		i;
	t_list	*temp;

	temp = *lst;
	*line_size = 0;
	while (temp)
	{
		i = 0;
		while (temp->content[i] != '\0')
		{
			if (temp->content[i] == '\n')
			{
				*line_size += i + 1;
				return (1);
			}
			i++;
		}
		temp = temp->next;
		*line_size += BUFFER_SIZE;
	}
	return (0);
}
char	*save_line(t_list **lst, int line_size)
{
	int		i;
	int		j;
	t_list	*temp;
	char	*line;

	temp = *lst;
	j = 0;
	//printf("Creating line size: %d\n",line_size);
	line = malloc((line_size + 1) * sizeof(char*));
	while (temp && j < line_size)
	{
		i = 0;
		while (temp->content[i] != '\0' && j < line_size)
		{
			//printf("->%c\n", temp->content[i]);
			line[j] = temp->content[i];
			i++;
			j++;
		}
		temp = temp->next;
	}
	if(j==0)
		return NULL;
	line[j] = '\0';
	//printf("Line created: |%s|\n", line);
	//printf("j:%d\n", j);
	return (line);
}
char	*next_line(int fd, t_list **lst)
{
	char	readed[BUFFER_SIZE + 1];
	char	*line;
	int		b_read;
	int		line_size;

	readed[BUFFER_SIZE] = '\0';
	// readed = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	b_read = 1;
	line_size = 0;
	while (b_read > 0 && !has_nl(lst, &line_size))
	{
		b_read = read(fd, readed, BUFFER_SIZE);
		if (b_read < 0)
			break ;
		readed[b_read] = '\0';
		//printf("Read: |%s| bytes: %d\n", readed, b_read);
		lstadd_back(lst, lstnew(readed));
		// printf("byts readed: %d\n", b_read);
		lst_show(lst);
	}
	line = save_line(lst, line_size);
	if(line)
		clean_lst(lst, line_size);
	//line = "";
	return (line);
}

char	*get_next_line(int fd)
{
	char			*line;
	static t_list	*lst;

	//printf("Starting the reads\n");
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	line = next_line(fd, &lst);
	return (line);
}






