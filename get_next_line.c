/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrevin- <ltrevin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 12:13:30 by ltrevin-          #+#    #+#             */
/*   Updated: 2024/03/04 12:24:07 by ltrevin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_line(int fd, char **saved)
{
	// Read from file (check if it fails)
	// Append the current read to what i had
	// Check if newLine or EOF
		// Save the rest in "saved" for later (idk if do it here or in get_next_line)
		// Substring the line until newLine or EOF
	// Return the line that i readed
}


char	*get_next_line(int fd)
{
	//Main Logic:
	// Precheck if fd is valid
	// Read line from file with read_line until newLine or EOF
		// read_line
		// save readed for next read (idk if do it here or in read_line)
	// Return line

	// TODO but idk where rn:
		// Decide if i clean the line & save the rest in get_next_line or in read_line 
			// (change declaration of read_line if is in gnl)
		// Check if the read fails
		// Check if EOF
		// Handle multiple file descriptors (i thinks that my logic will do it?)
	// TODO: write a main to check with multiple fd and not only files (4example stdinput?)
}