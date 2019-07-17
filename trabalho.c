/* Trabalho de Fundamentos de Algoritmos - Informática/UEM 2019
   Um programa feito em C para cadastro de Clientes.
   Funções: Cadastro, Remoção, Listagem e Remoção.
   By: Filipe Moreno and Gabriel Galego
  Atualizado em: 10/06 - 19:00 PM
*/

// INICIO DAS BIBLIOTECAS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// FIM DAS BIBLIOTECAS

//INÍCIO DA FUNÇÃO DELAY

void delay(int number_of_seconds)
{
    clock_t start_time = clock();
    while (clock() < start_time + number_of_seconds);
}

// FIM DA FUNÇÃO DELAY

// INICIO DA FUNCAO LIMPAR SCANF

void limpar(void)
{
    int c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}

// FIM DA FUNCAO LIMPAR SCANF

// INICIO DA ESTRUTURA DE CADASTRO

struct cadastro
{
    char nome[200];
    char endereco[200];
    char municipio[200];
    char uf[200];
    char cep[200];
    char numero[200];
    char bairro[200];
    char telefone[200];
    char nascimento[200];
    char rg[200];
    char cpf[200];
    char sexo[200];
    char estado_civil[200];
    char email[200];
    char nacionalidade[200];
    char celular[200];
    float dinheiro;
    int nconta;

};

// FIM DA ESTRUTURA DE CADASTRO

// INICIO DAS VARIAVEIS GLOBAIS

struct cadastro cliente[100];
char usuario[15], senha[15];
int qtdcliente = 0;

// FIM DAS VARIAVEIS GLOBAIS

// INICIO DA FUNÇÃO DE MENU

void menu()
{
	int opcao_menu;
    printf(" Voce deseja realizar outra operacao?\n");
    printf(" 1 - Sim\n");
    printf(" 2 - Nao\n");
    printf(" -> ");
    scanf("%i", &opcao_menu);
    limpar();
    switch (opcao_menu)
    {
        case 1:
			system("@cls||clear");
            escolher();
            break;
        case 2:
            printf("\n");
            printf(" Finalizando o programa...\n");
			printf(" Ate mais!\n");
			break;
        default:
            printf(" Ei, digite uma opcao valida!\n");
            menu();
            break;
    }
}

// FIM DA FUNÇÃO DE MENU

// INICIO DA FUNÇÃO DE CADASTRO

void cadastro()
{
	qtdcliente++;
	printf("\n");
	printf(" =======--- Cadastrando Cliente ---======= \n");
	printf("\n");
	printf(" Informe o nome do Cliente: ");
	fgets(cliente[qtdcliente].nome, 200, stdin);
	printf(" Informe o endereco do Cliente: ");
	fgets(cliente[qtdcliente].endereco, 200, stdin);
    printf(" Informe o bairro do Cliente: ");
	fgets(cliente[qtdcliente].bairro, 200, stdin);
    printf(" Informe o CEP do Cliente: ");
    fgets(cliente[qtdcliente].cep, 200, stdin);
    printf(" Informe o numero da residencia do Cliente: ");
	fgets(cliente[qtdcliente].numero, 200, stdin);
	printf(" Informe o municipio do Cliente: ");
	fgets(cliente[qtdcliente].municipio, 200, stdin);
    printf(" Informe o UF do Cliente: ");
    fgets(cliente[qtdcliente].uf, 200, stdin);
	printf(" Informe o telefone do Cliente: ");
	fgets(cliente[qtdcliente].telefone, 200, stdin);
	printf(" Informe o celular do Cliente: ");
	fgets(cliente[qtdcliente].celular, 200, stdin);
	printf(" Informe a data de nascimento do Cliente (DD MM AAAA): ");
	fgets(cliente[qtdcliente].nascimento, 200, stdin);
	printf(" Informe o sexo do Cliente: ");
	fgets(cliente[qtdcliente].sexo, 200, stdin);
	printf(" Informe a nacionalidade do Cliente: ");
	fgets(cliente[qtdcliente].nacionalidade, 200, stdin);
	printf(" Informe o RG do Cliente: ");
	fgets(cliente[qtdcliente].rg, 200, stdin);
	printf(" Informe o CPF do Cliente: ");
	fgets(cliente[qtdcliente].cpf, 200, stdin);
	printf(" Informe o estado civil do Cliente: ");
	fgets(cliente[qtdcliente].estado_civil, 200, stdin);
	printf(" Informe o email do Cliente: ");
	fgets(cliente[qtdcliente].email, 200, stdin);
	cliente[qtdcliente].dinheiro = 0;
	delay(500);
	printf("\n");
	printf(" Cadastro realizado com Sucesso!\n");
	srand(time(NULL));
	cliente[qtdcliente].nconta = rand() % 100000;
	printf(" Numero da Conta: %i\n", cliente[qtdcliente].nconta);
    delay(500);
    printf("\n");

    FILE *fp;

    fp = fopen("db.txt", "a+");

    if (fp==NULL)
    {
        printf("Erro ao criar arquivo");
    }

    fprintf(fp, "CPF %s", cliente[qtdcliente].cpf);
    fprintf(fp, "%s", cliente[qtdcliente].nome);
    fprintf(fp, "%s", cliente[qtdcliente].endereco);
    fprintf(fp, "%s", cliente[qtdcliente].bairro);
    fprintf(fp, "%s", cliente[qtdcliente].cep);
    fprintf(fp, "%s", cliente[qtdcliente].numero);
    fprintf(fp, "%s", cliente[qtdcliente].municipio);
    fprintf(fp, "%s", cliente[qtdcliente].uf);
    fprintf(fp, "%s", cliente[qtdcliente].telefone);
    fprintf(fp, "%s", cliente[qtdcliente].celular);
    fprintf(fp, "%s", cliente[qtdcliente].nascimento);
    fprintf(fp, "%s", cliente[qtdcliente].nacionalidade);
    fprintf(fp, "%s", cliente[qtdcliente].rg);
    fprintf(fp, "%s", cliente[qtdcliente].estado_civil);
    fprintf(fp, "%s", cliente[qtdcliente].email);
    fprintf(fp, "%.2f\n", cliente[qtdcliente].dinheiro);
    fprintf(fp, "%i\n", cliente[qtdcliente].nconta);
    fclose(fp);

	menu();
}

