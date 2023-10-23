int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	else
		return (0);
}

#include <stdio.h>
int main(void)
{
	int	c;
	int	result;

	c = 35;
	result = ft_isprint(c);
	printf("ft_isprint(%d) returns a value of %d", c, result);
}
