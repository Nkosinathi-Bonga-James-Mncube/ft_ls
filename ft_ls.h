/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmncube <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 11:03:18 by nmncube           #+#    #+#             */
/*   Updated: 2019/12/01 14:55:48 by nmncube          ###   ########.fr       */
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
void ft_display(char *folder,char **arr,int total,int bfound);
void ft_dir_search(char *folder,char **y,int *b);
int ft_s(char *folder);
int ft_arv_count(char **argv);
void ft_folder_name(int l,int bfound, struct stat b,char *folder);
void ft_free(char *x,char **arr,int total);
#endif
