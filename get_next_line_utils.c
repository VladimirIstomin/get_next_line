/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmerlene <gmerlene@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 13:46:35 by gmerlene          #+#    #+#             */
/*   Updated: 2021/10/10 10:26:34 by gmerlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
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
	while (str2 && str2[j])
	{
		space[i + j] = str2[j];
		j++;
	}
	space[i + j] = '\0';
	return (space);
}

char	*add_to_line(char *str, char *buff)
{
	int		len_str;
	int		len_buff;
	char	*new_str;

	len_str = ft_strlen(str);
	len_buff = ft_strlen(buff);
	new_str = malloc(sizeof(char) * (len_str + len_buff + 1));
	if (!new_str)
		return (NULL);
	new_str = concat_strings(new_str, str, buff);
	if (str)
		free(str);
	return (new_str);
}

int	get_nl_index(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (i < ft_strlen(str))
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

void	unshift_string(char *str, int start)
{
	int		i;

	i = 0;
	if (!str)
		return ;
	while (start + i < ft_strlen(str))
	{
		str[i] = str[start + i];
		i++;
	}
	str[i] = '\0';
}
