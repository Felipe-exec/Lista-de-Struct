#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX 100

typedef struct n
{
	char mes[15];
	int ano;
}tNascimento;

typedef struct 
{
	char codigo[15], abate[1];
	float leite, alimento;
	struct n dataNasc;
}tGado;

qtd = 0;
anopresente = 2022;

void cadastra(tGado g[])
{
	printf("\n Cadastrar as cabeças de gado \n");
	printf("Codigo cabeça de gado: ");
	fflush(stdin);
	gets(g[qtd].codigo);
	printf("Numero de litros de leite por semana: ");
	scanf("%f", &g[qtd].leite);
	printf("Quantidade de alimento por semana: ");
	scanf("%f", &g[qtd].alimento);
	printf("Data de nascimento\n");
	printf("mes(escreva por extenso): ");
	fflush(stdin);
	gets(g[qtd].dataNasc.mes);
	printf("Ano: ");
	scanf("%i", &g[qtd].dataNasc.ano);
	
	int idade = anopresente - g[qtd].dataNasc.ano;
	if (idade > 5 || g[qtd].leite < 40)
	{
		g[qtd].abate[0] = 's';
	}
	else
	{
		g[qtd].abate[0] = 'n';
	}
	printf("Abate: %s", g[qtd].abate);
	qtd++;
}

void mostrarCadastros(tGado gados[])
{
	int i;
	if (qtd > 0)
	{
		printf("\n existe %i gado(s) cadastrados", qtd);
		for(i = 0; i < qtd; i++)
		{
			printf("\n -- GADO %i --\n", i+1);
			printf("codigo: %s\n", gados[i].codigo);
			printf("Numero de litros de leite por semana: %1.f\n", gados[i].leite);
			printf("Quantidade de alimento por semana: %1.f\n", gados[i].alimento);
			printf("Data e nascimento: %s/%i\n", gados[i].dataNasc.mes, gados[i].dataNasc.ano);
			printf("Abate: %s\n", gados[i].abate);
		}
	}
	else
	{
		printf("nao existe nenhum gado cadastrado.\n");
	}
}

float producaoTotaldeLeite(tGado gados[])
{
	int i;
	float total = 0;
	for(i=0; i < qtd; i++)
	{
		total += gados[i].leite;
	}
	return total;
}

int menu()
{
	int op;
	
	printf("-=-=-=- CONTROLE DE CABECAS DE GADO -=-=-=-\n");
	printf("1 - inserir novo gado\n");
	printf("2 - animais cadastrados\n");
	printf("3 - leite produzido por semana\n");
	printf("0 - sair\n");
	scanf("%i", &op);
	return op;
}

main()
{
	tGado g[MAX];
	int op;
	
	do
	{
		op = menu();
		switch(op)
		{
			case 1: 
				cadastra(g);
				break;
			case 2: 
				mostrarCadastros(g);
				break;
			case 3:
				printf("\n%.1f Litros produzidos por semana\n", producaoTotaldeLeite(g));
				break;
			case 0:
				printf("saindo...");
				break;
		}
		getch();
		system("cls");	
	}
	while (op!= 0);
	return 0;
}
