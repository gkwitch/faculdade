#include <stdio.h>

int	main(void)
{
	float	real;
	float	dol;
	float	conv;

	printf("Digite um valor em real: ");
	scanf("%f", &real);

	printf("\nDigite um valor em dolar: ");
	scanf("%f", &dol);
	
	conv = real / dol;
	printf("\nSeu valor em dolar: %.2f\n", conv);
	
	return(0);
}