// FIM DA FUNÇÃO DE CADASTRO

// INICIO DA FUNÇÃO DE VISUALIZAR

void visualizar()
{
    int i = 0;
    char cpf[20];

	printf("\n");
    printf(" Por favor, insira o CPF do cliente: ");
    fgets(cpf, 20, stdin);

	while (i <= qtdcliente)
	{
    	if (strcmp(cpf, cliente[i].cpf) == 0)
    	{
			printf("\n");
			printf(" =======--- Visualizando Cliente ---======= \n");
		    printf(" Nome: %s", cliente[i].nome);
		    printf(" Endereco: %s", cliente[i].endereco);
		    printf(" Municipio: %s", cliente[i].municipio);
		    printf(" Bairro: %s", cliente[i].bairro);
		    printf(" CEP: %s", cliente[i].cep);
		    printf(" Num Residencia: %s", cliente[i].numero);
		    printf(" UF: %s", cliente[i].uf);
		    printf(" Telefone: %s", cliente[i].telefone);
		    printf(" Celular: %s", cliente[i].celular);
		    printf(" Nascimento: %s", cliente[i].nascimento);
		    printf(" Sexo: %s", cliente[i].sexo);
		    printf(" Nacionalidade: %s", cliente[i].nacionalidade);
		    printf(" RG: %s", cliente[i].rg);
		    printf(" CPF: %s", cliente[i].cpf);
		    printf(" Estado Civil: %s", cliente[i].estado_civil);
		    printf(" Email: %s", cliente[i].email);
		    printf(" Saldo: R$ %.2f\n", cliente[i].dinheiro);
		    printf(" Numero da Conta: %i\n", cliente[i].nconta);
		    printf(" #ID: %i\n", i);
		    printf(" =======--- Visualizando Cliente ---======= \n");
		    printf("\n");
		    delay(1000);
		    menu();
		}
		else if (i == qtdcliente)
		{
			printf("\n");
			printf(" Erro1: Cliente nao encontrado.\n\n");
			menu();
		}
		i++;
	}
}

// FIM DA FUNÇÃO DE VISUALIZAR

// INICIO DA FUNÇÃO DE EDITAR

