#include "ft_printf.h"

int	hex_len(unsigned long n)
{
	int		len;

	len = (n <= 0);
	while ((n /= 16))
	{
		len++;
	}
	return (len + 1);
}

void	hex_x(int p)
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
	hex_x(p / 16);
	c = base[p % 16];
	my_write(1, &c, 1);
}

int	print_x(unsigned int n, char *flag, int fld, int pcn)
{
	int len;

	len = hex_len(n);
	if (pcn == -1)
	{
		if (fld == 0)
			return (0);
		pcn = 0;
		len = 0;
	}
	if ((pcn = pcn - len) < 0)
	{
		pcn = 0;
	}
	if ((fld = fld - (len + pcn)) < 0)
	{
		fld = 0;
	}
	if (flag && *flag == '-')
	{
		while (pcn--)
		{
			my_write(1, "0", 1);
		}
		if (len != 0)
			hex_x(n);
		while(fld--)
		{
			my_write(1, " ", 1);
		}
	} else {
		while(fld--)
		{
			if (flag && *flag == '0' && pcn == 0)
				my_write(1, "0", 1);
			else
				my_write(1, " ", 1);
		}
		while (pcn--)
		{
			my_write(1, "0", 1);
		}
		if (len != 0)
			hex_x(n);
	}
	return (0);
}

