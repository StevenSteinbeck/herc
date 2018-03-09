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

char	*name(char *buffer)
{	
	char *str;	
	int size;
	
	size = 0;
	if (buffer == NULL)
	{
		printf("%s", "Invalid input format, try: \"stestein : e1z1r3p33\"");
		return(NULL);
	}
	if (*buffer < 'A' || *buffer > 'z')
	{
		printf("%s", "Invalid input format, try: \"stestein : e1z1r3p33\"");
		return (NULL);
	}
	if (*buffer != ':')
	{	
		while (buffer[size] != ' ')
			size++;
		str = (char *)malloc(sizeof(*str) * size + 1);
		size = 0;
		while (*buffer >= 'A' && *buffer <= 'z' && *buffer != ' ')
		{
			str[size] = *buffer;
			size++;
			buffer++;
		}
	}
	return (str);
}

int	zone(char *buffer)
{
	int i;
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

int	comp(char *buffer)
{
	int i;
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
	str = "     _    _      _   _     _    _     _   _      _   _     _    _     _   _     _ \n  _   _  _        _ _   _   _  _   _   _ _        _ _   _   _  _   _   _ _       _\n _ _        _  _   _   _ _        _ _       _  _   _   _ _        _ _       _ _     \n    _      _    _     _   _      _   _     _    _     _   _      _   _     _   _  \n     _    _                _    _     _   _           _    _     _   _       \n    _      _    _     _   _      _   _     _    _     _   _      _   _     _      \n   _        _  _   _   _ _        _ _      _  _   _   _ _        _ _       _     \n      _  _        _ _   _   _  _       _ _        _ _   _   _  _       _ _        \n     _     _      _   _     _    _     _   _      _   _     _    _     _   _       \n            _    _                _   _     _    _                _   _     _      \n           _       _   _     _    _     _   _      _   _     _    _     _   _       \n          _        _ _   _   _  _       _ _        _ _   _   _  _       _ _        \n         _   _  _   _   _ _        _ _   _   _  _   _   _ _        _ _   _   _     \n            _    _     _   _      _   _     _    _     _   _      _   _     _      \n                                                                                    \n                                                                                   \n                _     _   _      _   _     _    _     _   _      _   _            \n               _   _   _          _ _   _   _  _   _   _          _ _    _        \n                  _ _       _  _   _   _          _ _       _  _   _   _          \n                 _   _          _     _          _   _     _    _     _          \n                _     _   _                _    _     _   _                       \n                 _   _          _     _          _   _     _    _     _           \n                  _ _      _                         _     _    _     _           \n                       _ _                             _ _        _ _             \n                      _   _                           _   _      _   _            \n                     _     _                         _     _    _                 \n                      _   _                           _   _      _            \n                       _                               _ _        _                  \n                     _   _   _                       _   _   _  _   _             \n                      _                               _     _    _                     \n\0";

	return (str);
}

char	*zone3_map(void)
{
	char *str;

	str = (char *)malloc(sizeof(*str) * 460);
	str = "    ____ _____ _____ _____ __\n   __ __ __ __ __ __ __ __ __\n   __ __ __ __ __ __ __ __ __\n   __ __ __ __ __ __ __ __ __\n   __ __ __ __ __ __ __ __ __\n                             \n                             \n _ __ __ __ __ __ __ __ __ __\n__ __ __ __ __ __ __ __ __ __\n__ __ __ __ __ __ __ __ __ __\n__ __ __ __ __ __ __ __ __ __\n_____ _____ _____ _____ _____\n\0";

	return(str);
}

char	*zone1_updater(char *map, int com)
{
	char *str = map;
	int r;
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
	if (com > 341)
	{
		printf("%s", "WE HAVE ELIMINATED ");
		printf("%i", com - 341);
		printf("%s", " PERSONS(S) FOR YOU \n");
		com = 341;
		j = 1;
	}
	p = com;
	i = 0;
	if (com == 0)
		tmp[27] = 'X';
	
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

char	*zone2_updater(char *map, int com)
{
	char *str = map;
	int r;
	int i = 0;
	int n = 0;
	char *tmp;
	int p;
	int j;	
	
	j = 0;
	tmp = (char *)malloc(sizeof(*tmp) * 2400);
	while (str[i])
	{
		tmp[i] = str[i];
		i++;
	}
	if (com > 311)
	{
		printf("%s", "                       WE HAVE ELIMINATED ");
		printf("%i", com - 311);
		printf("%s", " PERSONS(S) FOR YOU \n");
		com = 311;
		j = 1;
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

char	*zone3_updater(char *map, int com)
{
	char *str = map;
	int r;
	int i = 0;
	int n = 0;
	char *tmp;
	int j;
	int p;
	
	j = 0;
	tmp = (char *)malloc(sizeof(*tmp) * 460);
	while (str[i])
	{
		tmp[i] = str[i];
		i++;
	}
	if (com > 196)
	{
		printf("%s", "WE HAVE ELIMINATED ");
		printf("%i", com - 196);
		printf("%s", " PERSONS(S) FOR YOU\n");
		com = 196;
		j = 1;
	}
	p = com;
	i = 0;
	if (com == 0)
		tmp[4] = 'X';
	
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
	char *buffer = getdata();
	char *newmap;
	char *newbuff;

	newmap = (char *)malloc(sizeof(*newmap) * 2400);
	
		printf("\n\n%s", "             :::::::::    :::                :::::::::    :::\n");
		printf("%s", "           :+:           :+:    :--:       :+:           :+:     :--:    ***   :::\n");	
		printf("%s", "         +:+ +:+ +:+  ::+:+:: :+:+:+     +:+ +:+ +:+  ::+:+:: :+:+:+    +:+   +:+:+:+:+\n");
		printf("%s", "               +:+    +:+    :+:               +:+    +:+    :+:       +:+   +:+   +:+\n");
		printf("%s", "      +#+#+#+#+#+    +#+      +#+#+#  +#+#+#+#+#+    +#+      +#+#+# +#+   +#+   +#+\n");
		printf("\n\n%s\n\n", "This program prints logically from left to right, starting from 0");	
	while (strlen(buffer) != 0){

	if (zone(buffer) == 1)
	{	
		printf("\n%s", "             :::      ::::::::\n");
		printf("%s", "           :+:      :+:    :+:\n");	
		printf("%s", "         +:+ +:+    SV    +:+ \n");
		printf("%s", "        +#+  +:+       +#+ \n ");
		printf("%s", "      +#+#+#+#+#+   +#+    \n ");
		printf("%s", "           #+#    #+#      \n ");
		printf("%s", "          ###   ########.us \n");
		printf("\n%s\n\n", "		ZONE 1");
		printf("%s", " 	        ");
		printf("%s\n\n", name(buffer));
		if (strlen(buffer) != 0)
			newmap = zone1_updater(zone1_map(), comp(buffer));
		printf("%s", newmap);
		printf("\n");
	}
	
	if (zone(buffer) == 2)
	{
		printf("\n%s", "	        	               :::      ::::::::\n");
		printf("%s", "				     :+:      :+:    :+:\n");	
		printf("%s", "				   +:+ +:+    SV    +:+ \n");
		printf("%s", "				  +#+  +:+       +#+ \n ");
		printf("%s", "				+#+#+#+#+#+   +#+    \n ");
		printf("%s", "				     #+#    #+#      \n ");
		printf("%s", "				    ###   ########.us \n");
		printf("\n%s\n\n", "		 		         ZONE 2");
		printf("%s", "     		                         ");
		printf("%s\n\n", name(buffer));
		if (strlen(buffer) != 0)
			newmap = zone2_updater(zone2_map(), comp(buffer));
		printf("%s", newmap);
		printf("\n");
	}
								
	if (zone(buffer) == 3)
	{	
		printf("\n%s", "          :::      ::::::::\n");
		printf("%s", "        :+:      :+:    :+:\n");	
		printf("%s", "      +:+ +:+    SV    +:+ \n");
		printf("%s", "     +#+  +:+       +#+ \n ");
		printf("%s", "   +#+#+#+#+#+   +#+    \n ");
		printf("%s", "        #+#    #+#      \n ");
		printf("%s", "       ###   ########.us \n");
		printf("\n%s\n\n", "	    ZONE 3");
		printf("%s", "            ");
		printf("%s\n\n", name(buffer));

		
		if (strlen(buffer) != 0)
			newmap = zone3_updater(zone3_map(), comp(buffer));
		printf("%s", newmap);
		printf("\n");
	}	
	while (*buffer != '\n')
		buffer++;
	buffer++;
	}
	return(0);
}
