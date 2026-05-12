#include <stdio.h>

#define TAM 50

typedef struct no {
	int valor;
	int prioridade;
} tno;

typedef struct fila {
	int ini;
	int fim;
	tno no[TAM];
} tfila;

void cria_fila (tfila *fila)
{
	fila->ini = 0;
	fila->fim = -1;
}

int fila_vazia (tfila *fila)
{
	return (fila->ini > fila->fim); 
}

int fila_cheia (tfila *fila)
{
	return (fila->fim == TAM -1);
}

int enfileirar (tfila *fila, tno chave)
{
	if (fila_cheia(fila) == 1)
	{
		printf("Não foi possivel enfileirar, pois a fila está cheia.");
		return 0;
	}
	fila->fim++;
	
	fila->no[fila->fim] = chave;
	return;
}

int desenfileirar (tfila *fila, tno *chave)
{
	if (fila_vazia(fila) == 1)
	{
		printf("Não foi possivel desenfileirar, pois a lista está vazia.");
		return 0;
	} 
	*chave = fila->no[fila->ini];
	fila->ini++;
	return 1;
}

int enfileirar_prioridade (tfila *fila, tno chave)
{
	tno chave_temp;
	tfila auxiliar;
	cria_fila(&auxiliar);
	
	while ((fila_vazia(fila) == 0) && (fila->no[fila->ini].prioridade >= chave.prioridade))
	{
		desenfileirar(fila, &chave_temp);
		enfileirar(&auxiliar, chave_temp);
	}
	enfileirar (&auxiliar, chave);
	
	while (fila_vazia(fila) != 1)
	{
		desenfileirar (fila, &chave_temp);
		enfileirar (&auxiliar, chave_temp);
	}
	
	while (fila_vazia(&auxiliar)!= 1)
	{
		desenfileirar (&auxiliar, &chave_temp);
		enfileirar (fila, chave_temp);
	}
	return 1;
}

void imprimir_fila (tfila *fila)
{
	int i;
	if (fila_vazia(fila) == 1) {
        printf("A fila esta vazia.\n");
        return;
    }
	for (i = fila->ini; i <= fila->fim; i++)
	{
		printf("\nDADOS FILA\n");
		printf("Valor: %d\n", fila->no[i].valor);
		printf("Prioridade: %d\n", fila->no[i].prioridade);
	}
}

int main() {
    tfila minha_fila;
    cria_fila(&minha_fila);
    tno item;

    printf("INICIANDO TESTES DA FILA COM PRIORIDADE\n");

    item.valor = 100;
    item.prioridade = 10;
    enfileirar_prioridade(&minha_fila, item);
    printf("Entrou Valor: %d | Prioridade: %d\n", item.valor, item.prioridade);

    item.valor = 200;
    item.prioridade = 50;
    enfileirar_prioridade(&minha_fila, item);
    printf("Entrou Valor: %d | Prioridade: %d (Deve ir pro inicio)\n", item.valor, item.prioridade);

    item.valor = 300;
    item.prioridade = 5;
    enfileirar_prioridade(&minha_fila, item);
    printf("Entrou Valor: %d | Prioridade: %d (Deve ir pro final)\n", item.valor, item.prioridade);

    item.valor = 400;
    item.prioridade = 10;
    enfileirar_prioridade(&minha_fila, item);
    printf("Entrou Valor: %d | Prioridade: %d (Empate! Fica atras do Valor 100)\n", item.valor, item.prioridade);

    imprimir_fila(&minha_fila);

    return 0;
}
