/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmncube <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 11:03:18 by nmncube           #+#    #+#             */
/*   Updated: 2019/09/12 10:32:34 by nmncube          ###   ########.fr       */
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

typedef struct options
{
	int l;
	int a;
	int t;
	int r;
	int R;
}flags;

char **ft_array(char *folder,int bfound);
int ft_count(char *folder,int bfound);
void ft_options(char *folder,int c,char **argc);
char **ft_bubble_sort(char **arr , int n);
void ft_details(char *folder,char **arr,int total,int bfound);
char **ft_mod(char *folder,char **arr , int total);
void ft_display(char **arr,int total,int bfound);
#endif
