/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bimartin <bimartin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 11:53:26 by bimartin          #+#    #+#             */
/*   Updated: 2022/10/25 11:57:15 by bimartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

/*=-=-=-=-=-=-=-=-=-=-=-=-=-=-[include <>]-=-=-=-=-=-=-=-=-=-=-=-=-=-=*/
# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>
# include <stdlib.h>

# include <stdio.h>
/*=-=-=-=-=-=-=-=-=-=-=-=-=-=-[functions]-=-=-=-=-=-=-=-=-=-=-=-=-=-=*/

char		*get_next_line(int fd);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_strchr(const char *s, int c);
void		*ft_bzero(void *b, size_t len);
void		*ft_calloc(size_t count, size_t size);
size_t		ft_strlen(const char *str);
char		*join_free(char *buf, char *file);
char		*del_line(char *buffer);
char		*next_line(char *buffer);
char		*read_file(int fd, char *buf);

#endif