void editar()
{
    int i = 0, opcao;
    char cpf[20];

    printf("\n");
	printf(" Por favor, insira o CPF do cliente: ");
    fgets(cpf, 20, stdin);
    printf("\n");

	while (i <= qtdcliente)
	{
    	if (strcmp(cpf, cliente[i].cpf) == 0)
    	{
		    printf(" O que deseja alterar?\n");
		    printf("  1 - Nome\n");
		    printf("  2 - Endereco\n");
		    printf("  3 - Municipio\n");
		    printf("  4 - Bairro\n");
		    printf("  5 - CEP\n");
		    printf("  6 - Num Residencia\n");
		    printf("  7 - UF\n");
		    printf("  8 - Telefone\n");
		    printf("  9 - Celular\n");
		    printf(" 10 - Nascimento\n");
		    printf(" 11 - Sexo\n");
		    printf(" 12 - Nacionalidade\n");
		    printf(" 13 - RG\n");
		    printf(" 14 - CPF\n");
		    printf(" 15 - Estado Civil\n");
		    printf(" 16 - Email\n");
		    printf(" 17 - Saldo\n");
		    printf("\n");
		    printf(" 0 - Voltar ao menu principal\n");
		    printf("\n");
		    printf(" Digite uma opcao: ");
		    scanf("%i", &opcao);
		    limpar();
		    switch (opcao)
		    {
		        case 1:
		            printf("\n Informe o novo 'Nome': ");
		            fgets(cliente[i].nome, 200, stdin);
		            delay(500);
		            printf("\n Cadastro atualizado com sucesso!\n");
		            printf("\n");
		            delay(500);
		            menu();
		            break;
		        case 2:
		            printf(" Informe o novo 'Endereco': ");
		            fgets(cliente[i].endereco, 200, stdin);
		            delay(500);
		            printf("\n Cadastro atualizado com sucesso!\n");
		            printf("\n");
		            delay(500);
		            menu();
		            break;
		        case 3:
		            printf("\n Informe o novo 'Municipio': ");
		            fgets(cliente[i].municipio, 200, stdin);
		            delay(500);
		            printf("\n Cadastro atualizado com sucesso!\n");
		            printf("\n");
		            delay(500);
		            menu();
		            break;
		        case 4:
		            printf("\n Informe o novo 'Bairro': ");
		            fgets(cliente[i].bairro, 200, stdin);
		            delay(500);
		            printf("\n Cadastro atualizado com sucesso!\n");
		            printf("\n");
		            delay(500);
		            menu();
		            break;
		        case 5:
		            printf("\n Informe o novo 'CEP': ");
		            fgets(cliente[i].cep, 200, stdin);
		            delay(500);
		            printf("\n Cadastro atualizado com sucesso!\n");
		            printf("\n");
		            delay(500);
		            menu();
		            break;
		        case 6:
		            printf("\n Informe o novo 'Numero da Residencia': ");
		            fgets(cliente[i].numero, 200, stdin);
		            delay(500);
		            printf("\n Cadastro atualizado com sucesso!\n");
		            printf("\n");
		            delay(500);
		            menu();
		            break;
		        case 7:
		            printf("\n Informe a nova 'UF': ");
		            fgets(cliente[i].uf, 200, stdin);
		            delay(500);
		            printf("\n Cadastro atualizado com sucesso!\n");
		            printf("\n");
		            delay(500);
		            menu();
		            break;
		        case 8:
		            printf("\n Informe o novo 'Telefone': ");
		            fgets(cliente[i].telefone, 200, stdin);
		            delay(500);
		            printf("\n Cadastro atualizado com sucesso!\n");
		            printf("\n");
		            delay(500);
		            menu();
		            break;
		        case 9:
		            printf("\n Informe o novo 'Celular': ");
		            fgets(cliente[i].celular, 200, stdin);
		            delay(500);
		            printf("\n Cadastro atualizado com sucesso!\n");
		            printf("\n");
		            delay(500);
		            menu();
		            break;
		        case 10:
		            printf("\n Informe a nova 'Data de Nascimento' (DD/MM/AAAA): ");
		            fgets(cliente[i].nascimento, 200, stdin);
		            delay(500);
		            printf("\n Cadastro atualizado com sucesso!\n");
		            printf("\n");
		            delay(500);
		            menu();
		            break;
		        case 11:
		            printf("\n Informe o novo 'Sexo': ");
		            fgets(cliente[i].sexo, 200, stdin);
		            delay(500);
		            printf("\n Cadastro atualizado com sucesso!\n");
		            printf("\n");
		            delay(500);
		            menu();
		            break;
		        case 12:
		            printf("\n Informe a nova 'Nacionalidade': ");
		            fgets(cliente[i].nacionalidade, 200, stdin);
		            delay(500);
		            printf("\n Cadastro atualizado com sucesso!\n");
		            printf("\n");
		            delay(500);
		            menu();
		            break;
		        case 13:
		            printf("\n Informe o novo 'RG': ");
		            fgets(cliente[i].rg, 200, stdin);
		            delay(500);
		            printf("\n Cadastro atualizado com sucesso!\n");
		            printf("\n");
		            delay(500);
		            menu();
		            break;
		        case 14:
		            printf("\n Informe o novo 'CPF': ");
		            fgets(cliente[i].cpf, 200, stdin);
		            delay(500);
		            printf("\n Cadastro atualizado com sucesso!\n");
		            printf("\n");
		            delay(500);
		            menu();
		            break;
		        case 15:
		            printf("\n Informe o novo 'Estado Civil': ");
		            fgets(cliente[i].estado_civil, 200, stdin);
		            delay(500);
		            printf("\n Cadastro atualizado com sucesso!\n");
		            printf("\n");
		            delay(500);
		            menu();
		            break;
		        case 16:
		            printf("\n Informe o novo 'Email': ");
		            fgets(cliente[i].email, 200, stdin);
		            delay(500);
		            printf("\n Cadastro atualizado com sucesso!\n");
		            printf("\n");
		            delay(500);
		            menu();
		            break;
                case 17:
		            printf("\n Informe o novo 'Saldo': ");
		            scanf("%f", &cliente[i].dinheiro);
		            delay(500);
		            printf("\n Cadastro atualizado com sucesso!\n");
		            printf("\n");
		            delay(500);
		            menu();
		            break;
		        case 0:
		            escolher();
		            break;
		        default:
		            printf("\n Ei, informe uma opcao valida!\n");
		            editar();
		            break;
			}
		}
		else if (i == qtdcliente)
		{
			printf(" Erro2: Cliente nao encontrado.\n\n");
			menu();
		}
		i++;
    }
}

