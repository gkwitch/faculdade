//Pegue o código do ex anterior. Agora, além da média, você deve descobrir qual foi o **maior** e o **menor** número digitado.

#include <stdio.h>

int	main(void)
{
	long int	i, n, maior, menor;
	float	media;

	i = 0;
	n = 0;
	
	while(1)
	{
		printf("Digite um numero inteiro: \n");
		scanf("%ld", &n);

		if (n < 0)
			break;
		if (i == 0)
		{
			maior = n;
			menor = n;
		}
		else
		{
			if (n >= maior)
				maior = n;
			if (n <= menor)
				menor = n;
		}

		media += n;
		i++;
	}

	if (i > 0)
	{
		media = media / i;
		printf("A media e: %.2f\n", media);
		printf("O maior: %ld\n", maior);
		printf("O menor: %ld\n", menor);
	}
	else
		printf("Nenhum numero valido digitado\n");

	return (0);
}
