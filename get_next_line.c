/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmasato- <lmasato-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 16:39:12 by lmasato-          #+#    #+#             */
/*   Updated: 2022/08/04 16:47:24 by lmasato-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_next_line(int fd, char *buffer, char **r);
static char	*ft_read_buffer(int fd, char *buffer, char **r, ssize_t *b);
static char	*ft_split_line(char *src, char **r);
static char	*error_handler(char **s);

char	*get_next_line(int fd)
{
	static char	*r[MAX_FD + 1];
	char		*buffer;
	char		*p;

	if (fd > MAX_FD || fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (NULL);
	p = ft_next_line(fd, buffer, &r[fd]);
	free(buffer);
	return (p);
}

static char	*ft_next_line(int fd, char *buffer, char **r)
{	
	char	*tmp;
	char	*tmp2;
	char	*p;
	ssize_t	b;

	tmp = ft_strdup(*r);
	free(*r);
	*r = NULL;
	if (ft_strchr(tmp, '\n') == 0)
	{	
		p = ft_read_buffer(fd, buffer, r, &b);
		if (b != -1)
		{
			tmp2 = ft_strljoin(tmp, p, ft_strlen(p) + ft_strlen(tmp));
			free(p);
			p = tmp2;
		}
	}
	else
		p = ft_split_line(tmp, r);
	free(tmp);
	return (p);
}

static char	*ft_read_buffer(int fd, char *buffer, char **r, ssize_t *b)
{	
	ssize_t	count;
	char	*tmp;
	char	*p;

	count = 0;
	*b = 1;
	p = ft_strdup("");
	while (*b > 0)
	{	
		*b = read(fd, buffer, BUFFER_SIZE);
		count = count + *b;
		if (*b == -1)
			return (error_handler(&p));
		tmp = ft_strljoin(p, buffer, count);
		free(p);
		p = tmp;
		if (ft_strchr(tmp, '\n') != 0)
			break ;
	}
	p = ft_split_line(p, r);
	free(tmp);
	return (p);
}

static char	*ft_split_line(char *src, char **r)
{	
	size_t	i;
	size_t	j;
	char	*dest;

	i = 0;
	j = 0;
	if (src == NULL)
		return (NULL);
	if (ft_strchr(src, '\n') == 0)
		return (ft_strdup(src));
	while (src[i] != '\n' && src[i] != '\0')
		i++;
	dest = malloc(sizeof(char) * (i + 2));
	while (j <= i)
	{	
		dest[j] = src[j];
		j++;
	}
	dest[j] = '\0';
	if (src[i + 1] != '\0')
		*r = ft_strdup(&src[i + 1]);
	return (dest);
}

static char	*error_handler(char **s)
{
	free(*s);
	*s = NULL;
	return (NULL);
}
