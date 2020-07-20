/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazumanoda <kazumanoda@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 23:29:48 by knoda             #+#    #+#             */
/*   Updated: 2020/07/10 22:01:00 by kazumanoda       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;

	if (ft_strlen(s) < start)
	{
		if (!(res = (char	*)ft_calloc(1, sizeof(char))))
			return (NULL);
		return (res);
	}
	if (!(res = (char	*)ft_calloc((len + 1), sizeof(char))))
		return (NULL);
	ft_strlcpy(res, (char	*)(s + start), (len + 1));
	return (res);
}
