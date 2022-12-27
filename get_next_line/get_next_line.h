/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoure <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 13:11:42 by apoure            #+#    #+#             */
/*   Updated: 2022/12/21 13:19:27 by apoure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

size_t	ft_strlen(char *str);
char	*get_next_line(int fd);
char	*ft_strjoin(char *first_str, char *buff);
char	*ft_strchr(char *s, int c);
char	*ft_get_line(char *first_str);
char	*ft_new_first_str(char *first_str);
char	*ft_read_first_str(int fd, char *first_str);
#endif
