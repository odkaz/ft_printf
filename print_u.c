/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazumanoda <kazumanoda@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 01:13:55 by kazumanoda        #+#    #+#             */
/*   Updated: 2020/07/21 01:36:20 by kazumanoda       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	rec_num_u(unsigned int n)
{
	char	*base;
	char	c;

	base = "0123456789";
	if (n < 10)
	{
		c = base[n];
		my_write(1, &c, 1);
		return ;
	}
	rec_num_u(n / 10);
	c = base[n % 10];
	my_write(1, &c, 1);
}

void	out_u(unsigned int n, t_format f, int len)
{
	if (f.flag && *f.flag == '-')
	{
		while (f.pcn--)
			my_write(1, "0", 1);
		if (len != 0)
			rec_num_u(n);
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
			rec_num_u(n);
	}
}

void	print_u(unsigned int n, t_format f)
{
	int len;

	len = dec_len(n);
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
	out_u(n, f, len);
}
