
#include "libft.h"

int ft_isdigitstr(char *s) // Ajouter a la lib
{
	if (!s)
		return (0);
	while (*s == ' ')
		s++;
	if (*s == '-')
		s++;
	while (*s)
		if (ft_isdigit(*s) || *s == ' ')
			s++;
	return ((*s == '\0') ? 1 : 0);
}
