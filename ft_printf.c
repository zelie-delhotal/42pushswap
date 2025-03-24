/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelhota <gdelhota@student.42perpigna      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 19:25:54 by gdelhota          #+#    #+#             */
/*   Updated: 2024/11/15 13:58:27 by gdelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

static int	ft_putstr(char *s)
{
	int	i;

	if (!s)
		return (ft_putstr("(null)"));
	i = -1;
	while (s[++i])
		write (1, &s[i], 1);
	return (i);
}

static int	ft_putnb(int n, char format)
{
	long	cast;
	int		written;

	if (format == 'u')
		cast = (unsigned int) n;
	else
		cast = (long) n;
	written = 0;
	if (cast < 0)
	{
		cast = -cast;
		written += ft_putchar('-');
	}
	if (cast > 9)
		written += ft_putnb(cast / 10, 'i');
	written += ft_putchar(cast % 10 + '0');
	return (written);
}

static int	ft_puthexa(unsigned long nb, char format)
{
	char	*base;
	int		written;

	written = 0;
	base = "0123456789abcdef";
	if (format == 'X')
		base = "0123456789ABCDEF";
	if (format == 'p')
	{
		if (nb == 0)
			return (ft_putstr("(nil)"));
		nb = (unsigned long) nb;
		written += write(1, "0x", 2);
		format = 'P';
	}
	if (format == 'x' || format == 'X')
		nb = (unsigned int) nb;
	if (nb < 16)
		written += write(1, &base[nb], 1);
	else
	{
		written += ft_puthexa(nb / 16, format);
		written += ft_puthexa(nb % 16, format);
	}
	return (written);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	size_t	i;
	int		n;

	i = -1;
	n = 0;
	va_start(ap, format);
	while (format[++i])
	{
		if (format[i] != '%' || format[++i] == '%')
			n += write(1, &format[i], 1);
		else if (format[i] == 'c')
			n += ft_putchar((char) va_arg(ap, int));
		else if (format[i] == 's')
			n += ft_putstr((char *) va_arg(ap, char *));
		else if (format[i] == 'd' || format[i] == 'i' || format[i] == 'u')
			n += ft_putnb((int) va_arg(ap, int), format[i]);
		else if (format[i] == 'x' || format[i] == 'X' || format[i] == 'p')
			n += ft_puthexa((long) va_arg(ap, long), format[i]);
	}
	va_end(ap);
	return (n);
}

/*#include <stdio.h>
int	main(void)
{
	char	*s = "test";
	char	*vide = "";
	int		r1;
	int		r2;
	void	*vide2 = NULL;
	printf("printf:\n");
	r1 = printf("%c %c %c %c %c\n", 0, 'z', '\n', 'P', '\'');
	ft_printf("ft_printf:\n");
	r2 = ft_printf("%c %c %c %c %c\n", 0, 'z', '\n', 'P', '\'');
	ft_printf("return values: %i / %i\n", r1, r2);
	printf("printf:\n");
	r1 = printf("%s %s %s %s\n", vide, s, (char *) vide2, "12345");
	ft_printf("ft_printf:\n");
	r2 = ft_printf("%s %s %s %s\n", vide, s, (char *) vide2, "12345");
	ft_printf("return values: %i / %i\n", r1, r2);
	printf("printf:\n");
	r1 = printf("%p %p %p %p\n", s, &s, &vide2, &vide);
	ft_printf("ft_printf:\n");
	r2 = ft_printf("%p %p %p %p\n", s, &s, &vide2, &vide);
	ft_printf("return values: %i / %i\n", r1, r2);
	printf("printf:\n");
	r1 = printf("%p %p %p\n", (void*)9223372036854775807, (void*)0, (void*)-1);
	ft_printf("ft_printf:\n");
	r2 = ft_printf("%p %p %p\n",(void*)9223372036854775807,(void*)0,(void*)-1);
	ft_printf("return values: %i / %i\n", r1, r2);
	printf("printf:\n");
	r1 = printf("%d %d %d\n", 2147483647, -2147483647 - 1, 0);
	ft_printf("ft_printf:\n");
	r2 = ft_printf("%d %d %d\n", 2147483647, -2147483647 - 1, 0);
	ft_printf("return values: %i / %i\n", r1, r2);
	printf("printf:\n");
	r1 = printf("%u %u %u\n", 2147483647, -2147483647 - 1, 0);
	ft_printf("ft_printf:\n");
	r2 = ft_printf("%u %u %u\n", 2147483647, -2147483647 - 1, 0);
	ft_printf("return values: %i / %i\n", r1, r2);
	printf("printf:\n");
	r1 = printf("%x %x %x\n", 2147483647, -2147483647 - 1, 0);
	ft_printf("ft_printf:\n");
	r2 = ft_printf("%x %x %x\n", 2147483647, -2147483647 - 1, 0);
	ft_printf("return values: %i / %i\n", r1, r2);
	printf("printf:\n");
	r1 = printf("%x %x %x %x %x\n", -1, 2500, 12345, 2147483647, -12345);
	ft_printf("ft_printf:\n");
	r2 = ft_printf("%x %x %x %x %x\n", -1, 2500, 12345, 2147483647, -12345);
	ft_printf("return values: %i / %i\n", r1, r2);
	printf("printf:\n");
	r1 = printf("%s %s %% %p %x %X\n", s, s, &s, 123, 123);
	ft_printf("ft_printf:\n");
	r2 = ft_printf("%s %s %% %p %x %X\n", s, s, &s, 123, 123);
	ft_printf("return values: %i / %i\n", r1, r2);
}*/
