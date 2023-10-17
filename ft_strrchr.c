/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 17:39:44 by danbarbo          #+#    #+#             */
/*   Updated: 2023/10/17 17:49:04 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	i = ft_strlen(s);
	if (c == '\0')
		return ((char *) s + i);
	while (s[i - 1] != (char) c && i > 0)
		i--;
	if (i == 0)
		return (NULL);
	// return ((char *) &s[i]);
	// (void) s;
	// (void) c;

	// if ((char) s[0] == 'a')
	// 	return ((char *) s);
	return ((char *) s + i - 1);

}
