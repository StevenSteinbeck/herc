#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

char	*getdata(void)
{
	char *buffer = 0;
	long length;
	char *str;
	char *name;
	int i;
	FILE * f = fopen ("log.txt", "r");

	if (f)
	{
  		fseek (f, 0, SEEK_END);
  		length = ftell (f);
  		fseek (f, 0, SEEK_SET);
  		buffer = malloc (length);
  		if (buffer)
    			fread (buffer, 1, length, f);
  		fclose (f);
	}
	return (buffer);		
}

char	*name(void)
{
	char *str;
	char *buffer = getdata();
	int i;
	int size;
	
	i = 0;
	size = 0;
	if (buffer == NULL)
	{
		printf("%s", "Invalid input format, try: \"stestein : e1z1r3p33\"");
		return(NULL);
	}
	if (buffer[i] < 'A' || buffer[i] > 'z')
	{
		printf("%s", "Invalid input format, try: \"stestein : e1z1r3p33\"");
		return (NULL);
	}
	if (buffer[i] != ':')
	{	
		while (buffer[size] != ' ')
			size++;
		str = (char *)malloc(sizeof(*str) * size + 1);
		size = 0;
		while (buffer[i] >= 'A' && buffer[i] <= 'z' && buffer[i] != ' ')
		{
			str[size] = buffer[i];
			size++;
			i++;
		}
	}
	return (str);
}

int	zone(void)
{
	int i;
	char *buffer = getdata();
	int zone;
	
	i = 0;
	zone = 0;
	while (zone == 0)
	{
		while (buffer[i] != ':')
			i++;
		while (buffer[i] != 'z')
			i++;
		i++;
		zone = atoi(&buffer[i]);
	}
	return (zone);
}

int	row(void)
{
	int i;
	char *buffer = getdata();
	int zone;
	int row;
	
	i = 0;
	row = 0;
	zone = 0;
	while (row == 0)
	{
		while (buffer[i] != ':')
			i++;
		while (buffer[i] != 'z')
			i++;
		i++;
		zone = atoi(&buffer[i]);
		i = i + 2;
		row = atoi(&buffer[i]);
	}
	return (row);
}

int	comp(void)
{
	int i;
	char *buffer = getdata();
	int zone;
	int seat;
	int row;
	char *comp;
	int c;
	int size;
	
	zone = 0;
	size = 0;
	seat = 0;
	row = 0;
	i = 0;
	c = 0;
	while (buffer[i] != '\n')
	{
		while (buffer[i] != ':')
			i++;
		while (buffer[i] != 'z')
			i++;
		i++;
		zone = atoi(&buffer[i]);
		i = i + 2;
		row = atoi(&buffer[i]);
		i = i + 2;
		while (buffer[i] >= '0' && buffer[i] <= '9')
		{
			size = i;
			while(buffer[size] != '\n')
				size++;
			comp = (char *)malloc(sizeof(*comp) * size + 1);
			while(buffer[i] != '\n')
			{	
				comp[c] = buffer[i];
				i++;
				c++;
			}
		}
	}
	return (atoi(comp));
}

char	*zone1_map(void)
{
	char *str;
	
	str = (char *)malloc(sizeof(*str) * 828);
     	str = "                           ________\n                               ____\n                                   \n   ______________  _____________  _\n   ______________  _____________  _\n                                   \n________________  _____________  __\n________________  _____________  __\n                                   \n    ___________  _____________  ___\n    ___________  _____________  ___\n                                   \n       _______  _____________  ____\n       _______  _____________  ____\n                                   \n          ___  _____________  _____\n          ___  _____________  _____\n                                   \n              _____________  ______\n              _____________  ______\n                                   \n                  ________  _______\n                  ________  _______\n\0";

	return (str);
}

char	*zone2_map(void)
{
	char *str;
	
	str = (char *)malloc(sizeof(*str) * 2400);
	str = "     _    _      _   _     _    _     _   _      _   _     _    _     _   _     _ \n  _   _  _        _ _   _   _  _   _   _ _        _ _   _   _  _   _   _ _       _\n _ _        _  _   _ _        _ _       _  _   _   _ _        _ _   _   _ _   \n    _      _    _     _   _      _   _     _    _     _   _      _   _     _   _  \n     _    _                _    _     _   _           _    _     _   _       \n    _      _    _     _   _      _   _     _    _     _   _      _   _     _      \n   _        _  _   _   _ _        _ _      _  _   _   _ _        _ _       _     \n      _  _        _ _   _   _  _       _ _        _ _   _   _  _       _ _        \n     _     _      _   _     _    _     _   _      _   _     _    _     _   _       \n           _    _                _   _     _    _                _   _     _      \n          _       _   _     _    _     _   _      _   _     _    _     _   _       \n         _        _ _   _   _  _       _ _        _ _   _   _  _       _ _        \n        _   _  _   _   _ _        _ _   _   _  _   _   _ _        _ _   _   _     \n           _    _     _   _      _   _     _    _     _   _      _   _     _      \n                                                                                    \n                                                                                   \n                _     _   _      _   _     _    _     _   _      _   _            \n               _   _   _          _ _   _   _  _   _   _          _ _    _        \n                  _ _       _  _   _   _          _ _       _  _   _   _          \n                 _   _          _     _          _   _     _    _     _          \n                _     _   _                _    _     _   _                       \n                 _   _          _     _          _   _     _    _     _           \n                  _ _     _                         _     _    _     _           \n                       _ _                             _ _        _ _             \n                      _   _                           _   _      _   _            \n                     _     _                         _     _    _                 \n                      _   _                           _   _      _            \n                        _                               _ _        _                  \n                     _   _   _                       _   _   _  _   _             \n                      _                               _     _    _                     \n";

	return (str);
}

