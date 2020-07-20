#include "ft_printf.h"

int	print_s(const char *s, char *flag, int fld, int pcn)
{
	int len;

	if (s == NULL)
	{
		s = "(null)";
	}
	len = ft_strlen(s);
	if (pcn != 0 && pcn != -1 && len > pcn)
	{
		len = pcn;
	}
	else if (pcn == -1)
	{
		len = 0;
		pcn = 0;
	}
	if ((fld = fld - len) < 0)
	{
		fld = 0;
	}
	if (flag && *flag == '-')
	{
		my_write(1, (char *)s, len);
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
		my_write(1, (char *)s, len);
	}
	return (0);
}

