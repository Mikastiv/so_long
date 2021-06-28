/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_lines.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 15:05:29 by mleblanc          #+#    #+#             */
/*   Updated: 2021/06/24 20:27:24 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>
#include <unistd.h>

#define BUF_SIZE 1024

int	count_lines(char *file)
{
	char	buf[BUF_SIZE + 1];
	ssize_t	bytes;
	int		count;
	char	*newline;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (-1);
	count = 0;
	bytes = 1;
	while (bytes > 0)
	{
		bytes = read(fd, &buf, BUF_SIZE);
		if (bytes < 0)
			close(fd);
		if (bytes < 0)
			return (-1);
		buf[bytes] = 0;
		newline = ft_strchr(buf, '\n');
		while (newline && ++count)
			newline = ft_strchr(newline + 1, '\n');
	}
	close(fd);
	return (count + 1);
}
