/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazumanoda <kazumanoda@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 01:13:58 by kazumanoda        #+#    #+#             */
/*   Updated: 2020/07/21 01:36:23 by kazumanoda       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		hex_len(unsigned int n)
{
	int		len;

	len = 0;
	while ((n /= 16))
	{
		len++;
	}
	return (len + 1);
}

void	hex_x(unsigned int n, char *fmt)
{
	char	*base;
	char	c;

	if (*fmt == 'x')
		base = "0123456789abcdef";
	else if (*fmt == 'X')
		base = "0123456789ABCDEF";
	if (n < 16)
	{
		c = base[n];
		my_write(1, &c, 1);
		return ;
	}
	hex_x(n / 16, fmt);
	c = base[n % 16];
	my_write(1, &c, 1);
}

void	out_x(unsigned int n, t_format f, int len)
{
	if (f.flag && *f.flag == '-')
	{
		while (f.pcn--)
			my_write(1, "0", 1);
		if (len != 0)
			hex_x(n, f.fmt);
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
		while (f.pcn--)
			my_write(1, "0", 1);
		if (len != 0)
			hex_x(n, f.fmt);
	}
}

void	print_x(unsigned int n, t_format f)
{
	int len;

	len = hex_len(n);
	if (f.pcn == -1)
	{
		if (f.fld == 0)
			return ;
		f.pcn = 0;
		len = 0;
	}
	if (f.pcn && f.flag && *f.flag == '0')
		f.flag = NULL;
	if ((f.pcn = f.pcn - len) < 0)
		f.pcn = 0;
	if ((f.fld = f.fld - (len + f.pcn)) < 0)
		f.fld = 0;
	out_x(n, f, len);
}
