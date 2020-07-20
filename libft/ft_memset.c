/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazumanoda <kazumanoda@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 23:27:10 by knoda             #+#    #+#             */
/*   Updated: 2020/07/10 21:26:34 by kazumanoda       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *buf, int ch, size_t n)
{
	unsigned char	*ptr;
	unsigned char	c;

	ptr = (unsigned char	*)buf;
	c = (unsigned char)ch;
	while (n--)
		*ptr++ = c;
	return (buf);
}
