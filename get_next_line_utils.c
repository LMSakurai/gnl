/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmasato- <lmasato-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 17:07:51 by lmasato-          #+#    #+#             */
/*   Updated: 2022/08/03 19:53:21 by lmasato-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{	
	int				i;
	unsigned char	ch;

	ch = c;
	i = 0;
	if (s == NULL)
		return (NULL);
	while (s[i] != '\0')
	{	
		if (s[i] == ch)
			return ((char *)(&s[i]));
		i++;
	}
	if (ch == 0)
		return ((char *)(&s[i]));
	return (0);
}

size_t	ft_strlen(const char *s)
{	
	size_t	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *src)
{
	char	*dest;
	int		i;

	i = 0;
	if (src == NULL)
		return (NULL);
	dest = malloc(sizeof(char) * (ft_strlen(src) + 1));
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strljoin(char *s1, char *s2, ssize_t size)
{
	char	*p;
	size_t	n;

	if (size <= 0)
		return (NULL);
	p = malloc(sizeof(char) * (size + 1));
	n = ft_strlen(s1);
	if (s1)
		ft_memcpy(p, s1, n);
	if (s2)
		ft_memcpy(p + n, s2, size - n);
	p[size] = '\0';
	return (p);
}	

void	*ft_memcpy(void *dest, const void *src, size_t n)
{	
	size_t	i;
	char	*d;
	char	*s;

	i = 0;
	d = (char *) dest;
	s = (char *) src;
	while (i < n)
	{	
		d[i] = s[i];
		i++;
	}
	return (dest);
}
