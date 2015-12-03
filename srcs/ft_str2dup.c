/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str2dup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubalest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 16:35:27 by jubalest          #+#    #+#             */
/*   Updated: 2015/12/03 16:35:28 by jubalest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		**ft_str2dup(char **array)
{
	char	**dup;
	int		i;

	i = 0;
	if ((dup = (char **)malloc(sizeof(char *) * (ft_str2len(array) + 1))))
	{
		while (array[i])
		{
			dup[i] = ft_strdup(array[i]);
			i++;
		}
		dup[i] = NULL;
	}
	return (dup);
}
