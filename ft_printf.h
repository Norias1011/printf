/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 13:52:25 by akinzeli          #+#    #+#             */
/*   Updated: 2024/02/27 16:47:32 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "./libft/libft.h"

void	ft_putnbr_base(unsigned long long nb, unsigned long long sizebase, char *base);
int	checkp(va_list args);
int	checkx(char c, va_list args);
int	checkc(va_list args);
int	checks(va_list args);
int	checkdi(va_list args);
int	checku(va_list args);
int	checkchar(char c, va_list args);
int	ft_printf(const char *format, ...);

#endif 
