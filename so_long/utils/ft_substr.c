/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyazici <amzyaziciali1@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 16:52:35 by alyazici          #+#    #+#             */
/*   Updated: 2022/01/21 14:55:28 by alyazici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char			*dest;
	unsigned int	idx;

	idx = 0;
	dest = malloc(sizeof(char) * (len + 1));
	if (!(dest) || !(s))
		return (0);
	while (start < ft_strlen((char *)s) && s[start + idx] && idx < len)
	{
		dest[idx] = s[start + idx];
		idx++;
	}
	dest[idx] = '\0';
	return (dest);
}
