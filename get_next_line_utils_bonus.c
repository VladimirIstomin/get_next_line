/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmerlene <gmerlene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 13:46:35 by gmerlene          #+#    #+#             */
/*   Updated: 2021/10/09 17:34:43 by gmerlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

static char	*concat_strings(char *space, char *str1, char *str2)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str1 && str1[i])
	{
		space[i] = str1[i];
		i++;
	}
	while (str2 && str2[j] && str2[j - 1] != '\n')
	{
		space[i + j] = str2[j];
		j++;
	}
	space[i + j] = '\0';
	return (space);
}

char	*add_to_line(char *str, char *str_buff)
{
	int		len_str;
	int		len_buff;
	char	*new_str;

	len_str = ft_strlen(str);
	len_buff = ft_strlen(str_buff);
	new_str = malloc(sizeof(char) * (len_str + len_buff + 1));
	if (!new_str)
		return (NULL);
	new_str = concat_strings(new_str, str, str_buff);
	if (str)
		free(str);
	return (new_str);
}

int	get_nl_index(char *buff)
{
	int	i;

	i = 0;
	while (i < ft_strlen(buff))
	{
		if (buff[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

void	unshift_buff(char *buff, int start)
{
	int		i;

	i = 0;
	while (start + i < ft_strlen(buff))
	{
		buff[i] = buff[start + i];
		i++;
	}
	buff[i] = '\0';
}
