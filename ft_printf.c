#include <stdio.h>
#include "ft_printf.h"

int		my_write(int fd, char *str, unsigned int len)
{
	static int rv;

	if (fd == -1 && !*str && len == 0)
		rv = 0;
	write (fd, str, len);
	rv += len;
	return (rv);
}



void	conversion(format_t f, va_list args)
{
	if (*f.fmt == 'c')
		print_c(va_arg(args, int), f.flag, f.fld, f.pcn);
	if (*f.fmt == 's')
		print_s(va_arg(args, const char *), f.flag, f.fld, f.pcn);
	if (*f.fmt == 'p')
		print_p(va_arg(args, unsigned long), f.flag, f.fld, f.pcn);
	if (*f.fmt == 'd' || *f.fmt == 'i')
		print_int(va_arg(args, int), f.flag, f.fld, f.pcn);
	if (*f.fmt == 'u')
		print_u(va_arg(args, unsigned int), f.flag, f.fld, f.pcn);
	if (*f.fmt == 'x')
		print_x(va_arg(args, unsigned int), f.flag, f.fld, f.pcn);
	if (*f.fmt == 'X')
		print_lx(va_arg(args, unsigned int), f.flag, f.fld, f.pcn);
	if (*f.fmt == '%')
		print_c('%', f.flag, f.fld, f.pcn);
}

int		get_value(const char *s, va_list args, int *target)
{
	int 	cnt;
	int		tmp;

	if (*s == '*')
	{
		tmp = va_arg(args, int);
		if (*target == 1 && tmp == 0)
			*target = -1;
		else
			*target = tmp;
		return (1);
	}
	tmp = ft_atoi(s);
	if (*target == 1 && tmp == 0)
	{
		*target = -1;
	}
	else
	{
		*target = tmp;
	}
	cnt = 0;
	while (ft_isdigit(*s))
	{
		s++;
		cnt++;
	}
	return(cnt);
}

char	*init_format(const char	*s, va_list args, format_t *format)
{
	char	*flag;
	int		fld;
	int		pcn;
	char	*fmt;

	flag = ft_strchr("-0", *s);
	while (ft_strchr("-0", *s))
	{
		if (flag != NULL && *flag == '-')
		{
			s++;
			continue;
		}
		flag = ft_strchr("-0", *s);
		s++;

	}
	fld = 0;
	s += get_value(s, args, &fld);
	pcn = 0;
	if (*s == '.')
	{
		s++;
		pcn = 1;
	}
	s += get_value(s, args, &pcn);
	fmt = ft_strchr("cspdiuxX%", *s);
	if (fmt != NULL)
	{
		format->flag = flag;
		format->fld = fld;
		format->pcn = pcn;
		format->fmt = fmt;
	}
	if (*s)
		s++;
	return ((char *)s);
}

int	ft_printf(const char *s, ...)
 {
	va_list	args;
	format_t format;

	my_write(-1, "", 0);
	va_start(args, s);
	while (*s)
	{
		if (*s == '%')
		{
			s++;
			// printf("s > %s\n", s);
			s = init_format(s, args, &format);
			// printf("\n");
			// if (format.flag != NULL)
			// 	printf("flag > %c\n", *format.flag);
			// printf("fld > %d\n", format.fld);
			// printf("pcn > %d\n", format.pcn);
			// if (format.fmt != NULL)
			// 	printf("fmt > %c\n", *format.fmt);
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
