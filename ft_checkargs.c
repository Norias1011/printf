/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkargs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 10:50:07 by akinzeli          #+#    #+#             */
/*   Updated: 2024/02/27 16:16:36 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	checkc(va_list args)
{
	int	count;
	int	letter;

	count = 1;
	letter = va_arg(args, int);
	ft_putchar_fd(letter, 1);
	return (count);
}

int	checks(va_list args)
{
	int	count;
	char	*str;

	str = va_arg(args, char *);
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	count = ft_strlen(str);
	ft_putstr_fd(str, 1);
	return (count);
}

int	checkdi(va_list args)
{
	int	count;
	int	number;

	count = 0;
	number = va_arg(args, int);
	ft_putnbr_fd(number, 1);
	while (number != 0)
	{
		number = number / 10;
		count++;
	}
	return (count);
}

int	checku(va_list args)
{
	int	count;
	unsigned int	number;

	count = 0;
	number = va_arg(args, unsigned int);
	ft_putnbr_fd(number, 1);
	while (number != 0)
	{
		number = number / 10;
		count++;
	}
	return (count);
}
