int ft_error(char *s1)
{
	FILE * pFile;
	int i;
	pFile=fopen (s1,"rb");
	i = 0;
	if (pFile==NULL)
	{
			ft_putstr("ls: cannot open directory ");
			ft_putstr("'");
			ft_putstr(s1);
			ft_putstr("'");
			ft_putchar(' ');
			ft_putstr(": ");
			ft_putstr(strerror(errno));
			ft_putchar('\n');
			i++;
	}
	else
	{ 
		fclose (pFile);
	}
	return (i);	
}
