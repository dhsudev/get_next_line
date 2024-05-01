/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrevin- <ltrevin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:36:37 by ltrevin-          #+#    #+#             */
/*   Updated: 2024/04/29 14:54:22 by ltrevin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <string.h>

void	lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	temp = *lst;
	while (temp && temp->next)
		temp = temp->next;
	temp->next = new;
	//printf("|%p|%p|\n", (*lst)->content, (*lst)->next->content);
}

t_list	*lstnew(void *content)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = strdup(content);
	node->next = NULL;
	return (node);
}
// char	*ft_strdup(const char *s1)
// {
// 	char	*s2;
// 	size_t	size;

// 	size = ft_strlen(s1);
// 	s2 = malloc(size * sizeof(char) + 1);
// 	if (!s2)
// 		return (NULL);
// 	ft_strlcpy(s2, s1, size + 1);
// 	return (s2);
// }
void	clean_lst(t_list **lst)
{
	t_list	*tmp;

	while (*lst)
	{
		tmp = (**lst).next;
		free((**lst).content);
		free(*lst);
		*lst = tmp;
	}
	free(*lst);
	*lst = NULL;
}


