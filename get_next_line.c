/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmerlene <gmerlene@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 13:46:32 by gmerlene          #+#    #+#             */
/*   Updated: 2021/10/10 10:34:28 by gmerlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

static char	*extract_line(char *line)
{
	int		nl_index;
	int		len;
	char	*extracted;
	int		i;

	nl_index = get_nl_index(line);
	if (nl_index == -1)
		len = ft_strlen(line);
	else
		len = nl_index + 1;
	if (len == 0)
		return (NULL);
	extracted = malloc(sizeof(char) * (len + 1));
	if (!extracted)
		return (NULL);
	i = 0;
	while (i < len)
	{
		extracted[i] = line[i];
		i++;
	}
	extracted[i] = '\0';
	return (extracted);
}

char	*get_next_line(int fd)
{
	char		buff[BUFFER_SIZE + 1];
	int			rt;
	static char	*next_line;
	char		*res;

	if (get_nl_index(next_line) == -1)
	{
		while (get_nl_index(buff) == -1)
		{
			rt = read(fd, buff, BUFFER_SIZE);
			if (rt <= 0)
			{
				buff[0] = '\0';
				break ;
			}
			buff[rt] = '\0';
			next_line = add_to_line(next_line, buff);
			if (!next_line)
				return (NULL);
		}
	}
	res = extract_line(next_line);
	if (rt <= 0 && next_line)
	{
		free(next_line);
		next_line = NULL;
	}
	unshift_string(next_line, get_nl_index(next_line) + 1);
	return (res);
}

/*int	main(void)
{
	int	fd;

	fd = open("test.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	return (0);
}*/
