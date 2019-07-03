/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmraz <mmraz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 15:44:53 by mmraz             #+#    #+#             */
/*   Updated: 2019/07/03 14:22:11 by mmraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <printf.h>
#include <stdio.h>

int	ft_printf(const char *format, ...)
{
	va_list argptr;

	va_start(argptr, format);
	printf("%s\n", format);
	printf("Hello\n");
	printf("%s", argptr);
	return (0);
}
