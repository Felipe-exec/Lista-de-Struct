#include<stdio.h>
#include<string.h>
#define MAX 100

typedef struct
{
	char nome[30];
	float potencia, horas;
}tEletrodomestico;

int qtd = 0;

void adicionar(tEletro e[])
{
	if(qtd == MAX)
	{
		printf("Sistema lotado\n");
	}
	printf("-=-=-=-=-=- Cadastro de Eletrodomestricos -=-=-=-=-=-");
	printf("Nome do Eletrodomestico: ");
	fflush(stdin);
	gets(e[qtd].nome);
	printf("Potencia: ");
	scanf("%f", &e[qtd].potencia);
	printf("Tempo medio ativo por dia em horas: ");
	scanf("%f", &e[qtd].horas);
	qtd++;
	printf("Adicionado.\n");
}

void listar(tEletro e[])
{
	int i;
	for(i = 0; i < qtd; i++)
	{
		printf("--------- Eletrodomestico %i -----------\n", i+1);
		printf("Nome: %s", e[i].nome);
		printf("\nPotencia: %.2f", e[i].potencia);
		printf("\nTempo Medio ativo por dia: %.2f Horas\n", e[i].horas);
		printf("-------------------------------------------\n");
	}
}

void buscaEletrodomestico(tEletro e[], char buscaNome[])
{
	int i, encontrou = 0;
	for (i = 0; i < qtd; i++)
	{
		if (strcmp(strupr(e[i].nome), strupr(buscaNome)))
		{
			printf("--------- Eletrodomestico %i -----------\n", i+1);
			printf("Nome:%s\nPotencia:%f\nTempo Medio ativo por dia:%.2f Horas\n", e[i].nome, e[i].potencia,e[i].horas);
			printf("----------------------------------------\n");
			encontrou = 1;
			break;
		}
	}
	if(!encontrou)
	{
		printf("Eletrodomestico nao foi encontrado... :(");
	}
}

void consumoTotal(tEletro e[], float valorKWh)
{
	int i;
	float consumopordia;
	for(i = 0; i < qtd; i++)
	{
		consumopordia += e[i].potencia * e[i].horas;
	}
	printf("\nConsumo Diario de KW: %.2lf", consumopordia);
	printf("\nConsumo Diario em R$: %.2lf", consumopordia * valorKWh);
	printf("\nConsumo Mensal de KW: %.2lf", consumopordia * 30);
	printf("\nConsumo Mensal em R$: %.2lf", consumopordia * valorKWh * 30);
}

int menu()
{
	int op;
	printf("-=-=-=-=-=- Cadastro de Eletrodomestricos -=-=-=-=-=-");
	printf("\n1 - Cadastrar Eletrodomestico.");
	printf("\n2 - Listar Eletrodomesticos.");
	printf("\n3 - Buscar Eletrodomestico por nome.");
	printf("\n4 - Consumo do Eletrodomestico.");
	printf("\n0 - Sair");
	scanf("%i", &op);
	return op;
}

int main()
{
	int op;
	tEletrodomestico e[MAX];
	char buscaNome[30];
	float valor KWh;
	do
	{
		op = menu();
		switch(op)
		{
			case 1: 
				adicionar(e);
				break;
			case 2:
				listar(e);
				break;
			case 3:
				printf("Digite o Eletrodomestico para a busca: ");
				fflush(stdin);
				gets(buscaNome);
				buscaEletrodomestico(e, buscaNome);
				break;
			case 4:
				printf("Qual é o valor do Consumo por hora? ");
				scanf("%f", &valorKWh);
				consumoTotal(e, valorKWh);
				break;
			case 0:
				printf("Saindo... \n");
				break;
		}
	}while(op!=0);
	return 0;
}