// FIM DA FUNÇÃO DE EDITAR

// INICIO DA FUNÇÃO ESTATÍSTICA

void estatistica()
{
    float saldototal = 0;
    int i;

    for (i=1;i<=qtdcliente; i++)
    {
        saldototal += cliente[i].dinheiro;
    }

    if (qtdcliente == 0)
    {
        printf("\n");
        printf(" =======--- Estatisticas ---======= \n");
        printf(" Nao existem cliente cadastrado.\n\n");
        delay(500);
        menu();
    }
    else if (qtdcliente == 1)
    {
        printf("\n");
        printf(" =======--- Estatisticas ---======= \n");
        printf(" Existe apenas %i usuario cadastrados.\n", qtdcliente);
        printf(" Existe R$ %.2f depositados no total.\n\n",saldototal);
        delay(500);
        menu();
    }
    else
    {
        printf("\n");
        printf(" =======--- Estatisticas ---======= \n");
        printf(" Existem %i usuarios cadastrados.\n", qtdcliente);
        printf(" Existe R$ %.2f depositados no total.\n\n",saldototal);
        delay(500);
        menu();
    }

}

// FIM DA FUNÇÃO ESTATÍSTICA

// INICIO DA FUNÇÃO LISTAR

void listar()
{
    int i, opcao, x;
    char pass[20];

    printf("\n Digite a senha do administrador para continuar: ");
    scanf("%s", &pass);
	limpar();
	printf("\n Autenticando");
	for (x=0; x<3; x++)
	{
		delay(300);
		printf(".");
	}
    if (strcmp(pass, "pass") != 0)
    {
        printf("\n Usuario e/ou senha errada\n\n");
        menu();
    }
    else
    {
	    system("@cls || clear");
		printf("\n");
	    printf(" O que deseja listar?\n");
	    printf("\n");
	    printf("  1 - Nome\n");
	    printf("  2 - Endereco\n");
	    printf("  3 - Municipio\n");
	    printf("  4 - Bairro\n");
	    printf("  5 - CEP\n");
	    printf("  6 - Num Residencia\n");
	    printf("  7 - UF\n");
	    printf("  8 - Telefone\n");
	    printf("  9 - Celular\n");
	    printf(" 10 - Nascimento\n");
	    printf(" 11 - Sexo\n");
	    printf(" 12 - Nacionalidade\n");
	    printf(" 13 - RG\n");
	    printf(" 14 - CPF\n");
	    printf(" 15 - Estado Civil\n");
	    printf(" 16 - Email\n");
	    printf(" 17 - Saldo\n");
	    printf("\n");
	    printf(" 0 - Voltar ao menu principal\n");
	    printf("\n");
	    printf(" Selecione uma opcao");
	    printf("\n -> ");
	    scanf("%i", &opcao);
	    printf("\n");
	    switch (opcao)
	    {
	        case 1:
	            for (i=0; i <= qtdcliente; i++)
	            {
	                if (i == 0 || qtdcliente == 0)
	                {
	                    printf(" Nao ha registros para listar.\n");
	                    printf("\n");
	                }
	                else
	                {
	                    printf(" %i. Nome: %s", i, cliente[i].nome);
	                }
	            }
	            printf("\n");
				menu();
	            break;
	        case 2:
	            for (i=1; i <= qtdcliente; i++)
	            {
	                if (i == 0 || qtdcliente == 0)
	                {
	                    printf(" Nao ha registros para listar.\n");
	                    printf("\n");
	                }
	                else
	                {
	                    printf(" %i. Endereco: %s", i, cliente[i].endereco);
	                }
	            }
	            printf("\n");
			    menu();
	            break;
	        case 3:
	            for (i=1; i <= qtdcliente; i++)
	            {
	                if (i == 0 || qtdcliente == 0)
	                {
	                    printf(" Nao ha registros para listar.\n");
	                    printf("\n");
	                }
	                else
	                {
	                    printf(" %i. Municipio: %s", i, cliente[i].municipio);
	                }
	            }
	            printf("\n");
				menu();
	            break;
	        case 4:
	            for (i=1; i <= qtdcliente; i++)
	            {
	                if (i == 0 || qtdcliente == 0)
	                {
	                    printf(" Nao ha registros para listar.\n");
	                    printf("\n");
	                }
	                else
	                {
	                    printf(" %i. Bairro: %s", i, cliente[i].bairro);
	                }
	            }
	            printf("\n");
	            menu();
	            break;
	        case 5:
	            for (i=1; i <= qtdcliente; i++)
	            {
	                if (i == 0 || qtdcliente == 0)
	                {
	                    printf(" Nao ha registros para listar.\n");
	                    printf("\n");
	                }
	                else
	                {
	                    printf(" %i. CEP: %s", i, cliente[i].cep);
	                }
	            }
	            printf("\n");
				menu();
	            break;
	        case 6:
	            for (i=1; i <= qtdcliente; i++)
	            {
	                if (i == 0 || qtdcliente == 0)
	                {
	                    printf(" Nao ha registros para listar.\n");
	                    printf("\n");
	                }
	                else
	                {
	                    printf(" %i. Num. Residencia: %s", i, cliente[i].numero);
	                }
	            }
	            printf("\n");
				menu();
	            break;
	        case 7:
	            for (i=1; i <= qtdcliente; i++)
	            {
	                if (i == 0 || qtdcliente == 0)
	                {
	                    printf(" Nao ha registros para listar.\n");
	                    printf("\n");
	                }
	                else
	                {
	                    printf(" %i. UF: %s", i, cliente[i].uf);
	                }
	            }
	            printf("\n");
				menu();
	            break;
	        case 8:
	            for (i=1; i <= qtdcliente; i++)
	            {
	                if (i == 0 || qtdcliente == 0)
	                {
	                    printf(" Nao ha registros para listar.\n");
	                    printf("\n");
	                }
	                else
	                {
	                    printf(" %i. Telefone: %s", i, cliente[i].telefone);
	                }
	            }
	            printf("\n");
				menu();
	            break;
	        case 9:
	            for (i=1; i <= qtdcliente; i++)
	            {
	                if (i == 0 || qtdcliente == 0)
	                {
	                    printf(" Nao ha registros para listar.\n");
	                    printf("\n");
	                }
	                else
	                {
	                    printf(" %i. Celular: %s", i, cliente[i].celular);
	                }
	            }
	            printf("\n");
				menu();
	            break;
	        case 10:
	            for (i=1; i <= qtdcliente; i++)
	            {
	                if (i == 0 || qtdcliente == 0)
	                {
	                    printf(" Nao ha registros para listar.\n");
	                    printf("\n");
	                }
	                else
	                {
	                    printf(" %i. Data Nascimento: %s", i, cliente[i].nascimento);
	                }
	            }
	            printf("\n");
				menu();
	            break;
	        case 11:
	            for (i=1; i <= qtdcliente; i++)
	            {
	                if (i == 0 || qtdcliente == 0)
	                {
	                    printf(" Nao ha registros para listar.\n");
	                    printf("\n");
	                }
	                else
	                {
	                    printf(" %i. Sexo: %s", i, cliente[i].sexo);
	                }
	            }
	            printf("\n");
				menu();
	            break;
	        case 12:
	            for (i=1; i <= qtdcliente; i++)
	            {
	                if (i == 0 || qtdcliente == 0)
	                {
	                    printf(" Nao ha registros para listar.\n");
	                    printf("\n");
	                }
	                else
	                {
	                    printf(" %i. Nacionalidade: %s", i, cliente[i].nacionalidade);
	                }
	            }
	            printf("\n");
				menu();
	            break;
	        case 13:
	            for (i=1; i <= qtdcliente; i++)
	            {
	                if (i == 0 || qtdcliente == 0)
	                {
	                    printf(" Nao ha registros para listar.\n");
	                    printf("\n");
	                }
	                else
	                {
	                    printf(" %i. RG: %s", i, cliente[i].rg);
	                }
	            }
	            printf("\n");
				menu();
	            break;
	        case 14:
	            for (i=1; i <= qtdcliente; i++)
	            {
	                if (i == 0 || qtdcliente == 0)
	                {
	                    printf(" Nao ha registros para listar.\n");
	                    printf("\n");
	                }
	                else
	                {
	                    printf(" %i. CPF: %s", i, cliente[i].cpf);
	                }
	            }
	            printf("\n");
				menu();
	            break;
	        case 15:
	            for (i=1; i <= qtdcliente; i++)
	            {
	                if (i == 0 || qtdcliente == 0)
	                {
	                    printf(" Nao ha registros para listar.\n");
	                    printf("\n");
	                }
	                else
	                {
	                    printf(" %i. Estado Civil: %s", i, cliente[i].estado_civil);
	                }
	            }
	            printf("\n");
				menu();
	            break;
	        case 16:
	            for (i=1; i <= qtdcliente; i++)
	            {
	                if (i == 0 || qtdcliente == 0)
	                {
	                    printf(" Nao ha registros para listar.\n");
	                    printf("\n");
	                }
	                else
	                {
	                    printf(" %i. Email: %s", i, cliente[i].email);
	                }
	            }
	            printf("\n");
				menu();
	            break;
	        case 17:
	            for (i=1; i <= qtdcliente; i++)
	            {
	                if (i == 0 || qtdcliente == 0)
	                {
	                    printf(" Nao ha registros para listar.\n");
	                    printf("\n");
	                }
	                else
	                {
	                    printf(" %i. Saldo: R$ %.2f", i, cliente[i].dinheiro);
	                }
	            }
	            printf("\n");
				menu();
	            break;
	        case 18:
	            for (i=1; i <= qtdcliente; i++)
	            {
	                if (i == 0 || qtdcliente == 0)
	                {
	                    printf(" Nao ha registros para listar.\n");
	                    printf("\n");
	                }
	                else
	                {
	                    printf(" %i. Numero da Conta: %i", i, cliente[i].nconta);
	                }
	            }
	            printf("\n");
				menu();
	            break;
	        case 0:
	            system("@cls || clear");
				escolher();
	            break;
	        default:
	            printf(" Ei, informe uma opcao valida!\n");
	            printf("\n");
	            editar();
	            break;
	    }
	}
}

