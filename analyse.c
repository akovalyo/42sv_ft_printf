/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalyo <al.kovalyov@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/31 18:11:08 by akovalyo          #+#    #+#             */
/*   Updated: 2020/04/03 13:16:09 by akovalyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void    analyse_width(t_flag *flags, t_output *print)
{
    
    if (print->body_len < flags->width) 
    {
        if (!(flags->minus))
            print->pref_len = flags->width - print->body_len;
        else if (flags->minus)
            print->postf_len = flags->width - print->body_len;
        if (print->x_prefix && !(flags->zero))
            flags->width -= ft_strlen(print->x_prefix);
    }
    if (flags->specf == 'c' || flags->specf == 's')
        print->cmplt = 0;
    if (print->cmplt && flags->zero && print->pref_len > 0)
        print->prefix = '0';
}

void     analyse_sharp(t_flag *flags, t_output *print)
{
    if (flags->xo && flags->specf == 'x')
    {
        if (flags->plus)
            print->x_prefix = ft_strdup("+0x");
        else
            print->x_prefix = ft_strdup("0x");
    }
    else if (flags->xo && flags->specf == 'X')
    {
        if (flags->plus)
            print->x_prefix = ft_strdup("+0X");
        else
            print->x_prefix = ft_strdup("0X");
    }       
    else if (flags->xo && flags->specf == 'o' && print->prefix != '0')
        print->x_prefix = ft_strdup("0");
    if (print->x_prefix)
    {
        if (ft_strlen(print->x_prefix) == 3)
            flags->plus = 0;
    }
}

void    analyse_spplus(t_flag *flags, t_output *print)
{
    if (flags->specf == 'd' || flags->specf == 'i' || flags->specf == 'p')
    {
        if (!(flags->plus) && !(flags->width))
        {
            print->spplus = ' ';
            print->count++;
        }
        else if (flags->plus)
        {
            print->spplus = '+';
            if (flags->width > print->body_len)
                print->pref_len--;
            print->count++;
        }
    }
}

void	analyse_precis(t_flag *flags, t_output *print)
{
	char	*output;
	int		len;

	len = ft_strlen(print->body);
	if (flags->specf == 's' && flags->precis >= 0 && flags->precis < len)
	{
		output = ft_strnew(flags->precis);
		ft_memmove(output, print->body, flags->precis);
		print->body = ft_strdup(output);
		ft_strdel(&output);
	}
    if (flags->specf == 'f' || flags->specf == 'F')
    {
        print->pref_len = (flags->precis > print->pref_len) ? 0 : print->pref_len - flags->precis;
        print->postf_len = (flags->precis > print->postf_len) ? 0 : print->postf_len - flags->precis;
    }
}