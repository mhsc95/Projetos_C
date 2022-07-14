#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

//Variáveis
int destino, origem, vertices = 0;
float custo, *custos = NULL;
//Prototipação das Funções que seram usadas no código
void dijkstra(int vertices, int origem, int destino, float *custos);
void menu_mostrar(void);
void grafo_procurar(void);
void grafo_criar(void);
void grafo_explicacao(void);

//Função main(principal) na qual ira ocorrer todas as chamadas de execução do programa
int main(int argc, char **argv) {
	setlocale(LC_ALL, "Portuguese");
	int opt;
	grafo_explicacao();
	//Laço principal do menu
	do {
		opt = -1;
		//desenha o menu na tela
		menu_mostrar();
		scanf("%d",  &opt);
		switch(opt) {
			case 1:
				//opção de criar um novo grafo
				grafo_criar();
				break;
			case 2:
				//opção  de procurar caminhos com base nos dados do grafo fornecidos na opção 1
				if(vertices > 0) {
					grafo_procurar();
				}
				break;
		}
		fflush(stdin);
	} while(opt != 0);
	system("cls");
	printf("*******Programa finalizado*******\n");
	printf("*******Espero que tenha atendido aos seus requisitos*******\n");
	system("pause");
	return 0;
}

//Implementação do algoritmo de Dijkstra - função responsavel por fazer a busca do caminho de menor curto
void dijkstra(int vertices, int origem, int destino, float *custos) {
	int i, v, cont = 0;
	int *ant, *tmp;
	int *z;//vertices para os quais se conhece o caminho mínimo
	double min;
	double dist[vertices];//vetor com os custos dos caminhos

	ant = (int*)calloc(vertices,  sizeof(int *));
	if(ant == NULL) {
		system("color fc");
		printf("***ERRO: Memória insuficiente***");
		exit(-1);
	}
	tmp = (int*)calloc(vertices, sizeof(int *));
	if(tmp == NULL) {
		system("color fc");
		printf("***ERRO: Memória insuficiente***");
		exit(-1);
	}
	z = (int*)calloc(vertices, sizeof(int *));
	if(z == NULL) {
		system("color fc");
		printf("***ERRO: Memória insuficiente***");
		exit(-1);
	}
	for(i = 0; i < vertices; i++) {
		if(custos[(origem - 1)*vertices+i] != -1) {
			ant[i] = origem - 1;
			dist[i] = custos[(origem-1)*vertices+i];
		} else {
			ant[i]= -1;
			dist[i] = HUGE_VAL;
		}
		z[i] = 0;
	}
	z[origem-1] = 1;
	dist[origem-1] = 0;
	//Laço principal do algoritmo
	do {
		//Econtrando o vertice que deve entrar em z
		min = HUGE_VAL;
		for(i = 0; i < vertices; i++) {
			if(!z[i]) {
				if(dist[i]>=0 && dist[i]<min) {
					min=dist[i];
					v=i;
				}
			}
		}
		//calculando as distâncias dos novos vizinhos de z
		if(min != HUGE_VAL && v != destino - 1) {
			z[v]=1;
			for(i = 0; i < vertices; i++) {
				if(!z[i]) {
					if(custos[v*vertices+i] != -1 && dist[v]+custos[v*vertices+i]<dist[i]) {
						dist[i]= dist[v]+custos[v*vertices+i];
						ant[i]=v;
					}
				}
			}
		}
	} while(v != destino - 1 && min != HUGE_VAL);
	//Mostrar o resultado da busca
	printf("\tDe %d para %d: \t", origem, destino);
	if(min == HUGE_VAL) {
		printf("Não existe!!\n");
		printf("\tCusto: \t- \n");
	} else {
		i = destino;
		i = ant[i - 1];
		while(i != - 1) {
			tmp[cont] = i+1;
			cont++;
			i = ant[i];
		}
		for(i = cont; i  > 0; i--) {
			printf("%d -> ", tmp[i-1]);
		}
		printf("%d", destino);
		printf("\n\tCusto: %.3f\n", (float) dist[destino-1]);
	}
}
//função para se criar um novo grafo, será mostrada essa opção no menu para o usuário
void grafo_criar(void) {
	vertices = 5;
	printf("-------------Antes de iniciarmos precisamos de algumas informações, ou seja, temos que criar o grafo para buscar o melhor caminho de menor custo\n");
	printf("de acordo com que o programna solicitar.\n***ATEÇÃO: Cuidado para NÃO errar os valores, pois terá que refazer todo procedimento***\n");
	system("pause");
	system("cls");

	if(!custos) {
		free(custos);
	}
	custos = (float *)malloc(sizeof(float)*vertices*vertices);
	//se o campilador falhar em alocar dinamicamente a memória, ele vai mostrar a seguinte mensagem:
	if(custos == NULL) {
		system("color fc");
		printf("**ERRO: Memória insuficiente :-( **");
		exit(-1);
	}
	//Preechimento da matriz com -1
	for(int i = 0; i<=vertices * vertices; i++) {
		custos[i] = -1;
	}
	do {
		system("cls");
		printf("Entre com as rotas:\n");
		do {
			printf("Origem (entre 1 e %d ou 0 para sair):",vertices);
			scanf("%d", &origem);
			fflush(stdin);
		} while(origem < 0 || origem > vertices);
		if(origem) {
			do {
				printf("Destino (entre 1 e %d, menos %d): ", vertices, origem);
				scanf("%d", &destino);
				fflush(stdin);
			} while(destino < 1 || destino > vertices || destino == origem);
			do {
				printf("Custo (positivo) do %d para o %d: ", origem, destino);
				scanf("%f", &custo);
				fflush(stdin);
			} while(custo < 0);
			custos[(origem - 1)*vertices + destino - 1] = custo;
		}
	} while(origem);
}
//logo após criar p grafo, o proggrama vai armazenar as informações forncidas pelo o usuário e vai procurar os menores caminhos entre os vértices
void grafo_procurar(void) {
	int i, j;
	system("cls");
	system("color 03");
	printf("Custo por rotas a partir do início 1:\n");
	for(i = 1; i <= 1; i++) {
		for(j = 2; j<= 5; j++) {
			dijkstra(vertices, i, j, custos);
		}
		printf("\n");
	}
	system("pause");
	system("color 07");
}
//função que desenha um menu na tela de forma interativa e simples para o usuário
void menu_mostrar(void) {
	printf("\n\n------Algoritmo de Dijkstra implementado em linguagem C para buscar o melhor caminho de menor custo\n");
	printf("------Desenvolvido para a obtenção de nota da atividade MAPA de Estrutura de Dados 1\n");
	printf("------Aluno: Matheus Henrique Silva Cavalcanti.\n");
	printf("------Estudante de Engenharia de Software pela UniCesumar.\n");
	printf("\nEscolha as seguintes opções:\n");
	printf("\n\t1 - Criar grafo.\n");
	printf("\n\t2 - Ver custo por rotas.\n");
	printf("\n\t0 - Sair do programa :(\n");
}

