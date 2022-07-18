#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void menu();
int votacao_vereador();
void votos_total();
int vJoao = 0, vZe = 0, vMaria = 0, vNulo = 0, vVoto = 0;
int pDr = 0, pGomes = 0, pNulo = 0, pVoto = 0;
int vResultado, pResultado, total;

int main (){
    setlocale(LC_ALL, "Portuguese");
    int op;
    
    do{
        printf("\nEscolha as seguintes opções abaixo:\n");
        printf("\n1 - Votar para vereador\n2 - Votar para prefeito\n3 - Apuração dos votos\n4 - Sair\n");
        scanf("%d", &op);
        switch(op){
            case 1:
                votacao_vereador();
            default:
                printf("\nOpção inválida!!\n");
            break;
        }
    }while(op != 0);
    return  0;
}

int votacao_vereador(){
    menu();
    do{
        if(vVoto == 111){
            printf("\nDigite 1 para confirmar e 2 para cancelar\n");
            scanf("%d", &vResultado);
            if(vResultado == 1){
                printf("\nVoto confirmado com sucesso\n");
                vJoao++;
                return main();
            }else{
                if(vResultado == 2)
                    printf("\nVoto cancelado!\n");                    
                    return main();
            }
        }else{
            if(vVoto == 222){
                printf("\nDigite 1 para confirmar e 2 para cancelar\n");
                scanf("%d", &vResultado);
                if(vResultado ==  1){
                    printf("\nVoto confirmado com sucesso\n");
                    vMaria++;
                    return main();
                }else{
                    if(vResultado == 2)
                        printf("\nVoto cancelado!\n");                        
                        return main();
                }
            }else{
                if(vVoto == 333){
                    printf("\nDigite 1 para confirmar e 2 para cancelar\n");
                    scanf("%d", &vResultado);
                    if(vResultado ==  1){
                        printf("\nVoto confirmado com sucesso\n");
                        vZe++;
                        return main();
                    }else{
                        if(vResultado == 2)
                            printf("\nVoto cancelado!\n");                            
                            return main();
                }
            }else{
                if(vVoto == 444){
                    printf("\nDigite 1 para confirmar e 2 para cancelar\n");
                    scanf("%d", &vResultado);
                    if(vResultado == 1){
                        printf("\nVoto nulo\n");
                        vNulo++;
                        return main();
                    }else{
                        if(vResultado == 2)
                            printf("\nVoto cancelado!!\n");                            
                            return main();
                    }
                }
            }
        }
    }
    }while(vVoto != 0);
    
}

void menu(){
    printf ("\nCadidatos\n");
    printf ("\tPara vereador:\n");
    printf ("\n\t111 - Vereador Joao do Frete\n\t222 - Vereador Maria da Pamonha\n\t333 - Vereador Ze da Farmacia\n\t444 - Voto Nulo\n");
    scanf ("%d", &vVoto);
}

void votos_total(){
    printf("\nQuantidade de votos para o vereador João do Frete: %d\n", vJoao);
    printf("\nQuantidade de votos para a vereadora Maria da Pamonha: %d\n", vMaria);
    printf("\nQuantidade de votos para o vereador Ze da Farmacia: %d\n", vZe);
    printf("\nQuantidade de votos Nulos para vereador: %d\n", vNulo);
}
