/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmncube <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 11:03:18 by nmncube           #+#    #+#             */
/*   Updated: 2019/08/05 14:52:54 by nmncube          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef FT_LS
# define FL_LS
#include "libft/libft.h"
#include <sys/types.h>
#include <string.h>
#include <dirent.h>
#include <stdlib.h>

void ft_ls(char *s1);
void ft_bubble_sort(char **arr , int n);
#endif
