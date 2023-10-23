char	ft_tolower(char c)
{
	if (c >= 65 && c <= 90)
		return (c + 32);
	else
		return (c);
}
#include <stdio.h>
int	main(void)
{
	char c;
	char result;

	c = 'D';
	result = ft_tolower(c);
	printf("The letter '%c' is now '%c'", c, result);
}
