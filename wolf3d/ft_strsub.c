/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasikimu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 12:03:25 by tasikimu          #+#    #+#             */
/*   Updated: 2018/08/28 15:34:02 by tasikimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*news;
	size_t	i;

	i = -1;
	news = malloc(sizeof(char) * len);
	if (!news || !len || !s)
		return (NULL);
	while (++i < len)
		*(news + i) = *(s + start + i);
	return (news);
}