void grafo_explicacao(void){
    printf("\n**********Uma breve explicação do que foi solicitado pela atividade MAPA de Estutura de dados 1*********");
    printf("\nO peso de cada aresta foi determinado por cada dígito do meu RA\nR.A(Registro Acadêmico) = 21115875-5.");
    printf("\nA atividade exigiu que o peso de cada aresta(aresta ponderadas, uma ligação de um vétice com outro vértice possui um valor, um peso), correspondece a cada dígito do R.A.");
    printf("\nFicando da seguinte forma:");
    printf("\n\tV = {1, 2, 3, 4, 5}");
    printf("\n\tE = {<1,2>, <1,3>, <2,4>, <2,5>, <3,2>, <3,5>, <4,5>}\nPor se tratar de um dígrafo(grafo orientado), usa-se parenteses angulares(<>)");
    printf("\n<1,2> = 2 * 6,596 = 13,192\n<1,3> = 1 * 6,596 = 6,596\n<2,4> = 1 * 6,596 = 6,596\n<2,5> = 1 * 6,596 = 6,596\n<3,2> = 5 * 6,596 = 32,980\n<3,5 = 8 * 6,596 = 52,768\n<4,5> = 7 * 6,596 = 46,172");
    printf("\n");
    printf("\nPediu-se que cada peso fosse miltiplicado por 6,596, valor baseado no preço da gasolina da época em questão"); 
}

