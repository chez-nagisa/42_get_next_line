/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhara <nhara@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 19:44:33 by nhara             #+#    #+#             */
/*   Updated: 2025/01/18 12:56:51 by nhara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*extract_line(char **buffer)
{
	char	*newline_pos;
	char	*line;
	char	*remaining_buffer;

	newline_pos = ft_strchr(*buffer, '\n');
	if (!newline_pos)
	{
		line = *buffer;
		*buffer = NULL;
		return (line);
	}
	line = malloc((newline_pos - *buffer) + 2);
	if (!line)
		return (NULL);
	ft_strlcpy(line, *buffer, (newline_pos - *buffer) + 2);
	remaining_buffer = ft_strdup(newline_pos + 1);
	if (!remaining_buffer)
	{
		free(line);
		return (NULL);
	}
	free(*buffer);
	*buffer = remaining_buffer;
	return (line);
}

static int	read_to_buffer(int fd, char **buffer)
{
	char	*temp;
	ssize_t	bytes_read;
	char	*new_buffer;

	temp = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!temp)
		return (-1);
	bytes_read = read(fd, temp, BUFFER_SIZE);
	if (bytes_read <= 0)
	{
		free(temp);
		return (bytes_read);
	}
	temp[bytes_read] = '\0';
	new_buffer = ft_strjoin(*buffer, temp);
	free(temp);
	if (!new_buffer)
	{
		free(*buffer);
		*buffer = NULL;
		return (-1);
	}
	free(*buffer);
	*buffer = new_buffer;
	return (bytes_read);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (!buffer || !ft_strchr(buffer, '\n'))
		if (read_to_buffer(fd, &buffer) <= 0)
			break ;
	if (!buffer || !*buffer)
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	line = extract_line(&buffer);
	return (line);
}

// #include "get_next_line.h"
// #include <fcntl.h> // open
// #include <stdio.h> // printf
// #include <stdlib.h> // exit
// #include <unistd.h> // close, read

// int	main(int argc, char **argv)
// {
// 	int		fd;
// 	char	*line;

// 	// 引数チェック
// 	if (argc != 2)
// 	{
// 		printf("Usage: %s <filename>\n", argv[0]);
// 		return (1);
// 	}
// 	// ファイルを開く
// 	fd = open(argv[1], O_RDONLY);
// 	if (fd < 0)
// 	{
// 		perror("Error opening file");
// 		return (1);
// 	}
// 	// 行ごとに読み込む
// 	while ((line = get_next_line(fd)) != NULL)
// 	{
// 		printf("%s", line);
// 		free(line); // メモリを解放
// 	}
// 	// ファイルを閉じる
// 	if (close(fd) < 0)
// 	{
// 		perror("Error closing file");
// 		return (1);
// 	}
// 	return (0);
// }
