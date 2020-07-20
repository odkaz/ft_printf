/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazumanoda <kazumanoda@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 23:26:18 by knoda             #+#    #+#             */
/*   Updated: 2020/07/14 14:51:18 by kazumanoda       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	mallen(int n)
{
	int		len;

	len = (n <= 0);
	while (n / 10)
	{
		len++;
	}
	return (len + 1);
}

char		*ft_itoa(int n)
{
	char	*res;
	int		i;
	long	div;
	long	ln;

	res = (char	*)ft_calloc(mallen(n), sizeof(char));
	if (res == NULL)
		return (NULL);
	i = 0;
	ln = n;
	div = 1;
	if (ln < 0)
	{
		res[i++] = '-';
		ln *= -1;
	}
	while (ln / div >= 10)
		div *= 10;
	while (div >= 1)
	{
		res[i++] = ln / div % 10 + '0';
		div /= 10;
	}
	return (res);
}
