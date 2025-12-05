### Bloco 1: Domando o Loop e Estatísticas (Foco no Ex 1 da prova)

O segredo aqui é controlar o loop e inicializar as variáveis corretamente (soma começa com 0, produto começa com 1).

**1. O Loop Básico e Média**

- **Tarefa:** Faça um programa que peça números inteiros ao usuário infinitamente. O programa só para quando o usuário digitar um número negativo.
- **Saída:** Ao parar, mostre a quantidade de números digitados e a média aritmética deles.
- _Dica:_ Use um contador e um acumulador. Lembre do cast `(float)` na divisão.
    
>[!failure] 
>R1: Eu preciso fazer um loop que enquanto uma variavel não for menor do que 0, o loop continua rodando e pedindo numeros ao meu usuário, preciso ir incrementado meu contador, para conseguir calcular a media dos numeros. Vou tentar com for sem inicializar n e ir pedindo lá dentro o scanf. Assim o for ja inicaliza a primeira e faz a verificacao antes de entrar no loop.
>Deu erro porque o loop so iria parar depois que o numero negativo e adicionado na soma, assim tambem contabilizando o contador i.

>[!success] 
>R2: Existe uma coisa chamada loop infinito. `While (1)`, que rodara enquanto o 1 for verdadeiro. Para parar esse loop podemos dar um brake quando a nossa condição não agradar. Entao posso pedir ja dentro do loop pro usuario digitar o numero e fazer a verificacao. 
Posso fazer uma medida de seguranca usando i > 0 para calcular a media, caso o usuario digite um negativo de primeira. Preciso inicializar o i e a media por conta do lixo de memoria.

```C
#include <stdio.h>

int main(void)
{
	long int i, n;
	float media;
	
	i = 0;
	media = 0;
	while(1)
	{
		printf("Digite um numero inteiro: \n");
		scanf("%ld", &n);
		
		if (n < 0)
			break;
		
		media += n;
		i++;
	}
	if (i > 0)
	{
		media = media / i;
		printf("A media e: %.2f\n", media);
	}
	else
		printf("Nenhum numero valido digitado\n");
		
	return (0);
}
```


**2. O Guardião do Maior e Menor**

- **Evolução:** Pegue o código do ex anterior. Agora, além da média, você deve descobrir qual foi o **maior** e o **menor** número digitado.
- _Dica:_ No primeiro número digitado, inicialize `maior` e `menor` com esse valor. Nos próximos, use `if`.

>[!success] 
>R1: Agora eu preciso criar 2 variaveis, maior e menor, fazer uma verificacao que se o numero for maior do que o anterior digitado ele vai para a variavel maior, e uma verificacao que se ele for menor do que o numero que esta na variavel menor ele vai pra ela. 
O problema e: como eu vou lidar com a comparacao se nenhum numero foi digitado ainda. E como eu vou lidar com o zero.  

>[!failure] 
>-Eu posso comparar com zero mesmo e coloca-lo nas duas variaveis. 
-Nao deu certo por conta do menor numero.

>[!success] 
>R2: Se eu atribuir o primeiro numero digitado as variaveis maior e menor, elimina o problema do zero e da comparacao.

```C
#include <stdio.h>

int     main(void)
{
        long int     i, n, maior, menor;
        float   media;

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
```

**3. Condicionais Matemáticas (Ímpar e Par)**

- **Evolução:** Continue com o mesmo código. Adicione duas novas variáveis: `soma_impares` (inicia em 0) e `produto_pares` (inicia em 1).
- **Lógica:** Se o número lido for impar, multiplique-o no acumulador de produto. Se for par, some-o no acumulador de soma.
- _Chekpoint:_ Com este exercício, você resolveu o **Ex 1** da sua prova.

>[!success]
R1: Agora eu preciso de 2 variaveis para ir armazenando a soma dos pares e o produto dos impares. Preciso fazer uma verificacao se o n e impar ou par. Preciso inicalizar as variaveis. As somas com 0, porque senao vai somar com o lixo. O produto com 1, porque senao vai multiplicar por 0.

O operador `if (n % 2)` retorna 0 se for verdadeiro, no entando o 0 e falso em booleano. Entao se o numero for par ele vai retornar falso, entao seria impar.

```C
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
                if (n % 2) //se for par, retorna 0, falso
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
```

---

### Bloco 2: Manipulação de Strings e "Matemática Maluca" (Foco no Ex 4 da prova)

O Ex 4 da prova exigia pegar pedaços de um número (matricula) e fazer contas. Vamos treinar isso.

