/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bimartin <bimartin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 12:15:43 by bimartin          #+#    #+#             */
/*   Updated: 2022/10/25 11:45:23 by bimartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ptr_free(char **ptr)
{
	free(*ptr);
	*ptr = NULL;
	return (NULL);
}

char	*del_line(char *buffer)
{
	int		i;
	int		j;
	char	*next;

	i = 0;
	j = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	next = ft_calloc(ft_strlen(buffer) - i + 1, sizeof(char));
	if (!next)
	{
		free(buffer);
		return (NULL);
	}
	i++;
	while (buffer[i])
		next[j++] = buffer[i++];
	free(buffer);
	return (next);
}

char	*next_line(char *buffer)
{
	int		i;
	char	*line;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] != '\0' || buffer[i] == '\n')
	{
		line[i++] = '\n';
	}
	return (line);
}

char	*read_file(int fd, char *buf)
{
	char	*file;
	int		size;

	file = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!file)
		return (ptr_free(&buf));
	size = 1;
	while (size > 0 && !ft_strchr(file, '\n'))
	{
		size = read(fd, file, BUFFER_SIZE);
		if (size == -1)
		{
			free (file);
			return (ptr_free(&buf));
		}
		if (size > 0)
		{
			file[size] = '\0';
			buf = ft_strjoin(buf, file);
			if (!buf)
				return (ptr_free(&file));
		}
	}
	free(file);
	return (buf);
}

char	*get_next_line(int fd)
{
	static char	*buffer = NULL;
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	if (!buffer || (buffer && !ft_strchr(buffer, '\n')))
		buffer = read_file(fd, buffer);
	if (!buffer)
	{
		return (NULL);
	}
	line = next_line(buffer);
	if (!line)
	{
		ptr_free(&buffer);
		buffer = NULL;
		return (NULL);
	}
	buffer = del_line(buffer);
	if (!buffer)
	{
		ptr_free(&buffer);
		buffer = NULL;
	}
	return (line);
}

// int	main(void)
// {
// 	int		fd;
// 	char	*temp;

// 	fd = open("./test", O_RDONLY);
// 	temp = get_next_line(fd);
// 	printf("LINIA 1: %s", temp);
// 	free(temp);
// 	temp = get_next_line(fd);
// 	printf("LINIA 2: %s", temp);
// 	free(temp);
// 	close(fd);
// 	printf("%i\n", fd);
// 	do
// 	{
// 		temp = get_next_line(fd);
// 		free(temp);
// 	} while (temp != NULL);
// 	close(fd);
// 	fd = open("./test", O_RDONLY);
// 	temp = get_next_line(fd);
// 	printf("LINIA 3: %s", temp);
// 	free(temp);
// 	temp = get_next_line(fd);
// 	printf("LINIA 4: %s", temp);
// 	free(temp);
// 	temp = get_next_line(fd);
// 	printf("LINIA 5: %s", temp);
// 	free(temp);
// 	return (0);
// }