#include "libft.h"

void	ft_bzero(void	*s, size_t	n)
{
	unsigned long	i;
	char			*str;

	i = 0;
	str = (char	*)s;
	while(i < n)
	{
		str[i] = 0;
		i++;
	}
}