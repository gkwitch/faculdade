>[!QUESTION] 1 - Função para retornar se um valor inteiro é par ou ímpar. A função deverá retornar os seguintes valores: a - 0 – PAR b - 1 – ÍMPAR

Primeiro temos uma função não um programa, então ela deve retornar um inteiro, se for par ela retorna 0, se for impar ela retorna 1. 
Para verificar se é par ou impar dividimos o numero por 2 e pegamos o modulo.

```C
int f_par_impar(int a)
{
	if (a % 2 == 0)
		return (0);
	else if(a % 2 != 0)
		return(1);
}
```

>[!QUESTION] 2 - Função para saber se um dado um valor inteiro é primo ou não. A função deverá retornar os seguintes valores: a - 0 – Não é primo b - 1 – É primo

É uma função, então teremos que ela retornara um int. 
Para verificar se é primo temos algumas verificações: 
1 -  numero negativo
2 - o 2
3 - modulo dele dividido por 2 é = o
4 - ir dividindo ele ate chegar nele e se algum dos números for divisível não é primo.
Aqui temos uma jogada matemática, não faz sentido testar os números divisores maiores que a metade do numero, já que o maior divisor que podemos obter um inteiro é a metade do numero que resulta em 2. Por exemplo: 100 / 2 = 50, se formos dividir 100 / 51 ou qualquer numero maior, sempre vai dar quebrado.

```C
int f_primos(int nbr)
{
	int i;
	i = 3;
	
	if (nbr <= 1)
		return (0);
	if (nbr == 2)
		return(1);
	if (nbr % 2 == 0)
		return(0);
	while (i <= nbr / 2) //não testar os numeros maiores que a metade do numero
	{
		if(nbr % 2 == i) //aqui a função acha um divisor, ou seja, o numero não é primo
			return(0);
		i++;	
	}
	return (1);
}
```

>[!QUESTION] 3 - Função para contar os caracteres de uma string.

A função deve retornar um inteiro. Como sabemos uma string termina no caracter '\n', então um loop que vai verificando cada char do vetor string ate achar o final dela. Sendo incrementado o indice.

```C
int f_strlen(char *str)
{
	int i;
	i = 0;
	
	while (str[i])
		i++;
	return (i);
}

```

>[!QUESTION] 4 - Função para, dados dois números inteiros, retornar o MDC.

Gracas aos meus amigos matematicos eu descobri o algoritmo de euclides e depois de muita conversa matematica ficou assim 

```C
int f_mdc(int a, int b)
{
	int resto;

	while (b != 0)
	{
		resto = a % b;
		a = b;
		b = resto;
	}
	return (a);
}
```

>[!QUESTION] 5 - Função para, dado dois numeros inteiros, retornar o MMC

Da pra saber o mmc usando o mdc com o algoritmo de euclides, apenas isolando o mmc.

```C
int f_mmc(int a, int b)
{
	int resto;
	va = a;
	vb = b;

	while (b != 0)
	{
		resto = a % b;
		a = b;
		b = resto;
	}
	return ((va / a) * vb);
}
```

>[!QUESTION] 6 - Função para, dado um vetor (array) de números inteiros, retorne o vetor ordenado. Utilize o bubblesort como algorítimo de ordenação.

Essa porra foi confusa de entender, preciso revisar e tirar duvidas

```C
int f_bubblesort(int *list, int n)
{
	int temp;
	int i;
	int j;
	
	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - i - 1; j++)
		{
			if (list[j] > list[j+1])
			{
				temp = list[j];
				list[j] = list[j+1];
				list[j+1] = temp;
			}
		}
	}
}
```

>[!QUESTION] 7 - Faça um programa em C para dado dois valores, limite inferior e limite superior ([li, ls]) para mostrar todos os números primos existente dentro do intervalo.

Aqui eu usarei a função de descobrir se é primo e fazer um loop para ir guardando os primos que for encontrando. No caso o i do loop que entrará como parametro da função que descobre se é primo, então se retornar 1, o programa salva esse numero em uma array.
Salvando em um array ocupa mais espaço na memoria, pois o intervalo pode ser bem grande ai teria que alocar memoria dinamicamente. Então printar ao achar seria uma maneira melhor.

