/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakwak <jakwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 05:53:12 by jakwak            #+#    #+#             */
/*   Updated: 2020/12/13 05:53:15 by jakwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	recur_putnbr(int n, int fd)
{
	if (n >= 10)
		recur_putnbr(n / 10, fd);
	write(fd, &"0123456789"[n % 10], 1);
}

void		ft_putnbr_fd(int n, int fd)
{
	if (fd < 0)
		return ;
	if (n == INT_MIN)
	{
		write(fd, INT_MIN_STR, 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n *= -1;
	}
	recur_putnbr(n, fd);
}
