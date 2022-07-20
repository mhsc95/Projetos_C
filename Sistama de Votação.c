#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
//prototipacao das funcoes usadas no programa
void candidatos_vereador();
void candidatos_prefeito();
int votacao_vereador();
int votacao_prefeito();
void votos_total_vereador();
void votos_total_prefeito();

//variaveis globais, declarei fora da main pra ficar mais facil de manusear elas e ficar mais facil o entendimento
int vJoao = 0, vZe = 0, vMaria = 0, vNulo = 0, vVoto = 0;//variaveis para candidatos para vereador
int pDr = 0, pGomes = 0, pNulo = 0, pVoto = 0;//variaveis para candidatos para prefeito
int vResultado, pResultado;

//funcao principal
int main () {
	setlocale(LC_ALL, "Portuguese");
	int op;/*coloquei essas variaveis dentro da main pois vou usar elas somentes aqui na funcao
    principal, entao nao vi o motivo de colocar elas de forma global, pois irei usar somente no switch case e
    a outra pra verificar a apuracao dos votos*/
	int total;

	do {
		printf("\nEscolha as seguintes opcoes abaixo:\n");
		printf("\n1 - Votar para vereador\n2 - Votar para prefeito\n3 - Apuracao dos votos\n4 - Sair\n");
		scanf("%d", &op);
        fflush(stdin);
        system("cls");
		switch(op) {
			case 1:
				votacao_vereador();
				break;
			case 2:
				votacao_prefeito();
				break;
			case 3:
				printf("\nApuracao para prefeito tecle 1 ou para vereador tecle 2:\n");
				scanf("%d", &total);
				if(total == 1) {
					votos_total_prefeito();
				} else {
					if(total == 2)
						votos_total_vereador();
				}
				break;
			case 4:
				printf("\nPrograma finalizado!!\n");
                return 0;
				break;
			default:
				printf("\nOpcao invalida!!\n");
				break;
		}
	} while(op != 3);
	return  0;
}

int votacao_vereador() {
	candidatos_vereador();
	do {
		if(vVoto == 111) {
			printf("\nDigite 1 para confirmar e 2 para cancelar\n");
			scanf("%d", &vResultado);
			if(vResultado == 1) {
				printf("\nVoto confirmado com sucesso\n");
				vJoao++;
				return main();
			} else {
				if(vResultado == 2)
					printf("\nVoto cancelado!\n");
				return main();
			}
		} else {
			if(vVoto == 222) {
				printf("\nDigite 1 para confirmar e 2 para cancelar\n");
				scanf("%d", &vResultado);
				if(vResultado ==  1) {
					printf("\nVoto confirmado com sucesso\n");
					vMaria++;
					return main();
				} else {
					if(vResultado == 2)
						printf("\nVoto cancelado!\n");
					return main();
				}
			} else {
				if(vVoto == 333) {
					printf("\nDigite 1 para confirmar e 2 para cancelar\n");
					scanf("%d", &vResultado);
					if(vResultado ==  1) {
						printf("\nVoto confirmado com sucesso\n");
						vZe++;
						return main();
					} else {
						if(vResultado == 2)
							printf("\nVoto cancelado!\n");
						return main();
					}
				} else {
					if(vVoto == 444) {
						printf("\nDigite 1 para confirmar e 2 para cancelar\n");
						scanf("%d", &vResultado);
						if(vResultado == 1) {
							printf("\nVoto nulo\n");
							vNulo++;
							return main();
						} else {
							if(vResultado == 2)
								printf("\nVoto cancelado!!\n");
							return main();
						}
					}
				}
			}
		}
	} while(vVoto != 0);
	return 0;
}

int votacao_prefeito() {
	candidatos_prefeito();
	do {
		if(pVoto == 11) {
			printf("\nDigite 1 para confirmar e 2 para cancelar\n");
			scanf("%d", &pResultado);
			if(pResultado == 1) {
				printf("\nVoto confirmado com sucesso!!\n");
				pDr++;
				return main();
			} else {
				if(pResultado == 2)
					printf("\nVoto cancelado\n");
				return main();
			}
		} else {
			if(pVoto == 22) {
				printf("\nDigite 1 para confirmar e 2 para cancelar\n");
				scanf("%d", &pResultado);
				if(pResultado == 1) {
					printf("\nVoto confirmado com sucesso!!\n");
					pGomes++;
					return main();
				} else {
					if(pResultado == 2)
						printf("\nVoto cancelado\n");
					return main();
				}
			} else {
				if(pVoto == 44) {
					printf("\nDigite 1 para confirmar e 2 para cancelar\n");
					scanf("%d", &pResultado);
					if(pResultado == 1) {
						printf("\nVoto anulado!!\n");
						pNulo++;
						return main();
					} else {
						if(pResultado == 2)
							printf("\nVoto nao foi anulado!\n");
						return main();
					}
				}
			}
		}
	} while(pVoto != 0);
	return 0;
}

void candidatos_vereador() {
	printf ("\nCadidatos\n");
	printf ("\tPara vereador:\n");
	printf ("\n\t111 - Vereador Joao do Frete\n\t222 - Vereador Maria da Pamonha\n\t333 - Vereador Ze da Farmacia\n\t444 - Voto Nulo\n");
	scanf ("%d", &vVoto);
}

void candidatos_prefeito() {
	printf ("\nCadidatos\n");
	printf ("\tPara prefeito:\n");
	printf ("\n\t11 - Prefeito Dr. Zureta\n\t22 - Prefeito Senhor Gomes\n\t44 - Voto Nulo\n");
	scanf ("%d", &pVoto);
}

void votos_total_vereador() {
	printf("\nQuantidade de votos para o vereador Joao do Frete: %d\n", vJoao);
	printf("\nQuantidade de votos para a vereadora Maria da Pamonha: %d\n", vMaria);
	printf("\nQuantidade de votos para o vereador Ze da Farmacia: %d\n", vZe);
	printf("\nQuantidade de votos Nulos para vereador: %d\n", vNulo);
}

void votos_total_prefeito() {
	printf("\nQuantidade de votos para o prefeito Dr. Zureta: %d\n", pDr);
	printf("\nQuantidade de votos para o prefeito Senhor Gomes: %d\n", pGomes);
	printf("\nQuantidade de votos Nulos para prefeito: %d\n", pNulo);
}