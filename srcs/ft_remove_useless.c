/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove_useless.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubalest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 16:43:09 by jubalest          #+#    #+#             */
/*   Updated: 2015/12/03 16:43:10 by jubalest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char	*get_new_string(char *old, int i, int s, int len)
{
	char	*new_str;

	if ((new_str = (char *)malloc(sizeof(char) * (len + 1))))
	{
		while (i < len)
		{
			new_str[i] = old[i + s];
			i++;
		}
		new_str[i] = '\0';
	}
	return (new_str);
}

char		*ft_remove_useless(char *str, char c)
{
	char	*new_str;
	int		len;
	int		s;
	int		e;
	int		i;

	len = (int)ft_strlen(str);
	s = 0;
	e = len;
	i = 0;
	while (str[s] == c)
		s++;
	if (s == len)
		return (NULL);
	while (str[e - 1] == c)
		e--;
	e = len - e;
	len = len - (s + e);
	new_str = get_new_string(str, i, s, len);
	return (new_str);
}
