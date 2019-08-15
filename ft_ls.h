/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmncube <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 11:03:18 by nmncube           #+#    #+#             */
/*   Updated: 2019/08/15 12:50:15 by nmncube          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
#include "libft/libft.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <dirent.h>
#include <stdlib.h>
#include <fcntl.h>
#include <grp.h>
#include <time.h>
#include <pwd.h>
#include <uuid/uuid.h>

void ft_ls(int total);
void ft_bubble_sort(char **arr , int n);
void ft_details(char **arr,int total);
void ft_mod(char **arr , int total);
#endif
