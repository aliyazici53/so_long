/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyazici <amzyaziciali1@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 16:42:10 by alyazici          #+#    #+#             */
/*   Updated: 2022/01/12 13:11:56 by alyazici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*ft_strdup(const char *str)
{
	int			idx;
	char		*dest;
	size_t		len;

	len = ft_strlen((char *)str);
	dest = malloc(sizeof(char) * (len + 1));
	if (!(dest))
		return (0);
	idx = 0;
	while (str[idx])
	{
		dest[idx] = str[idx];
		idx++;
	}
	dest[idx] = '\0';
	return (dest);
}
