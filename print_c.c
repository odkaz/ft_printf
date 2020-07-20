#include "ft_printf.h"


// int	print_c(char c)
// {
// 	write(1, &c, 1);
// 	return (0);
// }


int	print_c(char c, char *flag, int fld, int pcn)
{
	int len;

	len = 1;
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
		my_write(1, &c, 1);
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
		my_write(1, &c, 1);
	}
	return (0);
}
