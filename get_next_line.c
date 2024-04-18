/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrevin- <ltrevin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:36:35 by ltrevin-          #+#    #+#             */
/*   Updated: 2024/04/18 19:39:19 by ltrevin-         ###   ########.fr       */
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
		printf("[%d] - '%s'\n", i, temp->content);
		i++;
		temp = temp->next;
	}
}

int	has_nl(t_list **lst)
{
	int		i;
	t_list	*temp;

	temp = *lst;
	while (temp)
	{
		i = 0;
		while (temp->content[i] != '\0')
		{
			if (temp->content[i] == '\n')
				return (1);
			i++;
		}
		temp = temp->next;
	}
	return (0);
}

char	*next_line(int fd, t_list **lst)
{
	char	readed[BUFFER_SIZE + 1];
	char	*line;
	int		b_read;

	readed[BUFFER_SIZE] = '\0';
	// readed = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	b_read = read(fd, readed, BUFFER_SIZE);
	lstadd_back(lst, lstnew(readed));
	lst_show(lst);
	while (b_read > 0 && !has_nl(lst))
	{
		b_read = read(fd, readed, BUFFER_SIZE);
		if (b_read < 0)
			break ;
		readed[b_read] = '\0';
		printf("-------------------------|%s|%d|\n", readed, b_read);
		lstadd_back(lst, lstnew(readed));
		// printf("byts readed: %d\n", b_read);
		lst_show(lst);
	}
	//save_line(lst, line);
	//clean_lst(lst);
	line = "";
	return (line);
}

char	*get_next_line(int fd)
{
	char			*line;
	static t_list	*lst;

	printf("Starting the reads\n");
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	line = next_line(fd, &lst);
	return (line);
}






