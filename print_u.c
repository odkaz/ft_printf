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

int	print_u(unsigned int n, char *flag, int fld, int pcn)
{
	int len;

	len = dec_len(n);
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
			rec_num_u(n);
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
			rec_num_u(n);
	}
	return (0);
}
