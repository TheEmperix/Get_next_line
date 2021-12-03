#include "get_next_line.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*k;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	k = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!k)
		return (NULL);
	while (s1[i])
		k[j++] = s1[i++];
	i = 0;
	while (s2[i])
		k[j++] = s2[i++];
	k[j] = '\0';
	free(s1);
	free(s2);
	return (k);
}
