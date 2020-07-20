/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazumanoda <kazumanoda@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 01:13:43 by kazumanoda        #+#    #+#             */
/*   Updated: 2020/07/21 01:36:12 by kazumanoda       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		dec_len(long n)
{
	int		len;

	len = (n < 0);
	while ((n /= 10))
		len++;
	return (len + 1);
}

void	put_num(int n)
{
	char	*base;
	char	c;

	if (n == INT_MIN)
		my_write(1, "2147483648", 10);
	else if (n < 0)
		put_num(-n);
	else
	{
		base = "0123456789";
		if (n < 10)
		{
			c = base[n];
			my_write(1, &c, 1);
			return ;
		}
		put_num(n / 10);
		c = base[n % 10];
		my_write(1, &c, 1);
	}
}

void	left_out_int(int n, t_format f, int len)
{
	if (n < 0)
		my_write(1, "-", 1);
	while (f.pcn--)
		my_write(1, "0", 1);
	if (len != 0)
		put_num(n);
	while (f.fld--)
		my_write(1, " ", 1);
}

void	right_out_int(int n, t_format f, int len)
{
	if (n < 0 && f.flag && *(f.flag) == '0' && f.pcn == 0)
		my_write(1, "-", 1);
	while (f.fld--)
	{
		if (f.flag && *(f.flag) == '0' && f.pcn == 0)
			my_write(1, "0", 1);
		else
			my_write(1, " ", 1);
	}
	if (n < 0 && !(f.flag && *(f.flag) == '0' && f.pcn == 0))
		my_write(1, "-", 1);
	while (f.pcn--)
		my_write(1, "0", 1);
	if (len != 0)
		put_num(n);
}

void	print_int(int n, t_format f)
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
	if (f.pcn && f.flag && *(f.flag) == '0')
		f.flag = NULL;
	if ((f.pcn = f.pcn - len) < 0)
		f.pcn = 0;
	else if (n < 0)
		f.pcn++;
	if ((f.fld = f.fld - (len + f.pcn)) < 0)
		f.fld = 0;
	if (f.flag && *(f.flag) == '-')
		left_out_int(n, f, len);
	else
		right_out_int(n, f, len);
}
