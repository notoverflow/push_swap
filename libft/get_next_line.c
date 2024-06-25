/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oliradet <oliradet@student.42perpignan.f>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 06:01:48 by oliradet          #+#    #+#             */
/*   Updated: 2024/04/05 00:52:46 by oliradet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * just search line
 * @param buf the buffer
 * @return the index of the first "\n", -1 if error
 */
int	search_newline(char *buf)
{
	int	i;

	i = -1;
	if (!buf)
		return (i);
	while (buf[++i])
	{
		if (buf[i] == '\n')
			return (i);
	}
	return (-1);
}

/**
 * update the buffer
 * @param buff the old buffer (with the actually line)
 * @return the new buff
 */
char	*clean_buff(char *buff)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	while (buff[i] != '\n' && buff[i] != '\0')
		i++;
	if (buff[i] == '\0')
	{
		free(buff);
		return (NULL);
	}
	res = (char *)malloc(sizeof(char) * (ft_strlenn(buff) - i + 1));
	if (!res)
		return (NULL);
	j = 0;
	i++;
	while (buff[i])
		res[j++] = buff[i++];
	res[j] = '\0';
	free(buff);
	return (res);
}

/**
 * take the file, and return a string of the first line
 * @param buff the file
 * @return the line
 */
char	*extract_line(char *buff)
{
	char	*line;
	int		line_size;
	int		i;

	line_size = 0;
	while (buff[line_size] != '\n' && buff[line_size] != '\0')
		line_size++;
	if (buff[line_size] == '\0')
	{
		if (line_size == 0)
			return (NULL);
		return (ft_strdup(buff));
	}
	i = 0;
	line_size++;
	line = (char *)malloc(sizeof(char) * (line_size + 1));
	if (!line)
		return (NULL);
	while (i < line_size)
	{
		line[i] = buff[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

/**
 * just fill the buffer, with the file
 * @param fd the file descriptor of the file
 * @param buff the buff to fill
 * @return
 */
char	*read_file(int fd, char *buff)
{
	char	*buf;
	int		readed;
	int		nl_index;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	readed = 1;
	nl_index = -1;
	while (readed > 0 && nl_index == -1)
	{
		readed = read(fd, buf, BUFFER_SIZE);
		if (readed == -1)
		{
			free(buf);
			free(buff);
			return (NULL);
		}
		buf[readed] = '\0';
		buff = ft_strjoingnl(buff, buf);
		nl_index = search_newline(buf);
	}
	free(buf);
	return (buff);
}

char	*get_next_line(int fd)
{
	static char	*buff[4096];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buff[fd])
		buff[fd] = ft_strdup("");
	buff[fd] = read_file(fd, buff[fd]);
	if (!buff[fd])
		return (NULL);
	line = extract_line(buff[fd]);
	buff[fd] = clean_buff(buff[fd]);
	return (line);
}