char	*zone3_map(void)
{
	char *str;

	str = (char *)malloc(sizeof(*str) * 460);
	str = "    ____ _____ _____ _____ __\n   __ __ __ __ __ __ __ __ __\n   __ __ __ __ __ __ __ __ __\n   __ __ __ __ __ __ __ __ __\n   __ __ __ __ __ __ __ __ __\n                             \n                             \n _ __ __ __ __ __ __ __ __ __\n__ __ __ __ __ __ __ __ __ __\n__ __ __ __ __ __ __ __ __ __\n__ __ __ __ __ __ __ __ __ __\n_____ _____ _____ _____ _____\n\0";

	return(str);
}

char	*zone1_updater(void)
{
	char *str = zone1_map();
	int r;
	int com;
	int i = 0;
	int n = 0;
	char *tmp;
	int j;
	int p;
	
	tmp = (char *)malloc(sizeof(*tmp) * 828);
	while (str[i])
	{
		tmp[i] = str[i];
		i++;
	}
	com = comp();
	if (com > 341)
	{
		com = 341;
		printf("%s", "WE HAVE ELIMINATED THE EXTRAS FOR YOU\n");
	}
	p = com;
	i = 0;
	if (com == 0)
		tmp[27] = 'x';
	
	while (com > 0)
	{
		while (tmp[i] == ' ')
			i++;
		while (tmp[i] == '_' && com > 0)
		{
			i++;
			com--;
		}
		if (tmp[i] == '\n')
			i++;
		while (tmp[i] == ' ')
			i++;
		while (tmp[i] == '\n')
			i++;
		while (tmp[i] == ' ')
			i++;
	}
	if (p != 0)
		tmp[i] = 'X';
	return (tmp);
}

char	*zone2_updater(void)
{
	char *str = zone2_map();
	int r;
	int com;
	int i = 0;
	int n = 0;
	char *tmp;
	int j;
	int p;
	
	tmp = (char *)malloc(sizeof(*tmp) * 2400);
	while (str[i])
	{
		tmp[i] = str[i];
		i++;
	}
	com = comp();
	if (com > 311)
	{
		com = 311;
		printf("%s", "WE HAVE ELIMINATED THE EXTRAS FOR YOU\n");
	}
	p = com;
	i = 0;
	if (com == 0)
		tmp[5] = 'X';
	
	while (com > 0)
	{
		while (tmp[i] == ' ')
			i++;
		while (tmp[i] == '_' && com > 0)
		{
			i++;
			com--;
		}
		while (tmp[i] == '\n')
			i++;
		while (tmp[i] == ' ')
			i++;
		while (tmp[i] == '\n')
			i++;
		while (tmp[i] == ' ')
			i++;
	}
	if (p != 0)
		tmp[i] = 'X';
	return (tmp);
}

char	*zone3_updater(void)
{
	char *str = zone3_map();
	int r;
	int com;
	int i = 0;
	int n = 0;
	char *tmp;
	int j;
	int p;
	
	tmp = (char *)malloc(sizeof(*tmp) * 460);
	while (str[i])
	{
		tmp[i] = str[i];
		i++;
	}
	com = comp();
	if (com > 196)
	{
		com = 196;
		printf("%s", "TOO MANY PEOPLE FOR 42\n");
	}
	p = com;
	i = 0;
	if (com == 0)
		tmp[4] = 'x';
	
	while (com > 0)
	{
		while (tmp[i] == ' ')
			i++;
		while (tmp[i] == '_' && com > 0)
		{
			i++;
			com--;
		}
		while (tmp[i] == '\n')
			i++;
		while (tmp[i] == ' ')
			i++;
		while (tmp[i] == '\n')
			i++;
		while (tmp[i] == ' ')
			i++;
	}
	if (p != 0)
		tmp[i] = 'X';
	return (tmp);
}
	
int	main(void)
{
	if (zone() == 1)
	{	
		printf("\n%s", "       :::      ::::::::\n");
		printf("%s", "     :+:      :+:    :+:\n");	
		printf("%s", "   +:+ +:+    SV    +:+ \n");
		printf("%s", "  +#+  +:+       +#+ \n ");
		printf("%s", "+#+#+#+#+#+   +#+    \n ");
		printf("%s", "     #+#    #+#      \n ");
		printf("%s", "    ###   ########.us \n");
		printf("\n%s\n\n", "Zone 1");
		printf("%s", zone1_updater());
		printf("\n");
	}
	if (zone() == 2)
	{
		printf("\n%s", "       :::      ::::::::\n");
		printf("%s", "     :+:      :+:    :+:\n");	
		printf("%s", "   +:+ +:+    SV    +:+ \n");
		printf("%s", "  +#+  +:+       +#+ \n ");
		printf("%s", "+#+#+#+#+#+   +#+    \n ");
		printf("%s", "     #+#    #+#      \n ");
		printf("%s", "    ###   ########.us \n");
		printf("\n%s\n\n", "Zone 2");
		printf("%s", zone2_updater());
		printf("\n");
	}
	if (zone() == 3)
	{	
		printf("\n%s", "       :::      ::::::::\n");
		printf("%s", "     :+:      :+:    :+:\n");	
		printf("%s", "   +:+ +:+    SV    +:+ \n");
		printf("%s", "  +#+  +:+       +#+ \n ");
		printf("%s", "+#+#+#+#+#+   +#+    \n ");
		printf("%s", "     #+#    #+#      \n ");
		printf("%s", "    ###   ########.us \n");
		printf("\n%s\n\n", "Zone 3");
		printf("%s", zone3_updater());
		printf("\n");
	}	
	return(0);
}
