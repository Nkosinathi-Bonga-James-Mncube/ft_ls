/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmncube <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 14:55:00 by nmncube           #+#    #+#             */
/*   Updated: 2019/09/12 16:53:31 by nmncube          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdio.h>
//REMEBER TO CLOSE DIR/FILE!!!!!!!!!!!

/*void ft_check ()
{

}*/
char **ft_ls(char *folder,int total,int bfound,struct dirent *dp)
{
	DIR				*dir;
	int				k;
	char			**arr;
	char **hold2;//remove
	//char **s1;
	
	dir = opendir(folder);
	k = 0;
	if (dir == NULL)
	{
		//dir = opendir(".");//remove
		ft_putstr("Cannot open");
		exit(1);
	}
	arr = (char**)malloc(total * sizeof(char*));
	//hold2 = (char**)malloc(1* sizeof(char*));
	while ((dp = readdir(dir)) != NULL && total > 0)
	{
		if (dp->d_name[0] != '.' && bfound != 1)
		{
			arr[k] = ft_strdup(dp->d_name);
			k++;
		}
		if (bfound == 1)
		{
			arr[k] = ft_strdup(dp->d_name);
			k++;
		}
		/*if (ft_strcmp(arr[k],folder) == 0)
		{
			ft_putstr(folder);
			//hold2[0] = ft_strdup(folder);
			//break;
		}*/
	}
	//printf("Current folder :%s\n",folder);
	/*while (total > 1)
	{
		printf("%s\n",arr[total-1]);
		//if (ft_strcmp(arr[total],folder) == 0)
		//{
		//	hold2[0] = ft_strdup(folder);
			//ft_putstr(">>Present>>");
		//	break;
		//}
		//total--;
	}*/
	//s1 = arr;
	//free(arr);
	//arr =s1;
	//ft_bubble_sort(arr, total,0);//replace 0 with bfound
	//ft_details(arr, total, bfound);
	//ft_mod(arr, total);
	//ft_display(arr,total,0);
	//free(dir);//DIR LEAKS! Remember to free them!
	return (arr);
}

char **ft_array(char *folder,int bfound)
{
	int total;
	char **hold;
	//char ** hold2;
	struct dirent *dp;

	total = 0;
	//total = total + ft_count(bfound);
	hold = ft_ls(folder,ft_count(folder,bfound),bfound,dp);
	/*hold2 = hold;
	while (total >= 0)
	{
		free(hold[total]);
		total--;
	}
	hold = hold2;*/
	return (hold);
}
