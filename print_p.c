/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazumanoda <kazumanoda@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 01:13:47 by kazumanoda        #+#    #+#             */
/*   Updated: 2020/07/21 01:36:14 by kazumanoda       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ptr_len(unsigned long p)
{
	int		len;

	len = 0;
	while ((p /= 16))
		len++;
	return (len + 1);
}

void	hex_ptr(unsigned long p)
{
	char	*base;
	char	c;

	base = "0123456789abcdef";
	if (p < 16)
	{
		c = base[p];
		my_write(1, &c, 1);
		return ;
	}
	hex_ptr(p / 16);
	c = base[p % 16];
	my_write(1, &c, 1);
}

void	out_p(unsigned long p, t_format f, int len)
{
	if (f.flag && *f.flag == '-')
	{
		my_write(1, "0x", 2);
		while (f.pcn--)
			my_write(1, "0", 1);
		if (len)
			hex_ptr(p);
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
		my_write(1, "0x", 2);
		while (f.pcn--)
			my_write(1, "0", 1);
		if (len)
			hex_ptr(p);
	}
}

void	print_p(unsigned long p, t_format f)
{
	int len;

	len = ptr_len(p);
	if (f.pcn == -1)
	{
		f.pcn = 0;
		len = 0;
	}
	if ((f.pcn = f.pcn - len) < 0)
		f.pcn = 0;
	if ((f.fld = f.fld - (len + f.pcn + 2)) < 0)
		f.fld = 0;
	out_p(p, f, len);
}
