/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymoulou <aymoulou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:17:50 by aymoulou          #+#    #+#             */
/*   Updated: 2022/01/02 19:40:00 by aymoulou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*get_line(char *backup)
{
	int		len;
	int		x;
	char	*line;

	len = 0;
	if (*backup == '\0')
		return (NULL);
	while (backup[len] && backup[len] != '\n')
		len++;
	if (backup[len] == '\n')
		len++;
	line = malloc(sizeof(char) * len + 1);
	if (!line)
		return (NULL);
	x = 0;
	while (x < len)
	{
		line[x] = backup[x];
		x++;
	}
	line[x] = '\0';
	return (line);
}

static char	*get_backup(char *backup)
{
	char	*str;
	int		start;
	int		i;

	start = 0;
	while (backup[start] && backup[start] != '\n')
		start++;
	if (backup[start] == '\n')
		start++;
	if (backup[start] == '\0')
	{
		free(backup);
		return (NULL);
	}
	str = malloc(sizeof(char) * (ft_strlen(backup) - start + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (backup[start])
		str[i++] = backup[start++];
	str[i] = '\0';
	free(backup);
	return (str);
}

static char	*read_line(char *backup, int fd)
{
	int		byte;
	char	*buff;

	buff = malloc(BUFFER_SIZE + 1 * sizeof(char));
	if (!buff)
		return (NULL);
	byte = 1;
	while (byte > 0 && ft_index(backup, '\n') == -1)
	{
		byte = read(fd, buff, BUFFER_SIZE);
		if (byte == 0)
			break ;
		if (byte == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[byte] = '\0';
		backup = ft_strjoin(backup, buff);
	}
	free(buff);
	return (backup);
}

char	*get_next_line(int fd)
{
	static char	*backup;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		exit(1);
		return (NULL);
	}
	backup = read_line(backup, fd);
	if (!backup)
		return (NULL);
	line = get_line(backup);
	backup = get_backup(backup);
	return (line);
}