// FIM DA FUNÇÃO LISTAR

// INICIO DA FUNÇÃO EXCLUIR

void excluir()
{
    int i = 0, id, c, x;
    char cpf[20];

    printf(" Por favor, insira o CPF do cliente: ");
    fgets(cpf, 20, stdin);

	while (i < qtdcliente)
	{
    	if (strcmp(cpf, cliente[i].cpf) == 0)
    	{
            printf("\n");
            printf(" Excluindo");
            for (x=0; x<3; x++)
            {
				delay(500);
				printf(".");
			}
            delay(1000);
            printf("\n");
            for (c=i; c<qtdcliente; c++)
            {
                strcpy(cliente[c].nome, cliente[c+1].nome);
                strcpy(cliente[c].endereco, cliente[c+1].endereco);
                strcpy(cliente[c].municipio, cliente[c+1].municipio);
                strcpy(cliente[c].bairro, cliente[c+1].bairro);
                strcpy(cliente[c].cep, cliente[c+1].cep);
                strcpy(cliente[c].numero, cliente[c+1].numero);
                strcpy(cliente[c].uf, cliente[c+1].uf);
                strcpy(cliente[c].telefone, cliente[c+1].telefone);
                strcpy(cliente[c].celular, cliente[c+1].celular);
                strcpy(cliente[c].nascimento, cliente[c+1].nascimento);
                strcpy(cliente[c].sexo, cliente[c+1].sexo);
                strcpy(cliente[c].nacionalidade, cliente[c+1].nacionalidade);
                strcpy(cliente[c].rg, cliente[c+1].rg);
                strcpy(cliente[c].cpf, cliente[c+1].cpf);
                strcpy(cliente[c].estado_civil, cliente[c+1].estado_civil);
                strcpy(cliente[c].email, cliente[c+1].email);
                cliente[c+1].dinheiro = cliente[c].dinheiro;
                cliente[c+1].nconta = cliente[c].nconta;
        	}
   		}
   		else if (i == qtdcliente)
		{
			printf("\n");
			printf(" Erro3: Cliente nao encontrado.\n\n");
			menu();
		}
	i++;
	}
    qtdcliente--;
	printf("\n");
    printf(" Cadastro excluido com sucesso!\n\n");
    menu();
}

