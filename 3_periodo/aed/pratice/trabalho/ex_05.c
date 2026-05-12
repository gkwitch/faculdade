#include <stdio.h>

#define TAM 50

typedef int tno; 

typedef struct {
    tno no[TAM];
    int cont;
} tlista;

// Inicializa a lista
void cria_lista(tlista *lista) 
{
    lista->cont = 0;
}

int insere_fim(tlista *lista, tno valor)
{
    if (lista->cont >= TAM) 
	{
        printf("Erro: Lista cheia!\n");
        return 0;
    }
    lista->no[lista->cont] = valor;
    lista->cont++;
    return 1;
}

void imprimir_lista(tlista lista, char nome_lista) 
{
    int i;
    printf("\n--- Conteudo da Lista %c ---\n", nome_lista);
    if (lista.cont == 0) {
        printf("A lista esta vazia.\n");
        return;
    }
    for (i = 0; i < lista.cont; i++) 
	{
        printf("Posicao [%d] -> Valor: %d\n", i, lista.no[i]);
    }
    printf("Total de elementos: %d\n", lista.cont);
}

int copia_lista(tlista A, tlista *B) 
{
    int i;
    
    if (B->cont + A.cont > TAM) 
	{
        printf("Erro: A Lista B não tem espaço suficiente para receber todos os itens da Lista A.\n");
        return 0;
    }

    // Percorre todos os itens da lista A
    for (i = 0; i < A.cont; i++) 
	{
        B->no[B->cont] = A.no[i];
        
        B->cont++;
    }
    return 1;
}

int main() 
{
    tlista lista_a, lista_b;

    cria_lista(&lista_a);
    cria_lista(&lista_b);

    // Preenchendo a Lista B com seus itens ini
    insere_fim(&lista_b, 10);
    insere_fim(&lista_b, 20);
    insere_fim(&lista_b, 30);

    // Preenchendo a Lista A com os itens que serao cop
    insere_fim(&lista_a, 40);
    insere_fim(&lista_a, 50);
    insere_fim(&lista_a, 60);

    printf("ESTADO ANTES DA COPIA:");
    imprimir_lista(lista_a, 'A');
    imprimir_lista(lista_b, 'B');

    printf("\nREALIZANDO A COPIA DA LISTA A PARA A LISTA B...\n");
    
    copia_lista(lista_a, &lista_b);

    printf("ESTADO APOS A COPIA:");
    imprimir_lista(lista_a, 'A'); 
    imprimir_lista(lista_b, 'B'); 

    return 0;
}
