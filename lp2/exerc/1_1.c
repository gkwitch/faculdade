//Faça um programa que peça números inteiros ao usuário infinitamente. O programa só para quando o usuário digitar um número negativo.
#include <stdio.h>

int	main(void)
{
	int	i;
	int	n;
	float	media;

	media = 0;
	i = 0;

	while(1)
	{
		printf("Digite um número inteiro: \n");	
		scanf("%d", &n);

		if (n < 0)
			break;
		media += n;
		i++;
	}

	if (i > 0)
	{	
		media = media / i;
		printf("A media e: %.2f\n", media);
	}
	else
		printf("Nenhum numero valido digitado.");

	return (0);
}
