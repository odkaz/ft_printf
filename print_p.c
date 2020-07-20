#include "ft_printf.h"

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


// int	print_p(unsigned long p)
// {
// 	write(1, "0x", 2);
// 	hex_ptr(p);
// 	return (0);
// }

int	print_p(unsigned long p, char *flag, int fld, int pcn)
{
	int len;

	len = hex_len(p);
	if (pcn == -1)
		pcn = 0;
	if ((pcn = pcn - len) < 0)
	{
		pcn = 0;
	}
	if ((fld = fld - (len + pcn + 2)) < 0)
	{
		fld = 0;
	}
	if (flag && *flag == '-')
	{
		my_write(1, "0x", 2);
		while (pcn--)
		{
			my_write(1, "0", 1);
		}
		hex_ptr(p);
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
		my_write(1, "0x", 2);
		while (pcn--)
		{
			my_write(1, "0", 1);
		}
		hex_ptr(p);
	}
	return (0);
}
