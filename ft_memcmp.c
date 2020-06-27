#include "libft.h"

int	ft_memcmp(const void	*buf1, const void *buf2, size_t n)
{
	unsigned char	*s1;
	unsigned char	*s2;
	size_t			i;
	
	s1 = (unsigned char*)buf1;
	s2 = (unsigned char*)buf2;
	i = 0;
	while (i < n)
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}
	return (0);
}