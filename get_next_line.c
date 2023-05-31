/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clima-fr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 11:16:16 by clima-fr          #+#    #+#             */
/*   Updated: 2023/05/31 11:16:30 by clima-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
    int     i = 0;
    int     rd = 0;
    char    character;
    char    *buffer = malloc(100000);
    
    if (BUFFER_SIZE <= 0)
        return (NULL);
    while ((rd = read(fd, &character, BUFFER_SIZE - BUFFER_SIZE + 1)) > 0)
    {
        buffer[i++] = character;
        if (character == '\n')
            break ;
    }
    buffer[i] =  '\0';
    if (rd == -1 || i == 0 || (!buffer[i - 1] && !rd))
        return (free(buffer), NULL);
    return(buffer);
}

#include <fcntl.h>
#include <stdio.h>
int	main(int argc, char **argv)
{
	int		fd;
	int		line;
	char	*string;

	line = 1;
	string = NULL;
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		string = get_next_line(fd);
		while (string != NULL)
		{
			printf("Line %d - %s ", line, string);
			string = get_next_line(fd);
			line++;
		}
		if (!string)
			printf("Line %d - (null) EOF", line);
		close(fd);
	}
	return (0);
}
