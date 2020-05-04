/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalyo <al.kovalyov@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 11:01:09 by akovalyo          #+#    #+#             */
/*   Updated: 2020/05/04 11:01:49 by akovalyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void print_width(t_printf *flags, char fill)
{
    while (flags->width_val > 0)
        {
            putchar_count(flags, fill);
            flags->width_val--;
        }
}

void print_precis_di(t_printf *flags)
{
    while (flags->precis_val > 0)
        {
            putchar_count(flags, '0');
            flags->precis_val--;
        }
}