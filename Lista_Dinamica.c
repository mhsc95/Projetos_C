#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
/*Para a implemenação de uma lista dinâmica, faz-se necessário a presença de duas estruturas
(structs), uma do tipo Nó que vai conter um ponteiro do tipo struct "no" apontando para o próximo elemento
da lista, e uma estrutura do tipo Lista que vai conter um ponteiro do tipo(recém criado através do typedef) Nó apontando para 
o início da lista e um outro elemento opcional que informar o tamanho da lista, começando do início da lista recebendo zero*/
typedef struct no{
    int dado;
    struct no *proximo;//cada nó precisa de um ponteiro apontando para o nó seguinte
}No;

typedef struct tlista{
    No *inicio;//Quando a lista estiver vazia ele vai passar a ser nulo
    int tam;//esse "carinha" aqui, no inicio ele vai ser igual zero
}Lista;

//procedimento para inserir no início 
void inserir_inicio(Lista *lista, int num){
    No *novo = (No*)malloc(sizeof(No));/*Alocação dinâmica da memória para o tipo ponteiro, informo a máquina através de 
de um cast(No*) que ela vai ter que reservar um espaço na memória para um ponteiro do tipo Nó. Feito isso, ele vai guardar
essa iformação e vou poder alterar o que está lá dentro futuramente, sem que eu perca os dados já passado*/
    novo->dado = num;
    novo->proximo = lista->inicio;//o novo elemento passa a ser o início da lista
    lista->inicio = novo;
    lista->tam++;
}
//procedimento para inserir no fim da Lista
void inserir_fim(Lista *lista, int num){
    No *no, *novo = (No*)malloc(sizeof(No));
    novo->dado = num;
    novo->proximo = NULL;
    
    if(lista->inicio == NULL){
        lista->inicio = novo;
    }else{
        no = lista->inicio;
        while(no->proximo != NULL)
            no = no->proximo;
        no->proximo = novo;
    }
    lista->tam++;//independentemente de onde for feita essa inserção, eu tenho sempre que incrementar a minha lista
}
//procedimento para imprimir a Lista
void imprimir_lista(Lista *lista){
    No *inicio = lista->inicio;
    printf("\nTamanho da lista: %d\n", lista->tam);
    while(inicio != NULL){/*mesmo com a presença do campo "int tam" usarei NULL como se não soubesse o tamanho da Lista
pois é algo que será usado na grande maioria dos casos, trabalhar com listas dinâmicas sem saber o tamanho delas*/
        printf("%d ", inicio->dado);/*Se a lista for vazia o inicio vai ser nulo e não será feito nada, se a lista estiver vazia
ficará no inicio com uma região de memória com o endereço reservado, então será mandado o valor para o campo inicio->dado*/ 
        inicio = inicio->proximo;//para que não fica em laço infinito é perciso inidicar para o proximo nó da lista
    }
    printf("\n\n");
}

int main(){
   setlocale(LC_ALL, ("Portuguese"));
   Lista lista;//criei uma variável do tipo Lista. Não posso usar o mesmo nome "Lista"
   int op, valor;
   lista.inicio = NULL;
   lista.tam = 0;
   
   do{
       printf("1 - Inserir no inicio\n2 - Inserir no fim\n3 - Imprimir\n4 - Sair\n");
       scanf("%d", &op);
       switch(op){
        case 1:
            printf("\nDigite o valor que quer inserir:\n");
            scanf("%d ", &valor);
            inserir_inicio(&lista, valor);
            break;
        case 2:
            printf("\nDigite o valor que quer inserir no final da lista:\n");
            scanf("%d", &valor);
            inserir_fim(&lista, valor);
            break;
        case 3:
            imprimir_lista(&lista);
            break;
        case 4:
            printf("\nPrograma finalizado!!\n");
            break;
        default:
            printf("\nOpção inválida!!\n");
       }
   }while(op != 3);
   return 0;
}