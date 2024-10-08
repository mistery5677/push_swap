/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mistery576 <mistery576@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 14:37:51 by miafonso          #+#    #+#             */
/*   Updated: 2024/07/11 01:21:06 by mistery576       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*str;
	int		j;
	int		i;

	i = -1;
	if (!s1)
	{
		s1 = malloc(sizeof(char) + 1);
		if (!s1)
			return (0);
		s1[0] = 0;
	}
	str = malloc(((ft_strlen(s1) + ft_strlen(s2)) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (s1[++i])
		str[i] = s1[i];
	j = -1;
	while (s2[++j])
		str[i + j] = s2[j];
	str[i + j] = '\0';
	free(s1);
	return (str);
}

char	*update_buffer(char *buffer)
{
	char	*next_line;
	size_t	end;
	size_t	i;

	end = 0;
	i = 0;
	while (buffer[end] && buffer[end] != '\n')
		end++;
	if (buffer[end] == '\n')
		end++;
	next_line = malloc((ft_strlen(buffer) - end + 1) * sizeof(char));
	if (!next_line)
		return (free(buffer), NULL);
	while (buffer[end + i])
	{
		next_line[i] = buffer[end + i];
		i++;
	}
	next_line[i] = '\0';
	if (!next_line[0])
		return (free(buffer), free(next_line), NULL);
	return (free(buffer), next_line);
}

char	*get_line(char *buffer)
{
	char	*new_str;
	char	*end;
	size_t	i;

	end = ft_strchr(buffer, '\n');
	i = (ft_strlen(buffer) - ft_strlen(end)) + 1;
	new_str = ft_substr(buffer, 0, i);
	if (!new_str)
		return (NULL);
	return (new_str);
}

char	*scan_fd(char *str, int fd)
{
	char	*buffer;
	int		bytes;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	buffer[0] = '\0';
	bytes = 1;
	while (bytes > 0 && !ft_strchr(buffer, '\n'))
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes > 0)
		{
			buffer[bytes] = '\0';
			str = ft_strjoin_gnl(str, buffer);
		}
	}
	free(buffer);
	if (bytes == -1)
	{
		free(str);
		return (NULL);
	}
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = scan_fd(buffer, fd);
	if (!buffer)
		return (NULL);
	str = get_line(buffer);
	buffer = update_buffer(buffer);
	return (str);
}
