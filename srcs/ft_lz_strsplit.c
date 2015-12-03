/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lz_strsplit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubalest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 16:41:08 by jubalest          #+#    #+#             */
/*   Updated: 2015/12/03 16:41:09 by jubalest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_count_string(char *str, char c)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (str[i])
	{
		if (str[i] == c && str[i - 1] != c)
			n++;
		i++;
	}
	return (++n);
}

static char	*str_range_dup(char *str, int n)
{
	char	*new_str;
	int		i;

	i = 0;
	if ((new_str = (char *)malloc(sizeof(char) * (n + 1))))
	{
		while (i < n)
		{
			new_str[i] = str[i];
			i++;
		}
		new_str[i] = '\0';
	}
	return (new_str);
}

static char	*move_into_substring(char *str, char c, int match)
{
	if (match)
	{
		while (*str == c)
			str++;
	}
	else
	{
		while (*str && *str != c)
			str++;
	}
	return (str);
}

static int	get_next_sep(char *str, char c)
{
	int i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

char		**ft_lz_strsplit(char *str, char c)
{
	char	**split;
	int		nb_str;
	int		i;
	int		range;

	nb_str = ft_count_string(str, c);
	i = 0;
	if ((split = (char **)malloc(sizeof(char *) * (nb_str + 1))))
	{
		while (i < nb_str)
		{
			if (i != 0)
				str = move_into_substring(str, c, 1);
			range = get_next_sep(str, c);
			split[i] = str_range_dup(str, range);
			str = move_into_substring(str, c, 0);
			i++;
		}
		split[nb_str] = NULL;
	}
	return (split);
}
