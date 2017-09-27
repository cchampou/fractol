/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchampou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 09:01:21 by cchampou          #+#    #+#             */
/*   Updated: 2016/11/07 15:10:51 by cchampou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	j = 0;
	flag = 0;
	if (ft_strlen(little) == 0)
		return ((char*)big);
	while (big[i] != '\0')
	{
		while (big[i] == little[j])
		{
			j++;
			i++;
			if (j == (int)ft_strlen(little))
			{
				return (&((char*)big)[i - j]);
			}
		}
		flag++;
		j = 0;
		i = flag;
	}
	return (NULL);
}
