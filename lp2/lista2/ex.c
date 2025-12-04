#include <stdio.h>
#include <unistd.h>
void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, &*str, 1);
		str++;
	}
}

int	main(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 1;

	while (i < argc)
	{
	printf("%s\n", argv[i]);
	i++;
	}
	return (0);
}
