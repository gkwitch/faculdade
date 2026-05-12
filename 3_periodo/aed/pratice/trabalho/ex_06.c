#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ALUNOS 40

typedef struct endereco 
{
    char bairro[50];
    char tipo[20];
    char nome[50];
    int numero;
    char complemento[30];
    char cidade[50];
    char estado[3];  
} tendereco;

typedef struct aluno 
{
    char nome[50];
    int idade;
    char curso[50];
    tendereco endereco;
    float cr;
    int matricula;
} taluno;

typedef struct alunomat 
{
    taluno aluno;
    float nota;
    int faltas;
} talunomat;

typedef struct disciplina 
{
    char codigo[20];
    char nome[50];
    talunomat turma[MAX_ALUNOS];
} tdisciplina;

// --- ALGORITMO DE ORDENACAO (MERGE SORT) ---

void merge(talunomat vetor[], int inicio, int meio, int fim) 
{
    int i, j, k;
    int tam_esq = meio - inicio + 1;
    int tam_dir = fim - meio;

    talunomat *esq = (talunomat *)malloc(tam_esq * sizeof(talunomat));
    talunomat *dir = (talunomat *)malloc(tam_dir * sizeof(talunomat));

    for (i = 0; i < tam_esq; i++) esq[i] = vetor[inicio + i];
    for (j = 0; j < tam_dir; j++) dir[j] = vetor[meio + 1 + j];

    i = 0; j = 0; k = inicio;
    while (i < tam_esq && j < tam_dir) 
	{
        if (esq[i].aluno.matricula == 0) {
            vetor[k++] = dir[j++];
        } else if (dir[j].aluno.matricula == 0) {
            vetor[k++] = esq[i++];
        } else if (strcmp(esq[i].aluno.nome, dir[j].aluno.nome) <= 0) {
            vetor[k++] = esq[i++];
        } else {
            vetor[k++] = dir[j++];
        }
    }

    while (i < tam_esq) vetor[k++] = esq[i++];
    while (j < tam_dir) vetor[k++] = dir[j++];

    free(esq);
    free(dir);
}

void merge_sort(talunomat vetor[], int inicio, int fim) 
{
    if (inicio < fim) {
        int meio = inicio + (fim - inicio) / 2;
        merge_sort(vetor, inicio, meio);
        merge_sort(vetor, meio + 1, fim);
        merge(vetor, inicio, meio, fim);
    }
}

// --- FUNCOES DO MENU ---

void criar_disciplina(tdisciplina *d) 
{
    int i;
    printf("\n--- CRIAR DISCIPLINA ---\n");
    printf("Digite o codigo da disciplina: ");
    scanf(" %[^\n]", d->codigo);
    
    printf("Digite o nome da disciplina: ");
    scanf(" %[^\n]", d->nome);
    
    for(i = 0; i < MAX_ALUNOS; i++) 
	{
        d->turma[i].aluno.matricula = 0;
    }
    printf("Disciplina '%s' criada com sucesso e vagas zeradas!\n", d->nome);
}

void incluir_aluno(tdisciplina *d) 
{
    int i, vaga = -1;
    
    for(i = 0; i < MAX_ALUNOS; i++) {
        if(d->turma[i].aluno.matricula == 0) {
            vaga = i;
            break;
        }
    }
    
    if(vaga == -1) 
	{
        printf("\nERRO: Nao ha mais vagas nesta turma!\n");
        return;
    }
    
    printf("\nINCLUIR NOVO ALUNO (Vaga %d)\n", vaga + 1);
    
    printf("Numero de Matricula: ");
    scanf("%d", &d->turma[vaga].aluno.matricula);
    
    printf("Nome do Aluno: ");
    scanf(" %[^\n]", d->turma[vaga].aluno.nome);
    
    printf("Idade: ");
    scanf("%d", &d->turma[vaga].aluno.idade);
    
    printf("Curso: ");
    scanf(" %[^\n]", d->turma[vaga].aluno.curso);
    
    printf("Coeficiente de Rendimento (CR): ");
    scanf("%f", &d->turma[vaga].aluno.cr);
    
    printf("Nota na disciplina: ");
    scanf("%f", &d->turma[vaga].nota);
    
    printf("Total de faltas: ");
    scanf("%d", &d->turma[vaga].faltas);
    
    printf("--- Endereco ---\n");
    printf("Tipo (Rua/Av/Trav): ");
    scanf(" %[^\n]", d->turma[vaga].aluno.endereco.tipo);
    printf("Nome do Logradouro: ");
    scanf(" %[^\n]", d->turma[vaga].aluno.endereco.nome);
    printf("Numero: ");
    scanf("%d", &d->turma[vaga].aluno.endereco.numero);
    printf("Bairro: ");
    scanf(" %[^\n]", d->turma[vaga].aluno.endereco.bairro);
    printf("Cidade: ");
    scanf(" %[^\n]", d->turma[vaga].aluno.endereco.cidade);
    printf("Estado (UF): ");
    scanf(" %[^\n]", d->turma[vaga].aluno.endereco.estado);

    printf("\nAluno cadastrado com sucesso!\n");
}

