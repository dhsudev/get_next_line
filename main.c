/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrevin- <ltrevin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 18:04:42 by ltrevin-          #+#    #+#             */
/*   Updated: 2024/05/01 18:04:43 by ltrevin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h" 

int main(void)
{
	int    fd;
	char  *next_line = " ";
	int  count;

	count = 0;
	printf("Init program\n");
	fd = open("file.txt", O_RDONLY);
	printf("File open succes!\n");
	while (next_line){
		next_line = get_next_line(fd);
		printf("	Returned in [%d]: |%s|\n", count, next_line);
		// free(next_line);
		count++;
	}
	close(fd);
	return (0);
}

