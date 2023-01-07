#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string

int registrar() //Fun��o respons�vel por cadastrar os usu�rios no sistema
{
	//In�cio da cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final cria��o de vari�veis/string
	
	printf("Digite o seu CPF a ser cadastrado: "); //Coletando informa��o do usu�rio
	scanf("%s", cpf); //%s refere-se a string (para o usu�rio poder colocar a resposta)
	
	strcpy(arquivo, cpf); //Respons�vel por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" (significa escrever)
	fprintf(file, cpf); //salvo o valor da vari�vel (escreve dentro do arquvio)
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //cria o arquivo e o "a" (significa atualizar)
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	system("PAUSE");	
	
}

int consultar()
{
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("\tDigite o CPF a ser consultado: ");
	scanf("%s", cpf);
	printf("\n");
	
	FILE *file;
	file = fopen(cpf, "r"); //cria o arquivo e o "r" (significa ler)
	fclose(file);
	
	if(file == NULL)
	{
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado! \n\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf(" Essas s�o as informa��es do usu�rio: \n\n");
		printf("CPF | NOME | SOBRENOME | CARGO \n");
		printf("%s \n", conteudo);
		printf("\n\n");
		
	}
	
	system("PAUSE");
	
}

int deletar()
{
	char cpf[40];
	int confirmaDeletar;
	
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	fclose(file);
	
	if(cpf != NULL)
	{
		printf("\n Confirma deletar o cpf do usu�rio?\n\n");
		printf("Digite *1* para SIM e *2* para N�O.\n");
		printf("Op��o: ");
		scanf("%d", &confirmaDeletar); 
		
		
		switch(confirmaDeletar)
		{
			case 1:
			remove(cpf);
			printf("\nCPF do usu�rio exclu�do!\n\n");
			break;
			
			case 2:
			printf("\nCPF n�o exclu�do!\n\n");
			break;
			
			default:
			printf("Op��o inv�lida!");
			break;
		}
	}
	else
	{
		printf("Usu�rio iv�lido");
	}
	system("PAUSE");
}

int main()
{
	int opcao=0; //definindo vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
		system("cls");
		
		setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
		printf("*** Cart�rio da EBAC *** \n\n"); //inicio do menu
		printf("\t-Escolha a op��o no menu: \n\n");
		printf("\t| Op��o 1 - Registrar nomes |\n");
		printf("\t| Op��o 2 - Consultar nomes |\n");
		printf("\t| Op��o 3 - Deletar nomes   |\n");
		printf("\t| Op��o 4 - Sair do sistema |\n\n");
		printf("Op��o:"); //fim do menu
	
		scanf("%d", &opcao); //escanear o que o usu�rio selecionou
	
		system("cls"); //limpar a tela do usu�rio
		
		
		switch(opcao) //inicio da tomada de decis�o do menu
		{
			case 1:
			registrar(); //Chamada de fun��es
			break;
			
			case 2:
			consultar();
			break;
			
			case 3:
			deletar();
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema!\n");
			return 0;
			break;
		
			default:
			printf("\t * Essa op��o n�o est� disponivel!\n\n\n");
			system("PAUSE");
			break; //fim da tomada de decis�o do menu
		}    
	}
}