**4. O Cortador de Matrículas (String para Substring)**

- **Tarefa:** Peça ao usuário uma matrícula como string (ex: "20230015"). Crie uma lógica para copiar apenas os **4 primeiros caracteres** ("2023") para uma variável auxiliar chamada `ano_str` e coloque o `\0` no final.
    
- _Dica:_ Use um loop `for` de 0 a 3 ou `strncpy`.
    

**5. Convertendo e Comparando (String para Int)**

- **Evolução:** Pegue a string `ano_str` do exercício anterior e converta para um número inteiro (use `atoi`).
    
- **Lógica:** Se esse número for menor que 2019, imprima "Aluno Veterano". Se for maior ou igual, imprima "Aluno Novo".
    

**6. Os Últimos Dígitos e o Resto (A Lógica do Erro)**

- **Tarefa:** Peça a matrícula inteira novamente. Agora, se for "Aluno Novo" (ex 5), pegue os **últimos 5 dígitos** da matrícula (dica: converta a string original toda para `long int` ou manipule a string para pegar do índice 4 em diante).
    
- **Cálculo:** Percorra esses 5 dígitos (pode ser somando eles). Para cada dígito, faça a conta `digito % 3`.
    
    - Se o resultado for maior que 0, some em `x`.
        
    - Se for 0, some em `z`.
        
- **O Grande Final:** Tente imprimir o resultado de `x / z`.
    
- _Desafio:_ O que acontece se `z` for 0? Use um `if` para evitar que o programa quebre (evitar o erro da prova).
    

---

### Bloco 3: Arquivos Binários Inteligentes (Foco no Ex 2 da prova)

Aqui vamos aprender a verificar se um arquivo existe e mudar o nome dele.

**7. O Escritor Binário Simples**

- **Tarefa:** Crie um vetor de inteiros com 10 números preenchidos por você. Abra um arquivo chamado "dados.bin" usando `"wb"` e grave o vetor inteiro de uma vez usando `fwrite`. Feche o arquivo.
    

**8. O Detetive de Arquivos**

- **Tarefa:** Antes de criar o arquivo "dados.bin" (do ex anterior), tente abri-lo em modo leitura (`"rb"`).
    
- **Lógica:**
    
    - Se o ponteiro for diferente de NULL, imprima: "O arquivo já existe!". Feche-o.
        
    - Se for NULL, imprima: "Arquivo não existe, posso criar".
        

**9. O Renomeador Automático (A lógica difícil da prova)**

- **Tarefa:** Peça ao usuário um nome base, ex: "saida".
    
- **Desafio:** Tente abrir "saida.bin" para leitura.
    
    - Se não existir, crie "saida.bin".
        
    - Se existir, tente "saida1.bin". Se esse existir, tente "saida2.bin", e assim por diante até achar um livre.
        
- _Dica:_ Use um loop infinito, um contador e a função `sprintf(nome_final, "%s%d.bin", nome_base, contador)` para gerar os nomes.
    
- _Checkpoint:_ Com isso você domina a lógica complexa do **Ex 2** da prova.
    

---

### Bloco 4: Loops Aninhados (Foco no Ex 3 da prova)

**10. A Pirâmide Simples**

- **Tarefa:** Peça um número `N`. Faça um loop para imprimir `N` linhas. Na linha 1, imprima 1 asterisco. Na linha 2, imprima 3 asteriscos. Na linha 3, imprima 5.
    
- _Lógica:_ Você precisa imprimir espaços em branco antes dos asteriscos para centralizar.
    

**11. A Árvore de Natal Completa**

- **Evolução:** Pegue a pirâmide do ex 10. Garanta que o usuário digite no mínimo 5 linhas.
    
- **Adicional:** Após terminar a pirâmide, desenhe um "tronco" (ex: 2 linhas com 3 asteriscos no centro).
    
- _Checkpoint:_ Resolveu o **Ex 3** da prova.
    

---

### 🏆 Bloco 5: O Simulado Final

**12. O Integrador (Misturando tudo)**

- **Enunciado:** Faça um programa que:
    
    1. Receba várias matrículas (strings) num loop até digitar "fim".
        
    2. Para cada matrícula, aplique a lógica do **Ex 6** (ano < 2019 ou contas com resto).
        
    3. Guarde o resultado final (`x/z` ou código de erro) em uma `struct` ou variáveis.
        
    4. No final, grave esses resultados em um arquivo binário. O nome do arquivo deve ser "relatorio.bin". Se já existir, deve criar "relatorio1.bin", etc (Lógica do **Ex 9**).