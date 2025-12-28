#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>



// Código da Ilha – Edição Free Fire
// Nível: Mestre
// Este programa simula o gerenciamento avançado de uma mochila com componentes coletados durante a fuga de uma ilha.
// Ele introduz ordenação com critérios e busca binária para otimizar a gestão dos recursos.

#define maxIten  10
#define maxPrioridade 5
#define maxString 15

 struct itens
{ 
    char nome[maxString];
    char tipo[maxString];
    int quantidade;
    int prioridade;
    struct itens *prox;
    
};

void limpaBufferEntrada();
void insereItem(
                struct itens *cabeca,
                const char *nome,
                const char *tipo,
                int quantidade,
                int prioridade);
void listarItens(struct itens *cabeca);
void buscaItem(struct itens *cabeca, const char *nome);
        



int main() {
    // Menu principal com opções:
    // 1. Adicionar um item
    // 2. Remover um item
    // 3. Listar todos os itens
    // 4. Ordenar os itens por critério (nome, tipo, prioridade)
    // 5. Realizar busca binária por nome
    // 0. Sair

    int cont = 0;
    int opcao =-1;
    struct itens cabeca;
    cabeca.prox = NULL;

    do{
        printf("\n.........[ FIRE.FREE  ].............\n\n");
            printf("OPÇÃO - 1 : ADICIONAR UM ITEM NA LISTA\n");
            printf("OPÇÃO - 2 : LISTAR TODOS OS ITENS\n");
            printf("OPÇAO - 3 : REMOVER ITEM\n");
            printf("OPÇÃO - 4 : ORDERNAR ITENS POR CRITERIO\n");
            printf("OPÇÃO - 5 : REALIZAR BUSCA POR NOME\n");
            printf("OPÇÃO - 0 : SAIR\n");
            printf("==================================\n");
            printf("ESCOLHA UMA OPÇÃO :  ");

            scanf("%d", &opcao);
            limpaBufferEntrada();
            

            switch (opcao)
            {
            case 1:
               if (cont<maxIten){
                printf("cadastrando novo item");
                char nome[maxString];
                char tipo[maxString];
                int quantidade;
                int prioridade;
                printf("\ndigite o nome do item :");
                 if (fgets (nome, maxString, stdin) == NULL) {
                    printf("Erro ao ler nome.\n");
                    return 1;
                }
                    nome[strcspn(nome , "\n")] = '\0';
                   
                
                printf("\ndigite o tipo item :");
                 if (fgets (tipo, maxString, stdin) == NULL) {
                    printf("Erro ao ler tipo.\n");
                    return 1;
                }
                    tipo[strcspn(tipo , "\n")] = '\0';
                     
                    
                printf("\ndigite a quantidade do item :");
                    
                 if (scanf("%d", &quantidade) != 1) {
                    limpaBufferEntrada();
                    printf("Erro ao ler quantidade.\n");
                    
                    return 1;
                   }

                
                printf("\ndigite prioridade do item :");
                     
                  if (scanf("%d",&prioridade) != 1) {
                   limpaBufferEntrada();
                   printf("Erro ao ler prioridade.\n");
                   
                   return 1;
                   }
                insereItem(&cabeca,nome,tipo,quantidade,prioridade);
                printf("item cadastrado com sucesso\n");
                cont++;

                

               }else{
                printf("quantidade máxima de itens cadastrados");
               }
                
                               
                
                break;
            case 2:
                listarItens(&cabeca);
            
                break;
            case 3:
                printf("opcao não implementada");
                break;
            case 4:
                printf("opcao não implementada"); 
                break;
            case 5:
                if(cont>0){
                    char nome[maxString];
                    printf("DIGITE O ITEM PROCURADO : ");
                    if (fgets(nome,maxString,stdin)==NULL){
                    printf("ERRO AO LER ITEM");
                    break;
                    }
                 nome[strcspn(nome,"\n")]='\0';
                 printf("\nitem procurado %s",nome);
                 buscaItem(&cabeca,nome);
                 break;            
                } else{
                    printf("nenhum item cadastrado");
                  }
                break;
                 
            
            default:
                break;
            }
    }while (opcao!=0);

    printf("saindo do jogo\n");
    printf("ponteiro cabeca.prox = %p\n", (void *)cabeca.prox);


    
    
    


    // A estrutura switch trata cada opção chamando a função correspondente.
    // A ordenação e busca binária exigem que os dados estejam bem organizados.
     printf("-------Lista de itens------\n");
     printf("\nEscolha uma opção: \n1-inserir\n2-listar\n3-remover");

    return 0;
}

