/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoure <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 12:01:20 by apoure            #+#    #+#             */
/*   Updated: 2022/12/21 15:30:00 by apoure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*FT_READ_FIRST_STR
*	-----------------
*	DESCRIPTION
*	Takes the opened file descriptor and saves on a "buff" variable what readed
*	from it. Then joins it to the cumulative static variable for the persistence
*	of the information.
*	PARAMETERS
*	#1. A file descriptor.
*	#2. The pointer to the cumulative static variable from previous runs of
*	get_next_line.
*	RETURN VALUES
*	The new static variable value with buffer joined for the persistence of the info,
*	or NULL if error.*/
char	*ft_read_first_str(int fd, char *first_str)
{
	char	*buff;
	int		rdd_bytes;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	rdd_bytes = 1;
	while (!ft_strchr(first_str, '\n') && rdd_bytes != 0)
	{
		rdd_bytes = read(fd, buff, BUFFER_SIZE);
		if (rdd_bytes == -1)
		{
			free (buff);
			return (NULL);
		}
		buff[rdd_bytes] = '\0';
		first_str = ft_strjoin(first_str, buff);
	}
	free (buff);
	return (first_str);
}
/*GET_NEXT_LINE
*	-------------
*	DESCRIPTION
*	This function takes an opened file descriptor and returns its next line.
*	This function has undefined behavior when reading from a binary file.
*	PARAMETERS
*	#1. A file descriptor 
*	RETURN VALUES
*	If successful, get_next_line returns a string with the full line ending in
*	a line break (`\n`) when there is one. 
*	If an error occurs, or there's nothing more to read, it returns NULL.*/
char	*get_next_line(int fd)
{
	char		*line;
	static char	*first_str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	first_str = ft_read_first_str(fd, first_str);
	if (!first_str)
		return (NULL);
	line = ft_get_line(first_str);
	first_str = ft_new_first_str(first_str);
	return (line);
}

int	main(void)
{
	char	*line;
	int		i;
	int		fd1;

	fd1 = open ("test.txt", O_RDONLY);
	i = 0;
	while (i < 5)
	{
		line = get_next_line(fd1);
		printf("line %d :%s", i, line);
		free (line);
		i++;
	}
	close (fd1);
	return (0);
}
