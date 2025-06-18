#include <stdlib.h>

char	*ft_strndup(char *str, int size)
{
	char	*tmp;
	int		i;

	tmp = malloc(sizeof(char) * (size + 1));
	if (!tmp)
		return (NULL);
	i = 0;
	if (!str)
		tmp[i] = '\0';
	while (i < size && str[i] != '\0')
	{
		tmp[i] = str[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}