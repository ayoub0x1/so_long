/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymoulou <aymoulou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:18:11 by aymoulou          #+#    #+#             */
/*   Updated: 2022/01/02 19:40:36 by aymoulou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# define BUFFER_SIZE 42

char			*get_next_line(int fd);
char			*ft_strjoin(char *s1, char const *s2);
unsigned int	ft_strlen(const char *str);
int				ft_index(const char *s, char c);
char			*ft_strdup(const char *s1);

#endif