// FIM DA FUNÇÃO EXCLUIR

// INCIO DA FUNÇÃO DEPOSITO

void deposito()
{
    int i = 0;
    float qtd1 = 0, qtd2 = 0;
    char cpf[20];

    printf("\n Por favor, insira o CPF do cliente: ");
    fgets(cpf, 20, stdin);

	while (i <= qtdcliente)
	{
    	if (strcmp(cpf, cliente[i].cpf) == 0)
    	{
            printf("\n Deposito para: %s\n", cliente[i].nome);
            printf("\n Insira o valor que deseja depositar: ");
            scanf("%f", &qtd1);
            printf(" Para confirmar o deposito, digite o valor novamente:  ");
            scanf("%f", &qtd2);
            if (qtd1 == qtd2)
            {
                cliente[i].dinheiro += qtd1;
                delay(1000);
                printf("\n");
                printf(" =======--- Deposito ---======= \n");
                printf(" Deposito realizado com sucesso!\n");
                printf(" Valor: R$%.2f\n", qtd1);
                printf(" Saldo em conta: R$%.2f\n", cliente[i].dinheiro);
                printf(" =======--- Deposito ---======= \n");
                printf("\n");
                menu();
            }

            else
            {
                printf("\n");
                delay(1000);
                printf(" Erro: Os valores inseridos nao sao iguais\n\n");
                menu();
            }
    	}
    	else if (i == qtdcliente)
		{
			printf("\n");
			delay(1000);
			printf(" Erro4: Cliente nao encontrado.\n\n");
			menu();
		}
    	i++;
	}
}

