/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazumanoda <kazumanoda@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 23:28:25 by knoda             #+#    #+#             */
/*   Updated: 2020/07/10 22:10:43 by kazumanoda       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*res;

	len = ft_strlen(s1) + ft_strlen(s2);
	res = (char	*)ft_calloc((len + 1), sizeof(char));
	if (!res)
		return (NULL);
	ft_memmove(res, (char	*)s1, ft_strlen(s1));
	ft_memmove(res + ft_strlen(s1), (char	*)s2, ft_strlen(s2));
	return (res);
}
