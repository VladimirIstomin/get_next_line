/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmerlene <gmerlene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 13:46:32 by gmerlene          #+#    #+#             */
/*   Updated: 2021/10/09 17:34:54 by gmerlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*handle_read_end(char *buff, char *next_line)
{
	if (buff[0])
	{
		buff[0] = '\0';
		return (next_line);
	}
	if (next_line)
		free(next_line);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1];
	int			rt;
	char		*next_line;

	next_line = NULL;
	while (get_nl_index(buff) == -1)
	{
		next_line = add_to_line(next_line, buff);
		if (!next_line)
			return (NULL);
		rt = read(fd, buff, BUFFER_SIZE);
		if (rt <= 0)
			return (handle_read_end(buff, next_line));
		buff[rt] = '\0';
	}
	next_line = add_to_line(next_line, buff);
	unshift_buff(buff, get_nl_index(buff) + 1);
	return (next_line);
}

/*int	main(void)
{
	int	fd;

	//fd = open("to_read.txt", O_RDONLY);
	fd = 220;
	printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	
	int i;

	char a[10] = "abcdefghi";
	i = 0;
	while (a[i++])
		printf("%c\n", a[i - 1]);
	printf("i: %d\n", i);
	return (0);
}*/
