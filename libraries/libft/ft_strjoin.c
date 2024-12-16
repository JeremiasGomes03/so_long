/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerda-si <jerda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 18:48:55 by jerda-si          #+#    #+#             */
/*   Updated: 2024/11/07 22:57:34 by jerda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		j2;
	int		dest_i;
	char	*result;

	dest_i = 0;
	i = 0;
	if (!s1 && !s2)
		return (ft_strdup(""));
	dest_i = ft_strlen((char *)s1);
	i = ft_strlen((char *)s2);
	result = (char *)malloc(sizeof(char) * (dest_i + i + 1));
	if (!result)
		return (NULL);
	j = -1;
	while (j++ < dest_i - 1)
		result[j] = s1[j];
	j2 = -1;
	while (j2++ < i - 1)
		result[j + j2] = s2[j2];
	result[dest_i + i] = '\0';
	return (result);
}
