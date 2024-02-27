/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 13:32:00 by akinzeli          #+#    #+#             */
/*   Updated: 2024/02/27 16:05:07 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	checkchar(char c, va_list args)
{
	int	count;

	count = 0;
	if (c == 'c')
	{
		count = checkc(args);
	}
	else if (c == 's')
	{
		count = checks(args);
	}
	else if (c == 'p')
	{
		count = checkp(args);
	}
	else if (c == 'd' || c == 'i')
	{
		count = checkdi(args);
	}
	else if (c == 'u')
	{
		count = checku(args);
	}
	else if (c == 'x' || c == 'X')
	{
		count = checkx(c, args);
	}
	else if (c == '%')
	{
		write(1, "%", 1);
		count = 1;
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int	count;
	int	i;

	va_start(args, format);
	count = 0;
	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			count = count + checkchar(format[i], args);
			i = i + (count - 2);
		}
		else
		{
			write(1, &format[i], 1);
		}
		count++;
		i++;
	}
	va_end(args);
	return (count);
}
