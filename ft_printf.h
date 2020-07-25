/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazumanoda <kazumanoda@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 01:13:36 by kazumanoda        #+#    #+#             */
/*   Updated: 2020/07/25 17:41:45 by kazumanoda       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>
# include "./libft/libft.h"

typedef struct	s_format{
	char		*flag;
	int			fld;
	int			pcn;
	char		*fmt;
}				t_format;

int				my_write(int fd, char *str, unsigned int len);
int				ft_printf(const char *s, ...);
void			print_c(char c, t_format f);
int				dec_len(long n);
void			print_int(int n, t_format f);
void			print_u(unsigned int n, t_format f);
void			print_p(size_t p, t_format f);
void			print_s(const char *s, t_format f);
void			print_x(unsigned int n, t_format f);

#endif
