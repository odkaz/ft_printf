#include "libft.h"

char	*ft_strmapi(char const	*s, char (*f)(unsigned int, char))
{
	int		i;
	char	*res;

	i = 0;
	res = (char	*)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (res == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		res[i] = f(i, s[i]);
		i++;
	}
	res[i] = '\0';
	return (res);
}