```C
#include <stdio.h>

int f_primos(int nbr)
{
	int i;
	i = 3;
	
	if (nbr <= 1)
		return (0);
	if (nbr == 2)
		return(1);
	if (nbr % 2 == 0)
		return(0);
	while (i <= nbr / 2) //não testar os numeros maiores que a metade do numero
	{
		if(nbr % i == 0) //aqui a função acha um divisor, ou seja, o numero não é primo
			return(0);
		i++;	
	}
	return (1);
}

int main(void)
{
	int li;
	int ls;
	int i;
	
	scanf("%d",&li);
	scanf("%d", &ls);
	
	if (li > ls)
	{
		printf("limite inválido\n");
		return (0);
	}
	
	for (i = li; i <= ls; i++)
	{
		if (f_primos(i) == 1)
		 printf("%d, ",i);	
	}
	printf("\n");
	return (0);
}
```

>[!QUESTION] 8 - Faça um programa em C para dado dois valores, limite inferior e limite superior ([li, ls]) mostre todos os valores múltiplos de N

quase a mesma coisa dos primos, só que muda a verificação dentro do for.

```C
#include <stdio.h>
int main(void)
{
	int li;
	int ls;
	int i;
	int n;
	
	scanf("%d",&li);
	scanf("%d", &ls);
	scanf("%d", &n);
	
	if (li > ls)
	{
		printf("limite inválido\n");
		return (0);
	}
	
	for (i = li; i <= ls; i++)
	{
		if (i % n == 0)
		 printf("%d, ",i);	
	}
	printf("\n");
	return (0);
}
```

>[!QUESTION] 9 - Refaça os programas dos itens 7 e 8 para retornar o somatório dos valores encontrados

fácil, só trocar o print e adicionar uma variavel que vai somando a cada numero encontrado

```C
#include <stdio.h>

int f_primos(int nbr)
{
	int i;
	i = 3;
	
	if (nbr <= 1)
		return (0);
	if (nbr == 2)
		return(1);
	if (nbr % 2 == 0)
		return(0);
	while (i <= nbr / 2) //não testar os numeros maiores que a metade do numero
	{
		if(nbr % i == 0) //aqui a função acha um divisor, ou seja, o numero não é primo
			return(0);
		i++;	
	}
	return (1);
}

int main(void)
{
	int li;
	int ls;
	int i;
	int soma;
	
	soma = 0;
	
	scanf("%d",&li);
	scanf("%d", &ls);
	
	if (li > ls)
	{
		printf("limite inválido\n");
		return (0);
	}
	
	for (i = li; i <= ls; i++)
	{
		if (f_primos(i) == 1)
		 soma += i;
	}
	printf("A soma dos valores: %d", soma);
	printf("\n");
	return (0);
}
```

O 8:
```C
#include <stdio.h>
int main(void)
{
	int li;
	int ls;
	int i;
	int n;
	int soma;
	
	soma = 0;
	scanf("%d",&li);
	scanf("%d", &ls);
	scanf("%d", &n);
	
	if (li > ls)
	{
		printf("limite inválido\n");
		return (0);
	}
	
	for (i = li; i <= ls; i++)
	{
		if (i % n == 0)
		 soma += n;
	}
	printf("A soma dos valors: %d", soma);
	printf("\n");
	return (0);
}
```

>[!QUESTION] 10 - Refaça os programas dos itens 6, 7, 8 e 9 para armazenar as informações em um arquivo texto e em um arquivo binário

Aqui eu preciso abrir o arquivo antes do loop e trocar para ir escrevendo no arquivo no loop. Tambem preciso fazer a verificação de se o ponteiro de arquivo não retornou NULL. E fechar no final.

6:
```C
int f_bubblesort(int *list, int n)
{
	int temp;
	int i;
	int j;
	
	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - i - 1; j++)
		{
			if (list[j] > list[j+1])
			{
				temp = list[j];
				list[j] = list[j+1];
				list[j+1] = temp;
			}
		}
	}
}
```

