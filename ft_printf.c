/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazumanoda <kazumanoda@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 01:13:29 by kazumanoda        #+#    #+#             */
/*   Updated: 2020/07/25 17:44:40 by kazumanoda       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		my_write(int fd, char *str, unsigned int len)
{
	static int rv;

	if (fd == -1 && !*str && len == 0)
		rv = 0;
	write(fd, str, len);
	rv += len;
	return (rv);
}

void	conversion(t_format f, va_list args)
{
	if (*f.fmt == 'c')
		print_c(va_arg(args, int), f);
	if (*f.fmt == 's')
		print_s(va_arg(args, const char *), f);
	if (*f.fmt == 'p')
		print_p((size_t)va_arg(args, void *), f);
	if (*f.fmt == 'd' || *f.fmt == 'i')
		print_int(va_arg(args, int), f);
	if (*f.fmt == 'u')
		print_u(va_arg(args, unsigned int), f);
	if (*f.fmt == 'x' || *f.fmt == 'X')
		print_x(va_arg(args, unsigned int), f);
	if (*f.fmt == '%')
		print_c('%', f);
}

char	*get_value(const char *s, va_list args, int *target, char **flag)
{
	int		tmp;

	if (*s == '*')
	{
		tmp = va_arg(args, int);
		s++;
	}
	else
		tmp = ft_atoi(s);
	if (tmp < 0 && *target == 0)
	{
		tmp = -tmp;
		*flag = "-";
	}
	else if (tmp < 0 && *target == 1)
	{
		*target = 0;
		tmp = 0;
	}
	*target = (*target == 1) && (tmp == 0) ? -1 : tmp;
	while (*s && ft_isdigit(*s))
		s++;
	return ((char *)s);
}

char	*init_format(const char *s, va_list args, t_format *f)
{
	f->flag = ft_strchr("-0", *s);
	while (ft_strchr("-0", *s))
	{
		if (f->flag != NULL && *(f->flag) == '-')
		{
			s++;
			continue ;
		}
		f->flag = ft_strchr("-0", *s);
		s++;
	}
	f->fld = 0;
	s = get_value(s, args, &(f->fld), &(f->flag));
	f->pcn = 0;
	if (*s == '.')
	{
		s++;
		f->pcn = 1;
	}
	s = get_value(s, args, &(f->pcn), &(f->flag));
	f->fmt = ft_strchr("cspdiuxX%", *s);
	if (*s)
		s++;
	return ((char *)s);
}

int		ft_printf(const char *s, ...)
{
	va_list		args;
	t_format	format;

	my_write(-1, "", 0);
	va_start(args, s);
	while (*s)
	{
		if (*s == '%')
		{
			s++;
			s = init_format(s, args, &format);
			if (format.fmt != NULL)
				conversion(format, args);
		}
		else
		{
			my_write(1, (char *)s, 1);
			s++;
		}
	}
	va_end(args);
	return (my_write(1, "", 0));
}
