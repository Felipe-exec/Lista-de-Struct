#include<stdio.h>
#include<string.h>
#define MAX 100

typedef struct aluno
{
	int matricula;
	char nome[50];
	float nota1;
	float nota2;
	float nota3;
	float mediageral;
}taluno;

int qtd=0;
//--------------------------------------
int adicionarAluno(taluno a[])
{
	if(qtd == MAX)
	{
		return 0;
	}
	printf("\n--- Regristrador de alunos ---");
	printf("\nMatricula do aluno: ");
	scanf("%i", &a[qtd].matricula);
	printf("\nNome do aluno: ");
	fflush(stdin);
	gets(a[qtd].nome);
	printf("\nNota da primeira prova: ");
	scanf("%f", &a[qtd].nota1);
	printf("\nNota da segunda prova: ");
	scanf("%f", &a[qtd].nota2);
	printf("\nNota da terceira prova: ");
	scanf("%f", &a[qtd].nota3);
	float mediageralt = (a[qtd].nota1 + a[qtd].nota2 + a[qtd].nota3)/3;
	a[qtd].mediageral = mediageralt;
	printf("\nSua media foi: %.2f\n", a[qtd].mediageral);
	qtd++;
	return 1;
}
//--------------------------------------
void mostrarAlunos(taluno a[])
{
	int loop;
	printf("\n--- MOSTRANDO ALUNOS REGISTRADOS ---\n");
	for(loop = 0; loop < qtd; loop++)
	{
		printf("\n--- FICHA DO ALUNO %i ---", loop + 1);
		printf("\nMatricula: %i", a[loop].matricula);
		printf("\nNome: %s", a[loop].nome);
		printf("\nNota da primeira prova: %.2f", a[loop].nota1);
		printf("\nNota da segunda prova: %.2f", a[loop].nota2);
		printf("\nNota da terceira prova: %.2f", a[loop].nota3);
		printf("\nSua media foi: %.2f", a[loop].mediageral);
	}
}
//--------------------------------------
void alteraAluno(taluno a[], char nomeBusca[50])
{
	int loop, existe = 0;
	char aux[50];
	for(loop = 0; loop < qtd; loop++)
	{
		strcpy(aux, a[loop].nome);
		if(strcmp(strupr(aux), strupr(nomeBusca)) == 0)
		{
			printf("Novos dados para o Aluno %s\n", a[loop].nome);
			printf("Nova matricula:"); 
			scanf("%i", &a[loop].matricula);
			printf("Novo nome:");
			fflush(stdin); 
			gets(a[loop].nome);
			printf("Primeira Nota:");
			scanf("%.2f", &a[loop].nota1);
			printf("Segunda Nota:");
			scanf("%.2f", &a[loop].nota2);
			printf("Terceira Nota:");
			scanf("%.2f", &a[loop].nota3);
			float mediageralt = (a[loop].nota1 + a[loop].nota2 + a[loop].nota3)/3;
			a[loop].mediageral = mediageralt;
			existe = 1;
		}
	}
	if (existe=0)
	{
		printf("\nAluno nao encontrado.");
	}
}
//--------------------------------------
void salvarAluno(taluno a[])
{
	int loop;
	FILE *arq;
	arq = fopen("alunos.txt","w");
	fprintf(arq,"%i\n", qtd);
	for(loop=0; loop < qtd; loop++)
	{
		fprintf(arq,"%i\n",a[loop].matricula);
		fprintf(arq,"%s\n",a[loop].nome);
		fprintf(arq,"%.2f\n",a[loop].nota1);
		fprintf(arq,"%.2f\n",a[loop].nota2);
		fprintf(arq,"%.2f\n",a[loop].nota3);
		fprintf(arq,"%.2f\n",a[loop].mediageral);
	}
	printf("Dados salvos.\n");
	fclose(arq);	
}
//---------------------------------------
void carregaAluno(taluno a[])
{
	int loop;
	FILE *arq;
	arq = fopen("alunos.txt","r");
	if (arq == NULL)
	{
		printf("Arquivo em falta ou nao encontrado.\n");
		return;
	}
	fscanf(arq, "%i", &qtd);
	printf("Carregando..");
	for(loop=0;loop < qtd; loop++)
	{
		fscanf(arq,"%i", &a[loop].matricula);
		fscanf(arq,"%s", &a[loop].nome);
		fscanf(arq,"%.2f", &a[loop].nota1);
		fscanf(arq,"%.2f", &a[loop].nota2);
		fscanf(arq,"%.2f", &a[loop].nota3);
		fscanf(arq,"%.2f", &a[loop].mediageral);
	}
	fclose(arq);
}
//----------------------------------------
void buscaAluno(taluno a[], char nomeBusca[50])
{
	int loop, existe = 0;
	char aux[50];
	for(loop = 0; loop < qtd; loop++)
	{
		strcpy(aux, a[loop].nome);
		if(strcmp(strupr(aux), strupr(nomeBusca)) == 0)
		{
			printf("\nFicha do aluno %i", loop + 1);
			printf("\nMatricula: %i", a[loop].matricula);
			printf("\nNome: %s", a[loop].nome);
			printf("\nNota da prova 1: %.2f", a[loop].nota1);
			printf("\nNota da prova 2: %.2f", a[loop].nota2);
			printf("\nNota da prova 3: %.2f", a[loop].nota3);
			printf("\nMedia Geral: %.2f", a[loop].mediageral);
			existe = 1;
		}
	}
	if (existe=0)
	{
		printf("\nAluno nao encontrado.");
	}
}
//-----------------------------------------
void removeAluno(taluno a[], char nomeBusca[50])
{
	int loop, existe = 0;
	char aux[50];
	for(loop = 0; loop < qtd; loop++)
	{
		strcpy(aux, a[loop].nome);
		if(strcmp(strupr(aux), strupr(nomeBusca)) == 0)
		{
			a[loop] = a[qtd-1];
			qtd--;
			existe = 1;
		}
	}
	if (!existe)
	{
		printf("\nAluno nao encontrado.");
	}
	else
	{
		printf("\nAluno Removido com Sucesso! (risada maligna)");
	}
}
//-----------------------------------------
void buscamaiorNota(taluno a[])
{
	int loop;
	char nomeMaior[50];
	char nomeMenor[50];
	float maior, menor;
	maior = a[0].mediageral;
	menor = a[0].mediageral;
	
	for(loop = 0; loop < qtd; loop++)
	{
		if(a[loop].mediageral > maior)
		{
			maior = a[loop].mediageral;
			strcpy(nomeMaior, a[loop].nome);
		}
		if(a[loop].mediageral < menor)
		{
			menor = a[loop].mediageral;
			strcpy(nomeMenor, a[loop].nome);
		}
	}
	printf("\nA maior nota foi do aluno %s, com uma media de %.2f", nomeMaior, maior); //tem um bug miseravel que nao mostra o nomeMaior no print.
	printf("\n*curiosidade*A menor nota foi do aluno %s, com uma media de %.2f", nomeMenor, menor);
}
//------------------------------------------
void passouounao(taluno a[])
{
	int loop;
	for (loop=0; loop < qtd; loop++)
	{
		if(a[loop].mediageral < 6.0)
		{
			printf("\nO aluno %s nao passou, pois sua Media de notas foi menor que 6", a[loop].nome);
		}
		if(a[loop].mediageral > 6.0)
		{
			printf("\nO aluno %s passou, pois sua Media de notas foi maior que 6", a[loop].nome);
		}
	}
}
//------------------------------------------
int menu()
{
	int op;
	printf("\n*** Sistema Escolar ***\n");
	printf("1- Registrar Aluno\n");
	printf("2- Mostrar todos os Alunos\n");
	printf("3- Buscar um Aluno\n");
	printf("4- Remover um Aluno\n");
	printf("5- Alterar dados de um Aluno\n");
	printf("6- Saber alunos aprovados e reprovados\n");
	printf("7- Saber a nota mais alta\n");
	printf("0- Sair\n");
	scanf("%d",&op);
	return op;
}
//-------------------------------------------
int main()
{
	taluno a[MAX];
	char buscador[50];
	int op;
	//carregaAluno(a); <<<--- esta gerando bugs na leitura do bloco de notas.. nao faço ideia de como arrumar.
	//Experimente tirar os comentarios de carregaAluno(a); , adicione alunos, feche o programa e abra de novo. Voce achara diversos bugs de leitura/reading.
	do
	{
		op = menu();
		switch(op)
		{
			case 1:
				if(adicionarAluno(a) == 1)
				{
					printf("Aluno Adicionado!");
				}
				else
				{
					printf("Limite de fichas de alunos atingidos.");
				}
				break;
			case 2:
				mostrarAlunos(a);
				break;
			case 3:
				printf("Digite o nome do aluno: ");
				fflush(stdin);
				gets(buscador);
				buscaAluno(a, buscador);
				break;
			case 4:
				printf("Digite o nome do aluno: ");
				fflush(stdin);
				gets(buscador);
				removeAluno(a, buscador);
				break;
			case 5:
				printf("Digite o nome do aluno: ");
				fflush(stdin);
				gets(buscador);
				alteraAluno(a, buscador);
				break;
			case 6:
				passouounao(a);
				break;
			case 7:
				buscamaiorNota(a);
				break;
			case 0:
				salvarAluno(a);
				break;
			default:
				printf("Invalido.");
		}
	}while(op != 0);
	return 0;
}