7:
```C
#include <stdio.h>

int f_primos(int nbr)
{
	int i;
	i = 3;
	
	if (nbr <= 1)
		return (0);
	if (nbr == 2)
		return(1);
	if (nbr % 2 == 0)
		return(0);
	while (i <= nbr / 2) //não testar os numeros maiores que a metade do numero
	{
		if(nbr % i == 0) //aqui a função acha um divisor, ou seja, o numero não é primo
			return(0);
		i++;	
	}
	return (1);
}

int main(void)
{
	int li;
	int ls;
	int i;
	FILE *primos;
	
	scanf("%d",&li);
	scanf("%d", &ls);
	
	if (li > ls)
	{
		printf("limite inválido\n");
		return (0);
	}
	primos = fopen("primos.txt", "w");
	
	if (primos == NULL)
	{
		printf("não foi possivel abrir o arquivo\n");
		return (0);
	}
	else 
	{
		for (i = li; i <= ls; i++)
		{
			if (f_primos(i) == 1)
			 fprintf(primos, "%d" , i);	
		}
	}
	fclose(primos);
	printf("\n");
	return (0);
}
```

8:
```C
#include <stdio.h>
int main(void)
{
	int li;
	int ls;
	int i;
	int n;
	FILE *multiplos;
	
	scanf("%d",&li);
	scanf("%d", &ls);
	scanf("%d", &n);
	
	if (li > ls)
	{
		printf("limite inválido\n");
		return (0);
	}
	multiplos = fopen("multiplos.txt", "w");
	
	for (i = li; i <= ls; i++)
	{
		if (i % n == 0)
		 fprintf(multiplos, "%d ", i);	
	}
	fclose(multiplos);
	
	printf("\n");
	return (0);
}
```

>[!QUESTION] Em binario:

6:

7:
```C
#include <stdio.h>

int f_primos(int nbr)
{
	int i;
	i = 3;
	
	if (nbr <= 1)
		return (0);
	if (nbr == 2)
		return(1);
	if (nbr % 2 == 0)
		return(0);
	while (i <= nbr / 2) //não testar os numeros maiores que a metade do numero
	{
		if(nbr % i == 0) //aqui a função acha um divisor, ou seja, o numero não é primo
			return(0);
		i++;	
	}
	return (1);
}

int main(void)
{
	int li;
	int ls;
	int i;
	FILE *primos;
	
	scanf("%d",&li);
	scanf("%d", &ls);
	
	if (li > ls)
	{
		printf("limite inválido\n");
		return (0);
	}
	primos = fopen("primos.bin", "wb");
	
	if (primos == NULL)
	{
		printf("não foi possivel abrir o arquivo\n");
		return (0);
	}
	else 
	{
		for (i = li; i <= ls; i++)
		{
			if (f_primos(i) == 1)
			 fwrite(&i ,sizeof(int), 1, primos);	
		}
	}
	fclose(primos);
	printf("\n");
	return (0);
}
```

O 8:
```C
#include <stdio.h>
int main(void)
{
	int li;
	int ls;
	int i;
	int n;
	FILE *multiplos;
	
	scanf("%d",&li);
	scanf("%d", &ls);
	scanf("%d", &n);
	
	if (li > ls)
	{
		printf("limite inválido\n");
		return (0);
	}
	multiplos = fopen("multiplos.bin", "wb");
	
	for (i = li; i <= ls; i++)
	{
		if (i % n == 0)
		 fwrite(&i, sizeof(int), 1, multiplos);	
	}
	fclose(multiplos);
	
	printf("\n");
	return (0);
}

```

>[!QUESTION] 11 - Faça um programa em C para ler os arquivos anteriores e mostrar na tela o conteúdo do arquivo.

aqui preciso fazer o oposto do fprintf, como a função printf só ler o que está na ram eu preciso "pescar" o que está dentro o arquivo. O fscanf faz isso, linha por linha. Então preciso criar uma variavel temporaria para jogar o que o fscanf pra ela printar. Preciso de um loop que irá ler o arquivo ate que chegue ao fim comparando o retorno da função fscanf ao macro EOF, que retorna -1 quando chega ao fim do arquivo. 

