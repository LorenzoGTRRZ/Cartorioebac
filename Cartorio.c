#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço de memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings

int registro() //Função responsavel por cadastrar os usuários no sistema
{
	//inicio criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final criação de variáveis/string
	printf("Digite o CPF a ser cadastrado: "); //Coletando informacao do usuario
	scanf("%s",cpf); //%srefere-se a string
	
	strcpy(arquivo, cpf); //Responsável por copiar os valores das string
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo e o "w" sognifica escrever
	fprintf(file,cpf); // salvo o valor da variável
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese");
	
    char cpf[40];
    char conteudo[200];
    
    printf("Digite o CPF a ser consultado: ");
    scanf("%s",cpf);
    
    FILE *file;
    file = fopen(cpf,"r");
    
    if(file == NULL)
    {
    	printf(" Não foi possivel abrir o arquivo, não localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	system("pause");
	fclose(file);
}

int deletar ()
{
    char cpf[40];
    
    printf("Digite o CPF do usuário a ser deletado (apenas numeros): ");
    scanf("%s",cpf);
    
    FILE *file;
    file = fopen(cpf,"r");
    fclose(file);
    
    if(file == NULL) 
    {
    	printf("CPF não encontrado no sistema!.\n");
    	system("pause");
		return 0;	
	}
	
	fclose(file);
	
	if(remove(cpf) == 0) // identifica se o arquivo foi deletado com sucesso
	{
		printf("CPF removido com sucesso!\n");
	}
	else
	{
		printf("Erro ao remover o arquivo.\n");
	}
	
	system("pause");
	return 0;
}

int main ()  
{
	int opcao=0; //definindo variáveis
	int x=1;
	
	for(x=1;x=1;)
 {
	    
	    system("cls");
	    
        setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
    
	    printf("### Cartório da EBAC ###\n\n"); //início do menu
  	    printf("Escolha a opção desejada do menu:\n\n");
	    printf("\t1  +Registrar Nomes\n");
	    printf("\t2  +consultar Nomes\n");
	    printf("\t3  +Deletar Nomes\n\n"); 
	    printf("opção: "); //final do menu
	
	    scanf("%d", &opcao); //armazenando a escolha do usuário
	
	    system("cls"); //responsavel por limpar a tela
	
	switch(opcao) //inicio da seleção do menu
	{
		case 1:
	    registro(); //chamada de funções
		break;
		
		case 2:
		consulta();
		break;
		
		case 3:	
		deletar();
		break;
		
		default:
		printf("Essa opção não está disponivel!\n");
		system("pause");
		break;
	}
 }
	
}
