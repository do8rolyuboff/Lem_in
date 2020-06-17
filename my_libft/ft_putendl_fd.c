/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btrifle <btrifle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 18:10:10 by btrifle           #+#    #+#             */
/*   Updated: 2020/06/02 13:44:13 by btrifle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putendl_fd(char const *s, int fd)
{
	char *ptr;

	if (s)
	{
		ptr = (char *)s;
		write(fd, ptr, ft_strlen(ptr));
		write(fd, "\n", 1);
		return (1);
	}
	return (0);
}
