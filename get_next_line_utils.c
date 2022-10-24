/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bimartin <bimartin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 13:10:31 by bimartin          #+#    #+#             */
/*   Updated: 2022/10/19 17:25:35 by bimartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	char	*ptr;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	ptr = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	i = -1;
	j = 0;
	while (s1[++i])
		ptr[j++] = s1[i];
	i = -1;
	while (s2[++i])
		ptr[j++] = s2[i];
	ptr[j] = '\0';
	return (ptr);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	ch;
	char	*str;

	str = (char *)s;
	ch = (char)c;
	i = 0;
	while (str[i] != ch)
	{
		if (str[i] == '\0')
			return (NULL);
		i++;
	}
	return (str + i);
}

void	*ft_bzero(void *b, size_t len)
{
	int	i;

	i = 0;
	while (i < (int)len)
	{
		((unsigned char *)b)[i] = 0;
		i++;
	}
	return (b);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = (void *)malloc(count * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, size * count);
	return (ptr);
}

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
