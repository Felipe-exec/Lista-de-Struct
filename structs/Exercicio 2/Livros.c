#include <stdio.h>
#include <string.h>

typedef struct livro
{
	char titulo[30];
	char autor[15];
	int ano;
	int prateleira;
}tlivro;
int qtd = 0;

//--------------------------------
int adicionarLivro(tlivro l[])
{
	printf("Titulo: ");
	fflush(stdin);
	gets(l[qtd].titulo);
	printf("Autor: ");
	fflush(stdin);
	gets(l[qtd].autor);
	printf("Ano: ");
	scanf("%i", &l[qtd].ano);
	printf("Prateleira: ");
	scanf("%i", &l[qtd].prateleira);
	qtd++;
	return 1;
}
//---------------------------------
void procuraAno(tlivro l[], int compAno)
{
	int i;
	for (i = 0; i < qtd; i++)
	{
		if (compAno > l[i].ano)
		{
			printf("---------------------------------------\n");
			printf("Livro %i\n", i + 1);
			printf("Titulo: %s\n",l[i].titulo);
			printf("Autor: %s\n",l[i].autor);
			printf("Ano: %i\n",l[i].ano);
			printf("Prateleira: %i\n",l[i].prateleira);
			printf("---------------------------------------\n");
		}
	}
}
//---------------------------------
void procuraLivro(tlivro l[], char livroProcura[30], int prateleiraProcura)
{
	int i, existe = 0;
	char aux[30];
	int auxprat;
	for (i = 0; i < qtd; i++)
	{
		strcpy(aux, l[i].titulo);
		if ( strcmp(strupr(aux), strupr(livroProcura) )==0 && prateleiraProcura == l[i].prateleira)
		{	
			printf("---------------------------------------\n");
			printf("Livro %i\n", i + 1);
			printf("Titulo: %s\n",l[i].titulo);
			printf("Autor: %s\n",l[i].autor);
			printf("Ano: %i\n",l[i].ano);
			printf("Prateleira: %i\n",l[i].prateleira);
			printf("---------------------------------------\n");		
			existe = 1;
		}
	}
	if (!existe)
	{
		printf("Livro nao encontrado.\n");
	}
}
//-----------------------------------
void mostraLivros(tlivro l[])
{
	int i;
	for (i = 0; i < qtd; i++)
	{
		printf("-=-=-=-=-=-=-=-=-=-=-=-");
		printf("\nLivro %i\n",i+1);
		printf("Titulo: %s\n",l[i].titulo);
		printf("Autor: %s\n",l[i].autor);
		printf("Ano: %i\n",l[i].ano);
		printf("Prateleira: %i\n",l[i].prateleira);
		printf("\n-=--=-==-==-=-=-=-==-=-=\n");
	}
}
//--------------------------------------
int menu()
{
	int op;
	printf("\nSistema de Livraria\n");
	printf("1 - Adicionar Livro.\n");
	printf("2 - Procurar Livro.\n");
	printf("3 - Mostrar Livros.\n");
	printf("4 - Leia um ano e veja os livros mais novos.\n");
	scanf("%i", &op);
	return op;
}
//---------------------------------------
main()
{
	char procuratitulo[30];
	int procuraprateleira;
	int comparaAno;
	int n=10;
	tlivro l[n];
	int op;
	do
	{
		op = menu();
		switch(op)
		{
			case 1:
				adicionarLivro(l);
				printf("Livro adicionado.");
				break;
			case 2:
				printf("\nDigite o nome do Livro: ");
				fflush(stdin);
				gets(procuratitulo);
				printf("\nDigite o numero da prateleira: ");
				scanf("%i", &procuraprateleira);
				procuraLivro(l, procuratitulo, procuraprateleira);
				break;
			case 3:
				mostraLivros(l);
				break;
			case 4:
				printf("Digite um ano: ");
				scanf("%i", &comparaAno);
				procuraAno(l, comparaAno);
				break;
		}
	}while (op!= 0);
}
