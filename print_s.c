/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazumanoda <kazumanoda@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 01:13:50 by kazumanoda        #+#    #+#             */
/*   Updated: 2020/07/21 01:36:17 by kazumanoda       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	out_s(const char *s, t_format f, int len)
{
	if (f.flag && *f.flag == '-')
	{
		my_write(1, (char *)s, len);
		while (f.fld--)
			my_write(1, " ", 1);
	}
	else
	{
		while (f.fld--)
		{
			if (f.flag && *f.flag == '0' && f.pcn == 0)
				my_write(1, "0", 1);
			else
				my_write(1, " ", 1);
		}
		my_write(1, (char *)s, len);
	}
}

void	print_s(const char *s, t_format f)
{
	int len;

	if (s == NULL)
		s = "(null)";
	len = ft_strlen(s);
	if (f.pcn != 0 && f.pcn != -1 && len > f.pcn)
		len = f.pcn;
	else if (f.pcn == -1)
	{
		len = 0;
		f.pcn = 0;
	}
	if ((f.fld = f.fld - len) < 0)
		f.fld = 0;
	out_s(s, f, len);
}
