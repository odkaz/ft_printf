/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazumanoda <kazumanoda@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 01:13:40 by kazumanoda        #+#    #+#             */
/*   Updated: 2020/07/21 01:36:06 by kazumanoda       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	out_c(char c, t_format f)
{
	if (f.flag && *f.flag == '-')
	{
		while (f.pcn--)
			my_write(1, "0", 1);
		my_write(1, &c, 1);
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
		my_write(1, &c, 1);
	}
}

void	print_c(char c, t_format f)
{
	int len;

	len = 1;
	if ((f.pcn = f.pcn - len) < 0)
		f.pcn = 0;
	if ((f.fld = f.fld - (len + f.pcn)) < 0)
		f.fld = 0;
	out_c(c, f);
}
