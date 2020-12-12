/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakwak <jakwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 05:53:48 by jakwak            #+#    #+#             */
/*   Updated: 2020/12/13 05:53:50 by jakwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	size_t	i;
	char	*result;

	if (s1 == 0 && s2 == 0)
		return (0);
	else if (s1 == 0 || s2 == 0)
		return (s1 == 0 ? ft_strdup(s2) : ft_strdup(s1));
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	if ((result = (char *)malloc(sizeof(char) * len)) == 0)
		return (0);
	i = ft_strlcpy(result, s1, len);
	ft_strlcat(result + i, s2, len);
	return (result);
}
