#include "libft.h"

int	ft_strncmp(const char	*s1, const char *s2, size_t n)
{
	while (*s1 != '\0' && n > 0)
	{
		if (*s1 > *s2)
		{
			return (1);
		}
		else if (*s1 < *s2)
		{
			return (-1);
		}
		s1++;
		s2++;
		n--;
	}
	return (0);
}