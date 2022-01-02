/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_file_is_valid.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymoulou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 19:14:53 by aymoulou          #+#    #+#             */
/*   Updated: 2022/01/02 19:15:04 by aymoulou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	find(char *str, char *to_find)
{
	int	i;

	i = 0;
	while (to_find[i])
	{
		if (to_find[i] != str[i])
			return (0);
		i++;
	}
	if (str[i] == '\0')
		return (1);
	return (0);
}

void	check_file_is_valid(char *file_line)
{
	while (*file_line)
	{
		if (*file_line == '.')
		{
			if (find(file_line, ".ber"))
			{
				return ;
			}
		}
		file_line++;
	}
	printf("\033[1;31m🛑ERROR: file is not valid\033[0m");
	exit(1);
}
