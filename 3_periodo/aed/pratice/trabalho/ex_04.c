#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

#define TAM 5000 

typedef struct no {
    int tempo_atendimento;
} tno;

// Estrutura da Fila Circular
typedef struct fila {
    int ini;
    int fim;
    int quantidade; 
    tno no[TAM];
} tfila;

void cria_fila(tfila *f) {
    f->ini = 0;
    f->fim = 0;
    f->quantidade = 0;
}

int fila_vazia(tfila *f) {
    return (f->quantidade == 0);
}

int fila_cheia(tfila *f) {
    return (f->quantidade == TAM);
}

int enfileirar(tfila *f, tno chave) {
    if (fila_cheia(f) == 1) return 0;
    f->no[f->fim] = chave;
    // O comando % (resto da divisao) faz o fim dar a volta para o inicio se bater no limite!
    f->fim = (f->fim + 1) % TAM; 
    f->quantidade++;
    return 1;
}

int desenfileirar(tfila *f, tno *chave) {
    if (fila_vazia(f) == 1) return 0;
    *chave = f->no[f->ini];
    f->ini = (f->ini + 1) % TAM;
    f->quantidade--;
    return 1;
}

int main() {
    srand(time(NULL)); 
    
    tfila fila_banco;
    cria_fila(&fila_banco);
    
    int tempo_simulacao_min, num_caixas, tempo_max_atend, max_clientes_min;
    
    int seg, c, i;
    int total_atendidos = 0;
    int soma_tempos_atendimento = 0;
    
    printf("SIMULADOR DE BANCO\n");
    printf("Tempo de simulacao (em minutos): ");
    scanf("%d", &tempo_simulacao_min);
    
    printf("Numero de caixas disponiveis: ");
    scanf("%d", &num_caixas);
    
    printf("Tempo maximo de um atendimento (em segundos): ");
    scanf("%d", &tempo_max_atend);
    
    printf("Numero maximo de clientes que chegam por minuto: ");
    scanf("%d", &max_clientes_min);
    
    int *caixas = (int*) calloc(num_caixas, sizeof(int));
    
    int tempo_simulacao_seg = tempo_simulacao_min * 60;
    
    printf("\nIniciando simulacao...\n");
    
    for (seg = 0; seg < tempo_simulacao_seg; seg++) {
        
        if (seg % 60 == 0) {
            int num_chegadas = rand() % (max_clientes_min + 1);
            
            for (i = 0; i < num_chegadas; i++) {
                tno novo_cliente;
                novo_cliente.tempo_atendimento = rand() % (tempo_max_atend + 1);
                enfileirar(&fila_banco, novo_cliente);
            }
        }
        
        for (c = 0; c < num_caixas; c++) {
            if (caixas[c] > 0) {
                caixas[c]--; 
            } 
            else if (caixas[c] == 0 && fila_vazia(&fila_banco) == 0) {
                tno cliente_atendido;
                desenfileirar(&fila_banco, &cliente_atendido);
                
                caixas[c] = cliente_atendido.tempo_atendimento;
                
                soma_tempos_atendimento += cliente_atendido.tempo_atendimento;
                total_atendidos++;
            }
        }
    } 
    
    printf("\nRESULTADOS DA SIMULACAO\n");
    printf("Total de clientes atendidos: %d\n", total_atendidos);
    
    if (total_atendidos > 0) {
        float tempo_medio = (float)soma_tempos_atendimento / total_atendidos;
        printf("Tempo medio de atendimento: %.2f segundos\n", tempo_medio);
    } else {
        printf("Nenhum cliente foi atendido.\n");
    }
    
    printf("Tamanho da fila no final do expediente: %d pessoas\n", fila_banco.quantidade);
    
    free(caixas);
    
    return 0;
}
