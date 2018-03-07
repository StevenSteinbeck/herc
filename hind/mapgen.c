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

int	main(void)
{
	printf("%i", comp());
	return(0);
}
