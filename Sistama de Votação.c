#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
//prototipação das funções usadas no programa
void candidatos_vereador();
void candidatos_prefeito();
int votacao_vereador();
int votacao_prefeito();
void votos_total_vereador();
void votos_total_prefeito();

//variáveis globais, declarei fora da main pra ficar mais fácil de manusear elas e ficar mais fácil o entendimento 
int vJoao = 0, vZe = 0, vMaria = 0, vNulo = 0, vVoto = 0;
int pDr = 0, pGomes = 0, pNulo = 0, pVoto = 0;
int vResultado, pResultado;

//função principal
int main (){
    setlocale(LC_ALL, "Portuguese");
    int op;
    int total;
    
    do{
        printf("\nEscolha as seguintes opções abaixo:\n");
        printf("\n1 - Votar para vereador\n2 - Votar para prefeito\n3 - Apuração dos votos\n4 - Sair\n");
        scanf("%d", &op);
        switch(op){
            case 1:
                votacao_vereador();
            break;
            case 2:
                votacao_prefeito();
            break;
            case 3:
                printf("\nApuração para prefeito, tecle 1\nApuração para vereador, tecle 2\n");
                scanf("%d", &total);
                if(total == 1){
                    votos_total_prefeito();
                }else{
                    if(total == 2)
                        votos_total_vereador();
                }
            break;
            case 4:
                printf("\nPrograma finalizado!!\n");
            break;
            default:
                printf("\nOpção inválida!!\n");
            break;
        }
    }while(op != 0);
    return  0;
}

int votacao_vereador(){
    candidatos_vereador();
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

int votacao_prefeito(){
    candidatos_prefeito();
    fflush(stdin);
    do{
        if(pVoto == 11){
            printf("\nDigite 1 para confirmar e 2 para cancelar\n");
            scanf("%d", &pResultado);
            if(pResultado == 1){
                printf("\nVoto confirmado com sucesso!!\n");
                pDr++;
                return main();
            }else{
                if(pResultado == 2)
                    printf("\nVoto cancelado\n");
                    return main();
            }
        }else{
            if(pVoto == 22){
                printf("\nDigite 1 para confirmar e 2 para cancelar\n");
                scanf("%d", &pResultado);
                if(pResultado == 1){
                    printf("\nVoto confirmado com sucesso!!\n");
                    pGomes++;
                    return main();
                }else{
                    if(pResultado == 2)
                        printf("\nVoto cancelado\n");
                        return main();
                }
            }else{
                if(pVoto == 44){
                    printf("\nDigite 1 para confirmar e 2 para cancelar\n");
                    scanf("%d", &pResultado);
                    if(pResultado == 1){
                        printf("\nVoto anulado!!\n");
                        pNulo++;
                    }else{
                        if(pResultado == 2)
                            printf("\nVoto não foi anulado!\n");
                            return main();
                    }
                }
            }
        }
    }while(pVoto != 0);
    return main();
}

void candidatos_vereador(){
    printf ("\nCadidatos\n");
    printf ("\tPara vereador:\n");
    printf ("\n\t111 - Vereador Joao do Frete\n\t222 - Vereador Maria da Pamonha\n\t333 - Vereador Ze da Farmacia\n\t444 - Voto Nulo\n");
    scanf ("%d", &vVoto);
}

void candidatos_prefeito(){
    printf ("\nCadidatos\n");
    printf ("\tPara prefeito:\n");
    printf ("\n\t11 - Prefeito Dr. Zureta\n\t22 - Prefeito Senhor Gomes\n\t44 - Voto Nulo\n");
    scanf ("%d", &pVoto);
}

void votos_total_vereador(){
    printf("\nQuantidade de votos para o vereador João do Frete: %d\n", vJoao);
    printf("\nQuantidade de votos para a vereadora Maria da Pamonha: %d\n", vMaria);
    printf("\nQuantidade de votos para o vereador Ze da Farmacia: %d\n", vZe);
    printf("\nQuantidade de votos Nulos para vereador: %d\n", vNulo);
}

void votos_total_prefeito(){
    printf("\nQuantidade de votos para o prefeito Dr. Zureta: %d\n", pDr);
    printf("\nQuantidade de votos para o prefeito Senhor Gomes: %d\n", pGomes);    
    printf("\nQuantidade de votos Nulos para prefeito: %d\n", pNulo);
}