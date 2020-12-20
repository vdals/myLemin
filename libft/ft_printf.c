/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeri <ggeri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 13:36:55 by ggeri             #+#    #+#             */
/*   Updated: 2020/09/20 18:43:34 by ggeri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	obnulenie2036(t_arg *r)
{
	r->hsh = 0;
	r->zero = 0;
	r->num = 0;
	r->space = 0;
	r->move = 0;
	r->plus = 0;
	r->minus = 0;
	r->minus2 = 0;
	r->precision = 6;
	r->wiedth = -1;
	r->point = 0;
	r->star = 0;
	r->und_beh = 0;
	r->counter = 0;
}

static void	random_flags_check(t_arg *r, va_list ap)
{
	while (*(r->fmt + 1) == '#' || *(r->fmt + 1) == ' ' || \
	(*(r->fmt + 1) >= '0' && *(r->fmt + 1) <= '9') || \
	(*(r->fmt + 1) == '+') || (*(r->fmt + 1) == '-') || \
	(*(r->fmt + 1) == '*') || (*(r->fmt + 1) == '.'))
	{
		if (*(r->fmt + 1) == '#' && r->hsh == 0)
			r->hsh = ft_check_hash(r);
		else if (*(r->fmt + 1) == '0' && r->zero == 0)
			r->zero = ft_check_zero(r);
		else if ((*(r->fmt + 1) > '0') && (*(r->fmt + 1) <= '9'))
			r->num = ft_check_num(r);
		else if (*(r->fmt + 1) == ' ')
			r->space = ft_check_space(r);
		else if (*(r->fmt + 1) == '+')
			r->plus = ft_check_plus(r);
		else if (*(r->fmt + 1) == '-')
			r->minus = ft_check_minus(r);
		else if (*(r->fmt + 1) == '*')
			r->star = ft_check_star(ap, r);
		else if (*(r->fmt + 1) == '.')
			ft_check_wiedth(r);
		else
			r->und_beh = ft_check_undefined_behavior(r);
	}
}

static int	decide(t_arg *r, va_list ap)
{
	int		num;

	num = 0;
	random_flags_check(r, ap);
	r->flg = get_flag(r, ap, 0);
	if ((*(r->fmt + 1) == '%') || (*(r->fmt + 1) == 'p'))
		num += ft_print_symb2(r, ap);
	else if (((*(r->fmt + 1) == 'c') || (*(r->fmt + 1) == 's')))
		num += ft_print_symb(r, ap);
	else if ((*(r->fmt + 1) == 'o') || (*(r->fmt + 1) == 'u') || \
			(*(r->fmt + 1) == 'x') || (*(r->fmt + 1) == 'X') || \
			(*(r->fmt + 1) == 'i') || (*(r->fmt + 1) == 'd') || \
			(*(r->fmt + 1) == 'f'))
		num += ft_print_base(r, num);
	obnulenie2036(r);
	return (num);
}

int			pars(t_arg *r, va_list ap)
{
	int		num;

	num = 0;
	while (*(r->fmt))
	{
		if (*(r->fmt) == '%')
			num += decide(r, ap);
		else
			num += ft_putchar(*(r->fmt));
		r->fmt++;
	}
	return (num);
}

int			ft_printf(const char *fmt1, ...)
{
	int		sum;
	t_arg	*r;
	va_list	ap;
	char	*ptr;

	sum = 0;
	if (!fmt1)
		return (-1);
	if (fmt1[0] == '%' && fmt1[1] == '\0')
		return (0);
	r = (t_arg*)malloc(sizeof(t_arg));
	ptr = ft_strdup(fmt1);
	r->fmt = ptr;
	va_start(ap, fmt1);
	obnulenie2036(r);
	sum += pars(r, ap);
	va_end(ap);
	free(ptr);
	free(r);
	return (sum);
}
