/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str2defrag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubalest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 16:35:04 by jubalest          #+#    #+#             */
/*   Updated: 2015/12/03 16:35:06 by jubalest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_str2defrag(char **array, size_t origin_size)
{
	size_t	i;
	size_t	j;
	size_t	b;

	i = 0;
	if (origin_size != ft_str2len(array))
	{
		while (i < origin_size + 1)
		{
			if (array[i] == NULL)
			{
				b = i;
				j = i + 1;
				while (j < origin_size + 1)
				{
					array[i] = array[j];
					i++;
					j++;
				}
				i = b;
			}
			i++;
		}
	}
}