void limpaBufferEntrada(){
    int c;
    while ((c=getchar())!='\n' && c != EOF);   
    
}

void insereItem(struct itens *cabeca,
                const char *nome,
                const char *tipo,
                int quantidade,
                int prioridade)
{
    struct itens *novo = malloc(sizeof(struct itens));
    if (novo == NULL) {
        printf("Erro: falha ao alocar memória.\n");
        return;
    }

    strcpy(novo->nome, nome);
    strcpy(novo->tipo, tipo);
    novo->quantidade = quantidade;
    novo->prioridade = prioridade;
    novo->prox = NULL;

    struct itens *atual = cabeca;

    while (atual->prox != NULL) {
        atual = atual->prox;
    }

    atual->prox = novo;
}
void listarItens(struct itens *cabeca)
{
    if (cabeca == NULL) {
        printf("Erro: lista não inicializada.\n");
        return;
    }

    if (cabeca->prox == NULL) {
        printf("\nLista vazia. Nenhum item cadastrado.\n");
        return;
    }

    struct itens *atual = cabeca->prox;
    int indice = 1;

    printf("\n------- LISTA DE ITENS -------\n");

    while (atual != NULL) {
        printf("Item %d\n", indice);
        printf("Nome       : %s\n", atual->nome);
        printf("Tipo       : %s\n", atual->tipo);
        printf("Quantidade : %d\n", atual->quantidade);
        printf("Prioridade : %d\n", atual->prioridade);
        printf("-----------------------------\n");

        atual = atual->prox;
        indice++;
    }
}
void buscaItem(struct itens *cabeca,const char *nome){
    struct itens *atual = cabeca->prox;
    while (atual!=NULL)
    {
        if(strcmp(atual->nome,nome)==0){
           printf("\nITEM ENCONTRADO:\n");
            printf("Nome       : %s\n", atual->nome);
            printf("Tipo       : %s\n", atual->tipo);
            printf("Quantidade : %d\n", atual->quantidade);
            printf("Prioridade : %d\n", atual->prioridade);
            return;
        }
        atual = atual->prox;
    }
    printf("item %s não localizado",nome);
    
    
                    

}





// Struct Item:
// Representa um componente com nome, tipo, quantidade e prioridade (1 a 5).
// A prioridade indica a importância do item na montagem do plano de fuga.

// Enum CriterioOrdenacao:
// Define os critérios possíveis para a ordenação dos itens (nome, tipo ou prioridade).

// Vetor mochila:
// Armazena até 10 itens coletados.
// Variáveis de controle: numItens (quantidade atual), comparacoes (análise de desempenho), ordenadaPorNome (para controle da busca binária).

// limparTela():
// Simula a limpeza da tela imprimindo várias linhas em branco.

// exibirMenu():
// Apresenta o menu principal ao jogador, com destaque para status da ordenação.

// inserirItem():
// Adiciona um novo componente à mochila se houver espaço.
// Solicita nome, tipo, quantidade e prioridade.
// Após inserir, marca a mochila como "não ordenada por nome".

// removerItem():
// Permite remover um componente da mochila pelo nome.
// Se encontrado, reorganiza o vetor para preencher a lacuna.

// listarItens():
// Exibe uma tabela formatada com todos os componentes presentes na mochila.

// menuDeOrdenacao():
// Permite ao jogador escolher como deseja ordenar os itens.
// Utiliza a função insertionSort() com o critério selecionado.
// Exibe a quantidade de comparações feitas (análise de desempenho).

// insertionSort():
// Implementação do algoritmo de ordenação por inserção.
// Funciona com diferentes critérios de ordenação:
// - Por nome (ordem alfabética)
// - Por tipo (ordem alfabética)
// - Por prioridade (da mais alta para a mais baixa)

// buscaBinariaPorNome():
// Realiza busca binária por nome, desde que a mochila esteja ordenada por nome.
// Se encontrar, exibe os dados do item buscado.
// Caso contrário, informa que não encontrou o item.
