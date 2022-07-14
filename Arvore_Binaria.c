#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define MAX 9

typedef struct no{
	int valor;
	struct no *direita, *esquerda;
}NoArv;

NoArv* inserir_no(NoArv *raiz, int num){
	if(raiz == NULL){
		NoArv *aux=malloc(sizeof(NoArv));
		aux->valor = num;
		aux->esquerda = NULL;
		aux->direita = NULL;
		return aux;
	}else{
		if(num < raiz->valor)
			raiz->esquerda = inserir_no(raiz->esquerda, num);
		else
			raiz->direita = inserir_no(raiz->direita, num);
			return raiz;
	}
}
	
void imprimir_preordem(NoArv *raiz){
	if(raiz){
		printf("%d", raiz->valor);
		imprimir_preordem(raiz->esquerda);
		imprimir_preordem(raiz->direita);
	}
}	

int main(){
	setlocale(LC_ALL, "Portuguese");
	NoArv *raiz= NULL;
	int op, valor[MAX];
	int cont=0;
	printf("\nAluno: Matheus Henrique Silva Cavalcanti\nEstudante de Engenharia de Software pela Faculdade UniCesumar.");
	printf("\nAlgoritmo escrito para obtenção de nota da atividade MAPA.");
	printf("\nRA número: ***211158755***,\nEm visitação preordem: 2 1 1 1 5 8 7 5 5.\nO programa tem que entregar de acordo com a sequência que foi designada acima:\n");
	printf("\nPor favor digite o RA indicado acima:\n");
	printf("\n");
	do{
		printf("\n\t0 - Sair\n\t1 - Inserir\n\t2 - Imprimir\n");
		scanf("%d", &op);
		
		switch(op){
			case 1:
				for(int i = 0; i < MAX; i++){
					printf("\n\tDigite um valor: ");
					scanf("%d", &valor[i]);
					if(valor[i]>5) cont++;
					raiz = inserir_no(raiz, valor[i]);					
				}	
				break;
			case 2:				
				system("cls");				
				printf("\n\tImpressão em visitação pré-ordem:\n\t ");
				imprimir_preordem(raiz);
				printf("\nDe acordo com as aulas ministradas pelo Prof. Pietro e pelo Prof. Erinaldo, nas disciplinas de estrutura de dados 1 e 2");
				printf("\na visitação pré-ordem, também nominada de caminhamento pré-fixado por alguns autores, ao iniciar esse percurso, é marcada");
				printf("primeiramente a raiz como visitada, e só depois as subárvores esquerta e direita são visitadas, respectivamente.");	
				break;
			default:
				if(op != 0)
					printf("\n\tOpção inválida, digite novamente!!");
		   }
	}while(op != 0);
	
	return 0;
}