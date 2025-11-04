#include <stdio.h>

int	main(void)
{
	int	a;
	int 	suc;

	printf("Digite um numero inteiro: ");
	scanf("%d", &a);
	
	a -= 1;
	suc = a + 2;
	printf("\nSeu antecessor e %d e seu sucessor e %d\n", a, suc);

	return(0);
}
