#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdio.h>


# include <stdlib.h>
# include <unistd.h>
#include <stdarg.h>
# include <limits.h>
#include "./libft/libft.h"

int	my_write(int fd, char *str, unsigned int len);
int	ft_printf(const char *s, ...);
int	print_c(char c, char *flag, int fld, int pcn);
int	dec_len(long n);
int	print_int(int n, char *flag, int fld, int pcn);
int	print_u(unsigned int n, char *flag, int fld, int pcn);
int	print_lx(unsigned int n, char *flag, int fld, int pcn);
int	print_p(unsigned long p, char *flag, int fld, int pcn);
int	print_s(const char *s, char *flag, int fld, int pcn);
int	print_x(unsigned int n, char *flag, int fld, int pcn);
int	hex_len(unsigned long n);


typedef struct {
	char	*flag;
	int		fld;
	int		pcn;
	char	*fmt;
}			format_t;


#endif
