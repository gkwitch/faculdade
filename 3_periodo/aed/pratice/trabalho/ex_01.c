#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50
typedef struct candidato {
        char nome[50];
        int n_inscricao; /*seria o formato 202601*/
        long long int cpf;
        int idade;
        int num_colegio;
        float pont_final;
        } tcandidato;

typedef struct lista
{
        tcandidato A[MAX];
        int n;
        } tlista;

void cria_lista (tlista *lista)/*cria a lista vazia, para nao ficar lixo la*/
{
     lista->n = 0;
     return;
     }

int lista_vazia (tlista lista)
{
     return (lista.n == 0);
     }
     
int lista_cheia (tlista lista) /*verificar se a lista ta cheia e retorna 1 se for true*/
{
    return (lista.n == MAX);
    }

void inserir_candidato (tlista *lista) 
{
    if (lista_cheia(*lista) == 1) 
    {
        printf("ERRO! A lista esta cheia.\n");
        return;
    }

    printf("Digite o nome do candidato: ");
    // Limpa qualquer lixo do buffer antes de ler a string
    fflush(stdin); 
    fgets(lista->A[lista->n].nome, sizeof(lista->A[lista->n].nome), stdin);
    
    // Remove o '\n' que o fgets coloca no final da string
    lista->A[lista->n].nome[strcspn(lista->A[lista->n].nome, "\n")] = '\0';

    printf("Digite o numero de inscricao: ");
    scanf("%d", &lista->A[lista->n].n_inscricao);
    
    printf("Digite apenas os numeros do CPF: ");
    scanf("%lld", &lista->A[lista->n].cpf);
    
    printf("Digite a idade: ");
    scanf("%d", &lista->A[lista->n].idade);
    
    printf("Digite o numero do colegio: ");
    scanf("%d", &lista->A[lista->n].num_colegio);
    
    printf("Digite a pontuacao final: ");
    scanf("%f", &lista->A[lista->n].pont_final);
    
    lista->n++;
    printf("Candidato inserido com sucesso!\n\n");
}
     
int buscar_candidato (tlista lista, long long int chave)
{
    int i;
    for (i = 0; i < lista.n; i++) /*para pesquisar apenas entre os candidatos que estão cadastrados*/
    {
        if (lista.A[i].cpf == chave)
         return i;
        }
    return -1;
    }
void imprimir_candidato(tcandidato c) 
{
    printf("DADOS DO CANDIDATO\n");
    printf("Nome: %s\n", c.nome);
    printf("CPF: %lld\n", c.cpf);
    printf("Inscricao: %d\n", c.n_inscricao);
    printf("Idade: %d\n", c.idade);
    printf("Número do Colégio: %d\n", c.num_colegio);
    printf("Pontuação final: %.2f\n", c.pont_final);
}

void imprimir_por_colegio(tlista lista, int num_buscado) 
{
    int i;
    int encontrou = 0; 

    printf("\nALUNOS DO COLÉGIO %d\n", num_buscado);

    for (i = 0; i < lista.n; i++) 
    {
        
        if (lista.A[i].num_colegio == num_buscado)
        {
            
            imprimir_candidato(lista.A[i]);
            encontrou = 1; 
        }
    }

    if (encontrou == 0)
    {
        printf("Nenhum candidato encontrado para este colégio.\n");
    }
}

void imprimir_todos(tlista lista)
{
    int i;

    printf("DADOS DOS CANDIDATOS\n");
    for (i = 0; i < lista.n; i++)
    {
            imprimir_candidato(lista.A[i]);
        }
}

int main(void)
{
           int opcao;
           int i;
           int pos_menor, pos_maior, nota_maior;
           long long int cpf_chave; 
           int posicao, num_buscado;
           tlista lista_candidatos;
           
           cria_lista(&lista_candidatos);
         
           opcao = -1;
           while (opcao != 0)
           {
                 printf("Digite a opção do menu: \n"
                 "1- Incluir dados do candidato\n"
                 "2- Pesquisar canditato por seu CPF\n"
                 "3- Imprimir dados dos candidatos de um colégio\n"
                 "4- Imprimir dados completos dos candidatos\n"
                 "5- Imprimir dados do candidato mais novo\n"
                 "6- Imprimir dados do candidato mais velho\n"
                 "7- Imprimir dados do vencedor da olimpiada \n"
                 "0- encerrar o programa\n");
                 scanf("%d", &opcao);

                 switch (opcao) {

                 case 1:
                 
                      inserir_candidato(&lista_candidatos);
                 
                      break;

                 case 2:
                 
                      if (lista_vazia(lista_candidatos) == 1)
                      {
                         printf("Não possui candidatos cadastrados. \n");
                         break;
                    }
                      printf("Digite apenas o número do CPF do candidato: \n");
                      scanf("%lld", &cpf_chave);
                 
                      posicao = buscar_candidato (lista_candidatos, cpf_chave);
                 
                      if (posicao == -1) {
                         printf("Candidato com CPF %lld não encontrado!\n", cpf_chave);
                         } else {
                         printf("Candidato encontrado na posição %d!\n", posicao);
                       
                         imprimir_candidato(lista_candidatos.A[posicao]);
                     }
                     break;

                 case 3:
                      if (lista_vazia(lista_candidatos) == 1)
                      {
                         printf("Não possui candidatos cadastrados. \n");
                         break;
                      }
                       printf("Digite o número do colegio do candidato: \n");
                       scanf("%d", &num_buscado);
                       
                       imprimir_por_colegio(lista_candidatos, num_buscado);
                 
                 break;

                 case 4:
                      imprimir_todos(lista_candidatos);
                      break;

                 case 5:
                      pos_menor = 0;
                      i = 0;
                      if (lista_vazia(lista_candidatos) == 1)
                      {
                         printf("Não possui candidatos cadastrados. \n");
                         break;
                    }
                    for (i = 1; i < lista_candidatos.n; i++)
                    {
                        if (lista_candidatos.A[i].idade < lista_candidatos.A[pos_menor].idade)
                        {
                           pos_menor = i;
                           }
                        }
                        imprimir_candidato(lista_candidatos.A[pos_menor]);
                      break;

                 case 6:
                      pos_maior = 0;
                      i = 0;
                      if (lista_vazia(lista_candidatos) == 1)
                      {
                         printf("Não possui candidatos cadastrados. \n");
                         break;
                    }
                    for (i = 1; i < lista_candidatos.n; i++)
                    {
                        if (lista_candidatos.A[i].idade > lista_candidatos.A[pos_maior].idade)
                        {
                           pos_maior = i;
                           }
                        }
                        imprimir_candidato(lista_candidatos.A[pos_maior]);

                        break;

                 case 7:
                      nota_maior = 0;
                      i = 0;
                      if (lista_vazia(lista_candidatos) == 1)
                      {
                         printf("Não possui candidatos cadastrados. \n");
                         break;
                         }
                    for (i = 1; i < lista_candidatos.n; i++)
                    {
                        if (lista_candidatos.A[i].pont_final > lista_candidatos.A[nota_maior].pont_final)
                        {
                           nota_maior = i;
                           }
                        }
                        imprimir_candidato(lista_candidatos.A[nota_maior]);

                        break;

                 case 0:
                      printf("O programa foi encerrado.");
                      break;

                 default:
                         printf("Essa opção não é válida!\n");
                         break;
                         }
                 } 
                 return (0);
}

