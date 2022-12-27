/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoure <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 13:20:04 by apoure            #+#    #+#             */
/*   Updated: 2022/12/21 14:41:52 by apoure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	int		i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int		i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *first_str, char *buff)
{
	size_t		i;
	size_t		j;
	char		*str;

	if (!first_str)
	{
		first_str = (char *)malloc (1 * sizeof(char));
		first_str[0] = '\0';
	}
	if (!first_str || !buff)
		return (NULL);
	str = (char *)malloc (sizeof(*str)
			* (ft_strlen(first_str) + ft_strlen(buff) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (first_str)
		while (first_str[++i] != '\0')
			str[i] = first_str[i];
	while (buff[j] != '\0')
		str[i++] = buff[j++];
	str[ft_strlen(first_str) + ft_strlen(buff)] = '\0';
	free (first_str);
	return (str);
}
/*GET_LINE
*	---------
*	Extracts the line (ending in either line break and `\0` or only `\0` in EOF)
*	from static variable.
*	PARAMETERS
*	#1. The pointer to the cumulative static variable from previous runs of get_next_line.
*	RETURN VALUES
*	The string with the full line ending in a line break (`\n`) + (`\0`).*/
char	*ft_get_line(char *first_str)
{
	int		i;
	char	*str;

	i = 0;
	while (!first_str[i])
		return (NULL);
	while (first_str[i] && first_str[i] != '\n')
		i++;
	str = (char *)malloc (sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (first_str[i] && first_str[i] != '\n')
	{
		str[i] = first_str[i];
		i++;
	}
	if (first_str[i] == '\n')
	{
		str[i] = first_str[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
/*FIRST_NEW_STR
*	-------------
*	Stores in the cumulative static variable the new updated variable with whatever
*	is left from the original, minus the line extracted.
*	PARAMETERS
*	#1. The pointer to the cumulative static variable from previous runs of get_next_line.
*	RETURN VALUES
*	The new updated string with whatever is left from the original static, minus the
*	line extracted.*/
char	*ft_new_first_str(char *first_str)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (first_str[i] && first_str[i] != '\n')
		i++;
	if (!first_str[i])
	{
		free (first_str);
		return (NULL);
	}
	str = (char *)malloc (sizeof(char) * (ft_strlen(first_str) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (first_str[i])
		str[j++] = first_str[i++];
	str[j] = '\0';
	free (first_str);
	return (str);
}
