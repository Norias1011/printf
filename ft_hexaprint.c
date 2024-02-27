/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexaprint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 11:53:46 by akinzeli          #+#    #+#             */
/*   Updated: 2024/02/27 16:50:41 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_base(unsigned long long nb, unsigned long long sizebase, char *base)
{
	unsigned long long	d;

	d = nb;
/*	if (d < 0)
	{	
		write(1, "-", 1);
		d = d * -1;
	}*/	
	if (d >= sizebase)
	{
		ft_putnbr_base(d / sizebase, sizebase, base);
		d = d % sizebase;
	}
	if (d < sizebase)
	{
		write(1, &base[d], 1);
	}
}

int	checkp(va_list args)
{
	unsigned long long	p;
	int	count;

	count = 0;
	p = va_arg(args, unsigned long long);
	write(1, "0x", 2);
	ft_putnbr_base(p, 16, "0123456789abcdef");
	while (p != 0)
	{
		p = p / 16;
		count++;
	}
	return (count + 2);
}

int	checkx(char c, va_list args)
{
	int	number;
	int 	count;

	count = 0;
	number = va_arg(args, int);
	if (c == 'x')
		ft_putnbr_base(number, 16, "0123456789abcdef");
	else 
		ft_putnbr_base(number, 16, "0123456789ABCDEF");
	while (number != 0)
	{
		number = number / 16;
		count++;
	}
	return (count);
}
