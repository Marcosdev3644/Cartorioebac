#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

int registrar() //Função responsável por cadastrar os usuários no sistema
{
	//Início da criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final criação de variáveis/string
	
	printf("Digite o seu CPF a ser cadastrado: "); //Coletando informação do usuário
	scanf("%s", cpf); //%s refere-se a string (para o usuário poder colocar a resposta)
	
	strcpy(arquivo, cpf); //Responsável por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" (significa escrever)
	fprintf(file, cpf); //salvo o valor da variável (escreve dentro do arquvio)
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
		printf("Não foi possível abrir o arquivo, não localizado! \n\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf(" Essas são as informações do usuário: \n\n");
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
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	fclose(file);
	
	if(cpf != NULL)
	{
		printf("\n Confirma deletar o cpf do usuário?\n\n");
		printf("Digite *1* para SIM e *2* para NÃO.\n");
		printf("Opção: ");
		scanf("%d", &confirmaDeletar); 
		
		
		switch(confirmaDeletar)
		{
			case 1:
			remove(cpf);
			printf("\nCPF do usuário excluído!\n\n");
			break;
			
			case 2:
			printf("\nCPF não excluído!\n\n");
			break;
			
			default:
			printf("Opção inválida!");
			break;
		}
	}
	else
	{
		printf("Usuário iválido");
	}
	system("PAUSE");
}

int main()
{
	int opcao=0; //definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
		system("cls");
		
		setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
		printf("*** Cartório da EBAC *** \n\n"); //inicio do menu
		printf("\t-Escolha a opção no menu: \n\n");
		printf("\t| Opção 1 - Registrar nomes |\n");
		printf("\t| Opção 2 - Consultar nomes |\n");
		printf("\t| Opção 3 - Deletar nomes   |\n");
		printf("\t| Opção 4 - Sair do sistema |\n\n");
		printf("Opção:"); //fim do menu
	
		scanf("%d", &opcao); //escanear o que o usuário selecionou
	
		system("cls"); //limpar a tela do usuário
		
		
		switch(opcao) //inicio da tomada de decisão do menu
		{
			case 1:
			registrar(); //Chamada de funções
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
			printf("\t * Essa opção não está disponivel!\n\n\n");
			system("PAUSE");
			break; //fim da tomada de decisão do menu
		}    
	}
}