void saque()
{
    int i = 0;
    float qtd1 = 0, qtd2 = 0;
    char cpf[20];

    printf("\n Por favor, insira o CPF do cliente: ");
    fgets(cpf, 20, stdin);

	while (i <= qtdcliente)
	{
    	if (strcmp(cpf, cliente[i].cpf) == 0)
    	{
            printf("\n Sacando de: %s\n", cliente[i].nome);
            printf("\n Insira o valor que deseja realizar o saque: ");
            scanf("%f", &qtd1);
            printf(" Para confirmar o saque, digite o valor novamente:  ");
            scanf("%f", &qtd2);
            if (qtd1 == qtd2)
            {
                if (cliente[i].dinheiro >= qtd1)
                {
                    cliente[i].dinheiro -= qtd1;
                    delay(1000);
                    printf("\n");
                    printf(" =======--- Saque ---======= \n");
                    printf(" Saque realizado com sucesso!\n");
                    printf(" Valor: R$%2.f\n", qtd1);
                    printf(" Saldo em conta: R$%.2f\n", cliente[i].dinheiro);
                	printf(" =======--- Deposito ---======= \n");
                    printf("\n");
                    menu();
                }
                else
                {
                    printf("\n");
                    delay(1000);
                    printf(" Erro: O cliente nao possui saldo suficiente.\n");
                    printf("\n");
                    menu();
                }
            }
            else
            {
                printf("\n");
                delay(1000);
                printf(" Os valores inseridos nao sao iguais\n");
                deposito();
            }
    	}
    	else if (i == qtdcliente)
		{
			printf("\n Erro5: Cliente nao encontrado.\n\n");
			menu();
		}
    	i++;
	}
}

// FIM DA FUNÇAO DEPOSITO

// INICIO DA FUNÇÃO EXTRATO

void extrato()
{
    int i = 0, x;
    float qtd1 = 0, qtd2 = 0;
    char cpf[20];

    printf("\n Por favor, insira o CPF do cliente: ");
    fgets(cpf, 20, stdin);

	while (i <= qtdcliente)
	{
    	if (strcmp(cpf, cliente[i].cpf) == 0)
    	{
            printf("\n Buscando");
            for (x=0; x<3; x++)
            {
            	printf(".");
            	delay(500);
			}
            printf("\n");
            printf("\n Cliente: %s\n", cliente[i].nome);
			printf(" Saldo disponivel: R$%.2f \n\n", cliente[i].dinheiro);
			menu();
    	}
    	else if (i == qtdcliente)
		{
			printf("\n Erro6: Cliente nao encontrado.\n\n");
			menu();
		}
    	i++;
	}
}

