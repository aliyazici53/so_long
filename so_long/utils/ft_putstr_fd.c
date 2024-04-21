/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyazici <alyazici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 17:47:19 by alyazici          #+#    #+#             */
/*   Updated: 2022/04/29 17:47:19 by alyazici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
	{
		i = ft_putstr_fd("(null)", 1);
		return (i);
	}
	while (s[i])
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}	
	return (i);
}