void excluir_aluno(tdisciplina *d) 
{
    int mat_busca, i;
    int encontrou = 0;
    
    printf("\n--- EXCLUIR ALUNO ---\n");
    printf("Digite a matricula do aluno a ser excluido: ");
    scanf("%d", &mat_busca);
    
    for(i = 0; i < MAX_ALUNOS; i++) 
	{
        if(d->turma[i].aluno.matricula == mat_busca) 
		{
            d->turma[i].aluno.matricula = 0; 
            printf("Aluno excluido com sucesso (vaga liberada)!\n");
            encontrou = 1;
            break;
        }
    }
    
    if(encontrou == 0) {
        printf("Aluno com matricula %d nao encontrado.\n", mat_busca);
    }
}

void listar_alunos(tdisciplina d) 
{
    int i;
    int qtd = 0;
    
    printf("\n--- LISTA COMPLETA DE ALUNOS ---\n");
    for(i = 0; i < MAX_ALUNOS; i++) {
        if(d.turma[i].aluno.matricula != 0) 
		{
            printf("\nALUNO %d:\n", qtd + 1);
            printf("Nome: %s\n", d.turma[i].aluno.nome);
            printf("Matricula: %d | Curso: %s\n", d.turma[i].aluno.matricula, d.turma[i].aluno.curso);
            printf("Idade: %d | CR: %.2f\n", d.turma[i].aluno.idade, d.turma[i].aluno.cr);
            printf("Endereco: %s %s, %d - %s, %s/%s\n", 
                d.turma[i].aluno.endereco.tipo,
                d.turma[i].aluno.endereco.nome,
                d.turma[i].aluno.endereco.numero,
                d.turma[i].aluno.endereco.bairro,
                d.turma[i].aluno.endereco.cidade,
                d.turma[i].aluno.endereco.estado);
            qtd++;
        }
    }
    if(qtd == 0) printf("A turma esta vazia.\n");
}

void calcular_cr_medio(tdisciplina d) 
{
    int i, qtd = 0;
    float soma_cr = 0;
    
    for(i = 0; i < MAX_ALUNOS; i++) 
	{
        if(d.turma[i].aluno.matricula != 0) {
            soma_cr += d.turma[i].aluno.cr;
            qtd++;
        }
    }
    
    if(qtd > 0) 
	{
        printf("\nO CR Medio dos %d alunos da disciplina e: %.2f\n", qtd, soma_cr / qtd);
    } else {
        printf("\nNao ha alunos para calcular o CR Medio.\n");
    }
}

void imprimir_boletim(tdisciplina d) 
{
    int i, qtd = 0;
    
    merge_sort(d.turma, 0, MAX_ALUNOS - 1);
    
    printf("\nBOLETIM DA DISCIPLINA\n");
    printf("%-20s | %-15s | %-8s | %-6s | %-4s\n", "NOME", "CURSO", "MATRICULA", "FALTAS", "NOTA");
    printf("----------------------------------------------------------------\n");
    
    for(i = 0; i < MAX_ALUNOS; i++) {
        if(d.turma[i].aluno.matricula != 0) {
            printf("%-20s | %-15s | %-9d | %-6d | %.2f\n", 
                d.turma[i].aluno.nome, 
                d.turma[i].aluno.curso, 
                d.turma[i].aluno.matricula, 
                d.turma[i].faltas, 
                d.turma[i].nota);
            qtd++;
        }
    }
    if(qtd == 0) printf("Nenhum aluno matriculado para gerar boletim.\n");
}

void fechar_disciplina(tdisciplina *d) 
{
    int i;
    strcpy(d->codigo, " ");
    strcpy(d->nome, " ");
    
    for(i = 0; i < MAX_ALUNOS; i++) 
	{
        d->turma[i].aluno.matricula = 0;
    }
    printf("\nDisciplina fechada! Todos os registros foram resetados.\n");
}

int main() 
{
    tdisciplina minha_disciplina;
    char opcao;
    
    int i;
    for(i = 0; i < MAX_ALUNOS; i++) {
        minha_disciplina.turma[i].aluno.matricula = 0;
    }
    
    do {
        printf("\nMENU DO SISTEMA ESCOLAR\n");
        printf("a) Criar Disciplina\n");
        printf("b) Incluir Aluno\n");
        printf("c) Excluir Aluno\n");
        printf("d) Listar Alunos\n");
        printf("e) Calcular CR Medio\n");
        printf("f) Imprimir Boletim (Ordenado Alfabeticamente)\n");
        printf("g) Fechar Disciplina\n");
        printf("h) Terminar o programa\n");
        printf("Escolha uma opcao: ");
        scanf(" %c", &opcao);
        
        switch(opcao) {
            case 'a': case 'A': criar_disciplina(&minha_disciplina); break;
            case 'b': case 'B': incluir_aluno(&minha_disciplina); break;
            case 'c': case 'C': excluir_aluno(&minha_disciplina); break;
            case 'd': case 'D': listar_alunos(minha_disciplina); break;
            case 'e': case 'E': calcular_cr_medio(minha_disciplina); break;
            case 'f': case 'F': imprimir_boletim(minha_disciplina); break;
            case 'g': case 'G': fechar_disciplina(&minha_disciplina); break;
            case 'h': case 'H': printf("\nEncerrando o sistema... Ate logo!\n"); break;
            default: printf("\nOpcao invalida. Tente novamente.\n");
        }
    } while (opcao != 'h' && opcao != 'H');

    return 0;
}
