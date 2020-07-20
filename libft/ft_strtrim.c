/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazumanoda <kazumanoda@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 23:29:34 by knoda             #+#    #+#             */
/*   Updated: 2020/07/10 21:30:54 by kazumanoda       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	char	*end;

	while (*s1 && ft_strchr(set, *s1))
		s1++;
	if (*s1)
		end = (char	*)(s1 + ft_strlen(s1) - 1);
	else
		end = (char	*)s1;
	while (end > s1 && ft_strchr(set, *end))
		end--;
	res = (char	*)ft_calloc((end - s1 + 1 + 1), sizeof(char));
	if (!res)
		return (NULL);
	ft_strlcpy(res, s1, end - s1 + 1 + 1);
	return (res);
}
