/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerda-si <jerda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 22:31:41 by jerda-si          #+#    #+#             */
/*   Updated: 2024/11/01 18:43:26 by jerda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int s)
{
	while (*str)
	{
		if (*str == (char)s)
			return ((char *)str);
		str++;
	}
	if ((char)s == '\0')
	{
		return ((char *)str);
	}
	return (NULL);
}
