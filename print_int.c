#include "ft_printf.h"


int	dec_len(long n)
{
	int		len;

	len = (n < 0);
	while ((n /= 10))
	{
		len++;
	}
	return (len + 1);
}


void	rec_num(int n)
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
	rec_num(n / 10);
	c = base[n % 10];
	my_write(1, &c, 1);
}

void	put_num(int n)
{
	if (n == INT_MIN)
	{
		my_write(1, "2147483648", 11);
	}
	else if (n < 0)
	{
		rec_num(-n);
	}
	else
	{
		rec_num(n);
	}
}



int	print_int(int n, char *flag, int fld, int pcn)
{
	int len;

	len = dec_len(n);
	// printf("fld > %d, pcn > %d, len %d\n", fld, pcn, len);
	if (pcn == -1)
	{
		if (fld == 0)
			return (0);
		pcn = 0;
		len = 0;
	}
	if (pcn && flag && *flag == '0')
		flag = NULL;
	if ((pcn = pcn - len) < 0)
	{
		pcn = 0;
	}
	else if (n < 0)
	{
		pcn++;
	}
	if ((fld = fld - (len + pcn)) < 0)
	{
		fld = 0;
	}
	if (flag && *flag == '-')
	{
		if (n < 0)
			my_write(1, "-", 1);
		while (pcn--)
		{
			my_write(1, "0", 1);
		}
		if (len != 0)
			put_num(n);
		while(fld--)
		{
			my_write(1, " ", 1);
		}
	} else {
		// printf("fld > %d, pcn > %d, len %d\n", fld, pcn, len);
		if (n < 0 && flag && *flag == '0' && pcn == 0)
			my_write(1, "-", 1);
		while(fld--)
		{
			if (flag && *flag == '0' && pcn == 0)
				my_write(1, "0", 1);
			else
				my_write(1, " ", 1);
		}
		if (n < 0 && !(flag && *flag == '0' && pcn == 0))
			my_write(1, "-", 1);
		while (pcn--)
		{
			my_write(1, "0", 1);
		}
		if (len != 0)
			put_num(n);
	}
	return (0);
}
