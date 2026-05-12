#include <stdio.h>

#define TAM 50

typedef struct no {
    int valor;
    int prioridade;
} tno;

typedef struct pilha {
    int topo;
    tno no[TAM];
} tpilha;

void cria_pilha(tpilha *pilha) {
    pilha->topo = -1;
}

int pilha_vazia(tpilha pilha) {
    if(pilha.topo == -1)
        return 1;
    else 
        return 0;
}

int pilha_cheia(tpilha pilha) {
    if (pilha.topo == TAM - 1)
        return 1;
    else 
        return 0;
}

int empilha(tpilha *pilha, tno chave) {
    if (pilha_cheia(*pilha) == 1) {
        printf("Não foi possível empilhar, pois a pilha está cheia.\n");
        return 0;
    }
    pilha->topo++;
    pilha->no[pilha->topo] = chave;

    return 1;
}

int desempilha(tpilha *pilha, tno *chave) {
    if (pilha_vazia(*pilha) == 1) {
        printf("Não foi possivel desempilhar, pois a pilha está vazia.\n");
        return 0;
    }
    *chave = pilha->no[pilha->topo];
    pilha->topo--;
    return 1;
}

void empilha_prioridade(tpilha *pilha, tno chave) {
    tpilha auxiliar;
    cria_pilha(&auxiliar);
    tno chave_temp;
    
    // Tira os elementos do caminho de acordo com a prioridade
    while ((pilha_vazia(*pilha) == 0) && (pilha->no[pilha->topo].prioridade > chave.prioridade)) {
        desempilha(pilha, &chave_temp);
        empilha(&auxiliar, chave_temp);
    }
    
    // Empilha o novo elemento
    empilha(pilha, chave);
    
    // Devolve os elementos da pilha auxiliar para a original
    while (pilha_vazia(auxiliar) != 1) {
        desempilha(&auxiliar, &chave_temp);
        empilha(pilha, chave_temp);
    }
}

void imprimir_pilha(tpilha *pilha) {
    int i;
    if (pilha_vazia(*pilha) == 1) {
        printf("Não foi possivel imprimir a pilha, pois a pilha está vazia.\n");
        return;
    }
    for (i = pilha->topo; i >= 0; i--) {
        printf("\nElemento %d da Pilha", i);
        printf("\nValor: %d", pilha->no[i].valor);
        printf("\nPrioridade: %d\n", pilha->no[i].prioridade);
    }
}

int main() 
{
    tpilha pilha;
    cria_pilha(&pilha);
    tno item;

    printf("INICIANDO TESTES\n");

    item.valor = 100;
    item.prioridade = 2;
    empilha_prioridade(&pilha, item);
    printf("Inserido Valor: %d | Prioridade: %d\n", item.valor, item.prioridade);

    item.valor = 200;
    item.prioridade = 5;
    empilha_prioridade(&pilha, item);
    printf("Inserido Valor: %d | Prioridade: %d\n", item.valor, item.prioridade);

    item.valor = 300;
    item.prioridade = 1;
    empilha_prioridade(&pilha, item);
    printf("Inserido Valor: %d | Prioridade: %d\n", item.valor, item.prioridade);

    item.valor = 400;
    item.prioridade = 8;
    empilha_prioridade(&pilha, item);
    printf("Inserido Valor: %d | Prioridade: %d\n", item.valor, item.prioridade);

    printf("\nRESULTADO FINAL DA PILHA\n");
    imprimir_pilha(&pilha);

    return 0;
}
