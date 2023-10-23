int	ft_strlen(const char *s)
{
	int i;
	int length;

	i = 0;
	while (s[i] != '\0')
	{
		length++;
		i++;
	}
	return (length);
}
#include <stdio.h>
int	main(void)
{
	char string[] = "fish";
	int length;

	length = ft_strlen(string);
	printf("The string '%s' is '%d' characters long.\n", string, length);
}