// FIM DA FUNÇÃO EXTRATO

// INICIO DA FUNCAO ESCOLHA

void escolher()
{
    int opcao;

	printf("\n ========---- Menu ----======== \n");
	printf(" 1 - Cadastrar um novo Cliente\n");
    printf(" 2 - Atualizar cadastro de um Cliente\n");
    printf(" 3 - Excluir cadastro de um Cliente\n");
	printf(" 4 - Visualizar cadastro de um Cliente\n");
    printf(" 5 - Depositar\n");
    printf(" 6 - Sacar\n");
    printf(" 7 - Extrato\n");
    printf(" 8 - Listar todas informacoes cadastradas\n");
	printf(" 9 - Estatisticas\n\n");
	printf(" 0 - Sair\n\n");
	printf(" Por favor, selecione uma opcao.\n");
	printf(" -> ");
	scanf("%i", &opcao);
    limpar();

    switch (opcao)
    {
        case 0:
            printf("\n");
            printf(" Finalizando o programa...\n");
            printf(" Ate mais!\n");
            break;
        case 1:
            printf("\n");
            printf(" Voce selecionou: 'Cadastrar novo Cliente'...\n");
            printf(" Aguarde um segundo...\n");
            delay(500);
            printf("\n");
            system("@cls||clear");
            cadastro();
            break;
        case 2:
            printf("\n");
            printf(" Voce selecionou: 'Atualizar dados de um Cliente'...\n");
            printf(" Aguarde um segundo...\n");
            delay(500);
            printf("\n");
            system("@cls||clear");
            editar();
            break;
        case 3:
            printf("\n");
            printf(" Voce selecionou: 'Excluir cadastro de um Cliente'\n");
            printf(" Aguarde um segundo...\n");
            delay(500);
            printf("\n");
            system("@cls||clear");
            excluir();
            break;
        case 4:
            printf("\n");
            printf(" Voce selecionou: 'Visualizar cadastro de um cliente Cliente'\n");
            printf(" Aguarde um segundo...\n");
            delay(500);
            printf("\n");
            system("@cls||clear");
            visualizar();
            break;
        case 5:
            printf("\n");
            printf(" Voce selecionou: 'Depositar'\n");
            printf(" Aguarde um segundo...\n");
            delay(500);
            system("@cls||clear");
            deposito();
            break;
        case 6:
            printf("\n");
            printf(" Voce selecionou: 'Saque'\n");
            printf(" Aguarde um segundo...\n");
            delay(500);
            system("@cls||clear");
            saque();
            break;
        case 7:
            printf("\n");
            printf(" Voce selecionou: 'Extrato'\n");
            printf(" Aguarde um segundo...\n");
            delay(500);
            system("@cls||clear");
            extrato();
            break;
        case 8:
            printf("\n");
            printf(" Voce selecionou: 'Listar Informacoes'\n");
            printf(" Aguarde um segundo...\n");
            delay(500);
            system("@cls||clear");
            listar();
            break;
        case 9:
            printf("\n");
            printf(" Voce selecionou: 'Estatisticas'\n");
            printf(" Aguarde um segundo...\n");
            delay(500);
            printf("\n");
            system("@cls||clear");
            estatistica();
            break;
        default:
            printf("\n");
            printf(" Ei, parece que voce digitou uma opcao invalida.\n");
            printf("\n");
            escolher();
            break;
    }
}

// FIM DA FUNCAO ESCOLHA

// INICIO DA FUNCAO PRINCIPAL

main()
{
	int opcao, i, x;

    printf("\n");
    printf(" Para prosseguir, realize login.\n");
    printf("\n");
	printf(" Usuario: ");
	scanf("%s", &usuario);
	limpar();
	printf(" Senha: ");
	scanf("%s", &senha);
	limpar();
	printf("\n");
	system("@cls || clear");
	printf("\n");
	printf(" Autenticando");
	for (x=0; x<3; x++)
	{
		delay(600);
		printf(".");
	}
	printf("\n");
    if (strcmp(usuario, "admin") == 0 && strcmp(senha, "pass") == 0)
    {
	    printf(" Autenticado com sucesso!");
	    delay(800);
	    system("@cls||clear");
	    escolher();
    }
    else
    {
        printf("\n");
        printf(" Usuario e/ou senha errada\n");
        main();
    }
}

// FIM DA FUNCAO PRINCIPAL
