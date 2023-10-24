/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 12:26:17 by rboudwin          #+#    #+#             */
/*   Updated: 2023/10/24 14:23:40 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	char	*restrict			destination;
	const char	*restrict		source;
	size_t						i;	

	i = 0;
	destination = dst;
	source = src;
	while (i < n)
	{
		destination[i] = source[i];
		i++;
	}
	return (dst);
}
/*
#include <stdio.h>
int	main(void)
{
	char src[] = "fish";
	char dest[] = "duck";
	void	*result;

	printf("The strings are '%s' and '%s' now \n", src, dest);
	result = ft_memcpy(dest, src, 4);
	printf("The strings should now be the same: '%s' '%s'\n", src, dest);

}*/
