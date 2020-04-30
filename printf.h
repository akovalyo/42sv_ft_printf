/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalyo <al.kovalyov@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/23 09:50:41 by akovalyo          #+#    #+#             */
/*   Updated: 2020/04/30 13:46:16 by akovalyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft.h"

typedef struct		s_printf
{
	const char		*specif;
	int 			sp : 4;
	int				i;
	int				count;
	int				zero : 1;
	int				minus : 1;
	int				width : 1;
	int				width_val;


}					t_printf;

typedef void		conv(t_print *flags, va_list *ap);

typedef struct 		s_flag
{
	unsigned int 	zero : 1;
	unsigned int 	plus : 1;
	unsigned int 	minus : 1;
	unsigned int 	sharp : 1;
	unsigned int 	space : 1;
	unsigned int 	perc : 1;
	unsigned int	h_flag : 2;
	unsigned int	l_flag : 2;
	unsigned int	lb_flag : 1;
	unsigned int 	width : 16;
	int				precis : 16;
	unsigned int 	start : 16;
	unsigned int	xo : 1;
	char 			specf;
	char			len;

}					t_flag;

typedef struct 		s_output
{
	char			*body;
	unsigned int	body_len : 16;
	unsigned int	count : 16;
	unsigned int	i : 16;
	unsigned int	cmplt : 1;
	char 			prefix;
	unsigned int	pref_len : 16;
	char			postf;
	unsigned int	postf_len : 16;
	char			*x_prefix;
	unsigned int	x_correct : 16;
	char			spplus;
	unsigned int	free : 1;
}					t_output;

/* typedef enum		e_specif
{
	d = 1, u, c, s, p, x, X, o, f, percent
}					t_specif; */

/*
** get.c
*/

void 				take_sign(t_flag *flags, t_output *print);
void				get_diu(t_flag *flags, va_list *ap, t_output *print);
void				get_sc(t_flag *flags, va_list *ap, t_output *print);
void				get_xo(t_flag *flags, va_list *ap, t_output *print);
void				get_p(t_flag *flags, va_list *ap, t_output *print);
void				get_f(t_flag *flags, va_list *ap, t_output *print);

/*
** analyse.c
*/

void    			analyse_width(t_flag *flags, t_output *print);
void     			analyse_sharp(t_flag *flags, t_output *print);
void   	 			analyse_spplus(t_flag *flags, t_output *print);
void				analyse_precis(t_flag *flags, t_output *print);

/*
** helpers.c
*/

int					hex_ascii(size_t n, int letter);
char				*conv_base(unsigned int nbr, unsigned int base, int letter);
char				*conv_base_uns(size_t nbr, int base, char letter);
void				init_flags(t_flag *flags, int i);
void				init_output(t_output *print);

/*
** print.c
*/

void  				print_pre_post(char ch, int len, t_output *print);
void    			print_oxp(t_flag *flags, t_output *print);
void    			print_output(t_flag *flags, t_output *print);
void				edit_output(t_flag *flags, t_output *print);

/*
** checker.c
*/

int					format_checker(t_flag *flags, const char *str, t_output *print);
int					length_checker(t_flag *flags, const char *str, t_output *print);
int					flag_checker(t_flag *flags, const char *str, t_output *print);
int					precis_checker(t_flag *flags, const char *str, t_output *print);
void				width_checker(t_flag *flags, const char *str, t_output *print);
int					specifier_checker(t_flag *flags, const char *str, t_output *print);

/*
** ft_printf.c
*/

void				create_output(t_flag *flags, va_list *ap, t_output *print);
int					ft_printf(const char *format, ...);


#endif
