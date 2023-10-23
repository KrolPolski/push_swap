char	ft_toupper(char c)
{
	if (c >= 97 && c <= 122)
		return (c - 32);
	else
		return (c);
}

#include <stdio.h>
int	main(void)
{
	char c;
	char result;
	
	c = 'd';
	result = ft_toupper(c);
	printf("The char '%c' should now be uppercase: '%c'", c, result);
}
