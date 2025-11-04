#include <stdio.h>

int	main(void)
{
	float	lado;
	float	area;

	printf("Digite o lado do quadrado: ");
	scanf("%f", &lado);
	area = lado * lado;

	printf("A area e: %.1f\n", area);
	return(0);
}