```C
#include <stdio.h>
int main(void)
{
	int temp;
	FILE *primos;
	FILE *primos_bin;
	FILE *multiplos;
	FILE *multiplos_bin;
		
	multiplos = fopen("multiplos.txt", "r");
	
	if (multiplos == NULL)
		printf("Não foi possivel abrir o arquivo\n");
	else
	{
		while (fscanf(multiplos, "%d", &temp) != EOF)
			printf("%d\n", temp);
	fclose(multiplos);
	}
	printf("-----\n");
	
	multiplos_bin = fopen("multiplos.bin", "rb");
	
	if (multiplos_bin == NULL)
		printf("Não foi possivel abrir o arquivo\n");
	else
	{
		
		while (fread(&temp, sizeof(int), 1, multiplos_bin) == 1)
			printf("%d", temp);
	fclose(multiplos_bin);
	}
	printf("-----\n");
	
	primos = fopen("primos.txt", "r");
	
	if (primos == NULL)
		printf("Não foi possivel abrir o arquivo\n");
	else
	{
		while (fscanf(primos, "%d", &temp) != EOF)
			printf("%d", temp);
	fclose(primos);
	}
	printf("-----\n");
		
	primos_bin = fopen("primos.bin", "rb");
	
	if (primos_bin == NULL)
		printf("Não foi possivel abrir o arquivo\n");
	else
	{
		while (fread(&temp, sizeof(int), 1, primos_bin) == 1)
			printf("%d", temp);
	fclose(primos_bin);
	}
	return (0);
}
```

>[!QUESTION] 12 - Explique para que serve um arquivo Makefile.

O arquivo Makefile é um arquivo feito para gerenciar a compilação de arquivos. Muito util em projetos grandes onde você tem que compilar muitos arquivos e arquivos que dependem um dos outros.

>[!QUESTION] 13 - Crie um arquivo Makefile para ajudar na compilação de um sistema inteiro, seguindo a seguinte informação. 
>a - O arquivo binário terá o nome projeto_expeimental 
>b - O arquivo binário depende dos arquivos 
>	1 - a.o 
>	2 - b.o 
>	3 - c.o 
>	4 - d.o 
>	5 - e.o 
>c - Os arquivos a,c e b.c depende dos arquivos: 
>	1 - projeto_experimental.h 
>	2 - a.h 
>	3 - b.h 
>4 - funcoes.h 
>	d - Os arquivos c.c e e.c depende dos arquivos: 
>	1 - projeto_experimental.h 
>	2 - c.h 
>	3 - e.h 
>	4 - funcoes.h 
>e - O arquivo d.c depende doarquivo 
>	1 - projeto_experimental.h 
>	2 - d.h

Sabemos que a estrutura do Makefile funciona assim:

alvo: dependencias
	comando
Sendo: 
Alvo, o arquivo que você quer gerar.
Dependencias, o que o seu alvo depende para ser executado.
Comando, o que você quer realizar, no caso usaremos o gcc para compilar.

Para converter o arquivo para objeto (.o) usamos a flag -c no gcc.

Uma boa pratica é colocar o clean no final do makefile para limpar os arquivos .o que foram criados. Quando dermos make, o make executa a primeira regra alvo e depois vai executando as dependecias. O clean só será executado se dermos um make clean.

```makefile

projeto_experimental: a.o b.o c.o d.o e.o
	gcc -o projeto_experimental a.o b.o c.o d.o e.o

a.o: a.c projeto_experimental.h a.h b.h funcoes.h
	gcc -c a.c 
	
b.o: b.c projeto_experimental.h a.h b.h funcoes.h
	gcc -c b.c 
	
c.o: c.c projeto_experimental.h c.h e.h funcoes.h
	gcc -c c.c 
	
d.o: d.c projeto_experimental.h d.h
	gcc -c d.c 
	
e.o: e.c projeto_experimental.h c.h e.h funcoes.h
	gcc -c e.c 
	
clean:
	rm -f *.o projeto_experimental //retira os arquivos
	
```

>[!QUESTION] 14 - Faça um programa em C para ler uma string e mostrar se ela é ou não palindromo.

Um palindromo é uma palavra que de tras pra frente é identica. Temos que percorrer a string e comparar com o inverso dela se for igual, continua rodando, se for diferente para.

```C
#include <stdio.h>
int f_strlen(char *str)
{
	int i;
	
	i = 0;
	while (str[i])
		i++;
	return (i);
}

int palindromo(char *str)
{
	int i;
	int j;
	
	i = 0;
	j = strlen(str) - 1; //o indice começa em 0, então é o tamanho -1
	while (i < j)
	{
		if (str[i] != str[j])
			return (0);
		i++;
		j--;
	}
	return (1);
}

int main(void)
{
	char str[100];
	
	gets_s(str, sizeof(str));
	
	if (palindromo(str) == 1)
		printf("é palindromo\n");
	else
		printf("não é palindromo");
	return (0);
}

```

>[!QUESTION] 15 - Explique a diferença entre cmalloc e malloc, faça um programa em C para exemplificar a diferença.

