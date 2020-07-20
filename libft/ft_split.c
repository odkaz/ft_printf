/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazumanoda <kazumanoda@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 23:27:58 by knoda             #+#    #+#             */
/*   Updated: 2020/07/10 21:36:27 by kazumanoda       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	cnt_mal(char const *s, char c)
{
	int	cnt;
	int	flag;

	cnt = 1;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		flag = 0;
		while (*s != c && *s)
		{
			flag = 1;
			s++;
		}
		if (flag)
			cnt++;
	}
	return (cnt);
}

static void	*free_all(char **res, int index)
{
	while (index--)
		free(res[index]);
	free(res);
	return (NULL);
}

char		**ft_split(char const *s, char c)
{
	char	**res;
	int		index;
	int		i;

	if (!(res = (char	**)ft_calloc(cnt_mal(s, c), sizeof(char	*))))
		return (NULL);
	index = 0;
	while (*s)
	{
		i = 0;
		while (s[i] && s[i] != c)
			i++;
		if (i > 0)
		{
			if (!(res[index] = ft_substr(s, 0, i)))
				return (free_all(res, index));
			index++;
			s += i;
		}
		while (*s == c && *s)
			s++;
	}
	res[index] = NULL;
	return (res);
}
