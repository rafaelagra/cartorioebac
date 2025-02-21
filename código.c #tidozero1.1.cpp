#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings
 
int registro() // fun��o respons�vel por cadastrar os usu�rios no sistema
 {
 	//inicio da cria��o de vari�veis
 	char arquivo[40];
 	char cpf[40];
 	char nome[40];
 	char sobrenome[40];
 	char cargo[40];
 	//final da cria��o de vari�veis/string
 	
 	printf("digite o CPF  a ser cadastrado: "); //coletando informa��es do usu�rio
 	scanf("%s", cpf); //%s refere-se � string
 	
 	strcpy(arquivo, cpf); //respons�vel por criar os valores das strings
 	
 	FILE *file; //cria o arquivo
 	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
 	fprintf(file,cpf); //salva o valor da vari�vel
 	fclose(file); //fecha o arquivo
 	
 	file = fopen(arquivo, "a");
 	fprintf(file, ",");
 	fclose(file);
 	
 	printf("digite o nome a ser cadastrado: ");
 	scanf("%s", nome);
 	
 	file = fopen(arquivo,"a");
 	fprintf(file,nome);
 	fclose(file);
 	
 	file = fopen(arquivo, "a");
 	fprintf(file, ",");
 	fclose(file);
 	
 	printf("digite o sobrenome a ser cadastrado: ");
 	scanf("%s", sobrenome);
 	
 	file = fopen(arquivo ,"a");
 	fprintf(file,sobrenome);
 	fclose(file);
 	
 	file = fopen(arquivo, "a");
 	fprintf(file, ",");
 	fclose(file);
 	
 	printf("digite o cargo a ser cadastrado: ");
 	scanf("%s",cargo);
 	
 	file = fopen(arquivo, "a");
 	fprintf(file,cargo);
 	fclose(file);
 	
 	system("pause");
 }
 
int consulta()
{
	setlocale(LC_ALL,"portuguese");	// definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		     printf("n�o foi poss�vel abrir o arquivo,n�o localizado!\n");
	}
	
	while(fgets(conteudo,200,file) != NULL)
	{
			printf("\nEssas s�o as informa��es do usu�rio: ");
			printf("%s",conteudo);
			printf("\n\n");
	}
	
	system("pause");
} 

int deletar()
{
	char cpf[40];
	
	printf("digite o CPF  do usu�rio a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
	    printf("o usu�rio n�o se encontra no sistema!\n");
		system("pause");	
	}
}
     

 
int main()
{
	int opcao =0; //definindo as vari�veis
	int laco=1;
	char senhadigitada[10];
	int comparacao;
	
	printf("### cart�rio da EBAC ###\n\n");
	printf("login de administrador!\n Digite sua senha: ");
	scanf("%s", senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin");
	
	if(comparacao == 0)
				   	              
	{	
	      system("cls");
		for(laco=1;laco=1;)
		{
			system("cls");
		
    		setlocale(LC_ALL,"portuguese");	// definindo a linguagem
	
	
			printf("## cart�rio da ebac ##\n\n"); //inicio do menu
			printf("Escolha a op��o desejada do menu:\n\n");
			printf("\t1 - Registrar nomes\n");
			printf("\t2 - Consultar nomes\n");
			printf("\t3 - Deletar nomes\n\n");
			printf("\t4 - sair do sistema\n\n");
			printf("op��o:"); // fim do menu
 		
				scanf("%d", &opcao); // armazenando a escolha do usu�rio

				system("cls"); // respons�vel por limpar a tela

    	 		switch(opcao) // inicio da sele��o do menu
     			{
     			case 1:
     			registro(); // chamada de fun��es
     			break;
     		
     			case 2:
     			consulta();
     			break;
     		
        		case 3:
        		deletar();
        		break;
        	
        		case 4:
        		printf("obrigado por utilizar o sistema!\n");
        		return 0;
        		break;
        	
        		default:
        		printf("esta op��o n�o esta dispon�vel\n");
        		system("pause");
        	   	break;
        	    }//fim da sele��o
        }
    }
    
    
    else
	printf("senha incorreta!");
}	

			
	
