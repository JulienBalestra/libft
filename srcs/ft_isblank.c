/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isblank.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubalest <jubalest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/20 09:28:29 by jubalest          #+#    #+#             */
/*   Updated: 2015/02/20 09:29:08 by jubalest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_isblank(int c)
{
	if (c == 9 || c == 32)
		return (1);
	else
		return (0);
}
