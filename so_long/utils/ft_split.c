/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyazici <amzyaziciali1@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 13:48:34 by alyazici          #+#    #+#             */
/*   Updated: 2022/01/18 16:33:47 by alyazici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static size_t	ft_countchar(const char *s, char c, int opt_delimit)
{
	size_t	i;

	i = 0;
	if (opt_delimit)
	{
		while (s[i] && s[i] != c)
			i++;
	}
	else
	{
		while (s[i] && s[i] == c)
			i++;
	}
	return (i);
}

static size_t	ft_countword(const char *str, char c)
{
	size_t	i;
	size_t	nb_words;

	i = 0;
	nb_words = 0;
	while (str[i] && str[i] == c)
		i++;
	while (str[i])
	{
		while (str[i] && str[i] != c)
			i++;
		nb_words++;
		while (str[i] && str[i] == c)
			i++;
	}
	return (nb_words);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	size_t	nb_words;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	nb_words = ft_countword(s, c);
	array = malloc((nb_words + 1) * sizeof(char *));
	if (!(array))
		return (NULL);
	while (i < nb_words)
	{
		s += ft_countchar(s, c, 0);
		array[i] = ft_substr(s, 0, ft_countchar(s, c, 1));
		if (!(array[i]))
			return (NULL);
		s += ft_countchar(s, c, 1) + ft_countchar(s, c, 0);
		i++;
	}
	array[i] = NULL;
	return (array);
}
