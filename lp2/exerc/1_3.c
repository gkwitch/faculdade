//e o número lido for impar, multiplique-o no acumulador de produto. Se for par, some-o no acumulador de soma.

#include <stdio.h>

int     main(void)
{
        long int     i, n, maior, menor, impares, pares;
        float   media;

        i = 0;
        n = 0;
	pares = 0;
	impares = 1;

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
                if (n % 2)
	                impares *= n;
		else
			pares += n;
		            
                media += n;
                i++;
        }

        if (i > 0)
        {
                media = media / i;
                printf("A media e: %.2f\n", media);
                printf("O maior: %ld\n", maior);
                printf("O menor: %ld\n", menor);
                printf("A soma dos pares: %ld\n", pares);
                printf("O produto dos impares: %ld\n", impares);
        }
        else
                printf("Nenhum numero valido digitado\n");

        return (0);
}
