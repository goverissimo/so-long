#include "so_long.h"

int simp_strlen(char *str)
{
	int i;
	i = 0;
	while (str[i] && str[i] != '\n' && str[i] != ' ')
		i++;
	return (i);
}