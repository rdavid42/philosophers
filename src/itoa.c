
#include <stdlib.h>

static char			*scpy(char *s1, const char *s2)
{
	int		i;

	i = 0;
	while (s2[i] != 0)
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}

static size_t		getsize(int n)
{
	size_t			size;

	size = 0;
	if (n == 0)
	{
		size++;
		return (size);
	}
	if (n < 0)
	{
		n = -n;
		size++;
	}
	while (n > 0)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

char				*itoa(int n)
{
	char		*res;
	size_t		size;
	int			neg;

	if (n == -2147483648 && (res = (char *)malloc(12)))
		return (scpy(res, "-2147483648"));
	size = getsize(n);
	neg = 0;
	if (n < 0 && (neg = 1))
		n = -n;
	res = (char *)malloc(sizeof(char) * size + 1);
	res[size] = '\0';
	while (size)
	{
		size--;
		res[size] = (char)(n % 10 + 48);
		n = n / 10;
	}
	if (neg == 1)
		res[0] = '-';
	return (res);
}