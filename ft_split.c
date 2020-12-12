/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakwak <jakwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 05:53:29 by jakwak            #+#    #+#             */
/*   Updated: 2020/12/13 05:53:31 by jakwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**make_blank(char *s)
{
	char	**result;

	free(s);
	if (!(result = malloc(sizeof(char *))))
		return (0);
	result[0] = 0;
	return (result);
}

static int	get_word_count(char *s, char c)
{
	int	i;
	int	prev;
	int	count;

	count = 0;
	i = 0;
	prev = -1;
	while (s[i])
	{
		if (s[i] == c)
		{
			if (i > prev + 1)
				count++;
			prev = i;
			s[i] = 0;
		}
		i++;
	}
	if (s[i - 1] != 0)
		count++;
	return (count);
}

static char	**free_arr(char **arr)
{
	size_t i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (0);
}

static char	**fill_words(char *s, int count)
{
	size_t	i;
	char	**result;
	int		j;

	if (!(result = malloc(sizeof(char *) * (count + 1))))
		return (0);
	i = 0;
	j = 0;
	while (j < count)
	{
		if (s[i])
		{
			if ((result[j] = ft_strdup(s + i)) == 0)
				return (free_arr(result));
			i += ft_strlen(result[j]);
			j++;
		}
		i++;
	}
	result[j] = 0;
	return (result);
}

char		**ft_split(char const *s, char c)
{
	char	**result;
	char	*s2;
	int		count;

	if (!s || !(s2 = ft_strdup(s)))
		return (0);
	if (ft_strlen(s2) < 1)
		return (make_blank(s2));
	count = get_word_count(s2, c);
	result = fill_words(s2, count);
	free(s2);
	return (result);
}
