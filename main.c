/* Trabalho de Fundamentos de Algoritmos - Informática/UEM 2019
   Um programa feito em C para cadastro de Clientes.
   Funções: Cadastro, Remoção, Listagem e Remoção. 
   By: Filipe Moreno and Gabriel Galego 
   www.filipemoreno.me
*/

// INICIO DAS BIBLIOTECAS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// FIM DAS BIBLIOTECAS

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
    char uf[2];
    char cep[60];
    char numero[60];
    char bairro[200];
    char telefone[60];
    int dia[2];
    int mes[2];
    int ano[4];
    char rg[60];
    char cpf[60];
    char sexo[60];
    char estado_civil[60];
    char email[60];
    char nacionalidade[60];
    char celular[60];

};

// FIM DA ESTRUTURA DE CADASTRO

// INICIO DAS VARIAVEIS GLOBAIS

struct cadastro cliente[100];
int cod = 0;
char usuario[15];
char senha[12];

// FIM DAS VARIAVEIS GLOBAIS

// INICIO DA FUNÇÃO DE MENU

void menu()
{
    int opcao_menu;
    printf(" Realizar outra operacao?\n");
    printf(" 1 - Sim\n");
    printf(" 2 - Nao\n");
    printf(" Digite uma opcao: ");
    scanf("%i", &opcao_menu);
    limpar();
    switch (opcao_menu)
    {
        case 1:
			system("@cls||clear");
            return main();
            break;
        case 2:
            printf("\n");
            printf(" Finalizando o programa...\n");
			printf(" Ate mais!\n");
			break;
        default:
            printf(" Ei, digite uma opcao valida!");
            return menu();
            break;
    }
}

// FIM DA FUNÇÃO DE MENU

// INICIO DA FUNÇÃO DE CADASTRO

void cadastro()
{
    cod ++;
	printf(" ID do Cliente: #%i\n", cod);
	printf("\n");
	printf(" Informe o nome do Cliente: ");
	scanf("%s", &cliente[cod].nome);
	limpar();
	printf(" Informe o endereco do Cliente: ");
	scanf("%s", &cliente[cod].endereco);
	limpar();
    printf(" Informe o bairro do Cliente: ");
	scanf("%s", &cliente[cod].bairro);
	limpar();
    printf(" Informe o CEP do Cliente: ");
	scanf("%s", &cliente[cod].cep);
	limpar();
    printf(" Informe o numero da residencia do Cliente: ");
	scanf("%s", &cliente[cod].numero);
	limpar();
	printf(" Informe o municipio do Cliente: ");
	scanf("%s", &cliente[cod].municipio);
	limpar();
    printf(" Informe o UF do Cliente: ");
	scanf("%s", &cliente[cod].uf);
	limpar();
	printf(" Informe o telefone do Cliente: ");
	scanf("%s", &cliente[cod].telefone);
	limpar();
	printf(" Informe o celular do Cliente: ");
	scanf("%s", &cliente[cod].celular);
	limpar();
	printf(" Informe a data de nascimento do Cliente (DD/MM/AAAA): ");
	scanf("%i/%i/%i", &cliente[cod].dia,&cliente[cod].dia,&cliente[cod].dia);
	limpar();
	printf(" Informe o sexo do Cliente: ");
	scanf("%s", &cliente[cod].sexo);
	limpar();
	printf(" Informe a nacionalidade do Cliente: ");
	scanf("%s", &cliente[cod].nacionalidade);
	limpar();
	printf(" Informe o RG do Cliente: ");
	scanf("%s", &cliente[cod].rg);
	limpar();
	printf(" Informe o CPF do Cliente: ");
	scanf("%s", &cliente[cod].cpf);
	limpar();
	printf(" Informe o estado civil do Cliente: ");
	scanf("%s", &cliente[cod].estado_civil);
	limpar();
	printf(" Informe o email do Cliente: ");
	scanf("%s", &cliente[cod].email);
	limpar();
	sleep(1);
	printf("\n");
	printf(" Cadastro realizado com Sucesso!\n");
    sleep(1);
    printf("\n");
	menu();
}

// FIM DA FUNÇÃO DE CADASTRO

// INICIO DA FUNÇÃO DE VISUALIZAR

void visualizar()
{
    int codigo;

    printf("\n");
    printf(" Digite o #ID do cliente: ");
    scanf("%i", &codigo);
    limpar();
    if (codigo == 0 || codigo > cod)
    {
        printf(" ID: %i nao encontrado.\n", codigo);
        printf("\n");
        visualizar();
    }
    printf(" Nome: %s\n", cliente[codigo].nome);
    printf(" Endereco: %s\n", cliente[codigo].endereco);
    printf(" Municipio: %s\n", cliente[codigo].municipio);
    printf(" Bairro: %s\n", cliente[codigo].bairro);
    printf(" CEP: %s\n", cliente[codigo].cep);
    printf(" Num Residencia: %s\n", cliente[codigo].numero);
    printf(" UF: %s\n", cliente[codigo].uf);
	printf(" Telefone: %s\n", cliente[codigo].telefone);
	printf(" Celular: %s\n", cliente[codigo].celular);
	printf(" Nascimento: %s\n", cliente[codigo].nascimento);
	printf(" Sexo: %s\n", cliente[codigo].sexo);
	printf(" Nacionalidade: %s\n", cliente[codigo].nacionalidade);
	printf(" RG: %s\n", cliente[codigo].rg);
	printf(" CPF: %s\n", cliente[codigo].cpf);
	printf(" Estado Civil: %s\n", cliente[codigo].estado_civil);
	printf(" Email: %s\n", cliente[codigo].email);
	printf(" ID do Cliente: #%i\n", cod);
    sleep(1);
    printf("\n");
    menu();
}

// FIM DA FUNÇÃO DE VISUALIZAR

// INICIO DA FUNÇÃO DE EDITAR

void editar()
{
    int opcao, codigo;
    printf(" Digite o #ID do cliente: ");
    scanf("%i", &codigo);
    limpar();
    if (codigo == 0 || codigo > cod)
    {
        printf(" ID: %i nao encontrado.\n", codigo);
        printf("\n");
        editar();
    }
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
    printf("\n");
    printf(" 0 - Voltar ao menu principal\n");
    printf("\n");
    printf(" Digite uma opcao: ");
    scanf("%i", &opcao);
    limpar();

    switch (opcao)
    {
        case 1:
            printf(" Informe o novo 'Nome': ");
            scanf("%s", &cliente[codigo].nome);
            limpar();
            sleep(1);
            printf(" Alteracao realizada com sucesso!\n");
            printf("\n");
            menu();
            break;
        case 2:
            printf(" Informe o novo 'Endereco': ");
            scanf("%s", &cliente[codigo].endereco);
            limpar();
            sleep(1);
            printf(" Alteracao realizada com sucesso!\n");
            printf("\n");
            menu();
            break;
        case 3:
            printf(" Informe o novo 'Municipio': ");
            scanf("%s", &cliente[codigo].municipio);
            limpar();
            sleep(1);
            printf(" Alteracao realizada com sucesso!\n");
            printf("\n");
            menu();
            break;
        case 4:
            printf(" Informe o novo 'Bairro': ");
            scanf("%s", &cliente[codigo].bairro);
            limpar();
            sleep(1);
            printf(" Alteracao realizada com sucesso!\n");
            printf("\n");
            menu();
            break;
        case 5:
            printf(" Informe o novo 'CEP': ");
            scanf("%s", &cliente[codigo].cep);
            limpar();
            sleep(1);
            printf(" Alteracao realizada com sucesso!\n");
            printf("\n");
            menu();
            break;
        case 6:
            printf(" Informe o novo 'Numero da Residencia': ");
            scanf("%s", &cliente[codigo].numero);
            limpar();
            sleep(1);
            printf(" Alteracao realizada com sucesso!\n");
            printf("\n");
            menu();
            break;
        case 7:
            printf(" Informe a nova 'UF': ");
            scanf("%s", &cliente[codigo].uf);
            limpar();
            sleep(1);
            printf(" Alteracao realizada com sucesso!\n");
            printf("\n");
            menu();
            break;
        case 8:
            printf(" Informe o novo 'Telefone': ");
            scanf("%s", &cliente[codigo].telefone);
            limpar();
            sleep(1);
            printf(" Alteracao realizada com sucesso!\n");
            printf("\n");
            menu();
            break;
        case 9:
            printf(" Informe o novo 'Celular': ");
            scanf("%s", &cliente[codigo].celular);
            limpar();
            sleep(1);
            printf(" Alteracao realizada com sucesso!\n");
            printf("\n");
            menu();
            break;
        case 10:
            printf(" Informe a nova 'Data de Nascimento': ");
            scanf("%s", &cliente[codigo].nascimento);
            limpar();
            sleep(1);
            printf(" Alteracao realizada com sucesso!\n");
            printf("\n");
            menu();
            break;
        case 11:
            printf(" Informe o novo 'Sexo': ");
            scanf("%s", &cliente[codigo].sexo);
            limpar();
            sleep(1);
            printf(" Alteracao realizada com sucesso!\n");
            printf("\n");
            menu();
            break;
        case 12:
            printf(" Informe a nova 'Nacionalidade': ");
            scanf("%s", &cliente[codigo].nacionalidade);
            limpar();
            sleep(1);
            printf(" Alteracao realizada com sucesso!\n");
            printf("\n");
            menu();
            break;
        case 13:
            printf(" Informe o novo 'RG': ");
            scanf("%s", &cliente[codigo].rg);
            limpar();
            sleep(1);
            printf(" Alteracao realizada com sucesso!\n");
            printf("\n");
            menu();
            break;
        case 14:
            printf(" Informe o novo 'CPF': ");
            scanf("%s", &cliente[codigo].cpf);
            limpar();
            sleep(1);
            printf(" Alteracao realizada com sucesso!\n");
            printf("\n");
            menu();
            break;
        case 15:
            printf(" Informe o novo 'Estado Civil': ");
            scanf("%s", &cliente[codigo].estado_civil);
            limpar();
            sleep(1);
            printf(" Alteracao realizada com sucesso!\n");
            printf("\n");
            menu();
            break;
        case 16:
            printf(" Informe o novo 'Email': ");
            scanf("%s", &cliente[codigo].email);
            limpar();
            sleep(1);
            printf(" Alteracao realizada com sucesso!\n");
            printf("\n");
            menu();
            break;
        case 0:
            main();
            break;
        default:
            printf(" Ei, informe uma opcao valida!\n");
            printf("\n");
            editar();
            break;
    }
}

// FIM DA FUNÇÃO DE EDITAR

// INICIO DA FUNCAO PRINCIPAL

main()
{

	int opcao, i;
	struct cadastro cliente[100];
	
	printf(" Informe o usuario: ");
	scanf("%s", &usuario);
	limpar();
	printf(" Informe a senha: ");
	scanf("%s", &senha);
	limpar();
    if (strcmp(usuario, "admin") == 0 && strcmp(senha, "pass") == 0)
    {
	    printf("\n");
	    printf(" === Menu de Opcoes ===\n");
	    printf("\n");
	    printf(" 1 - Cadastrar um novo Cliente\n");
	    printf(" 2 - Alterar um Cliente\n");
	    printf(" 3 - Excluir um Cliente\n");
	    printf(" 4 - Visualizar um Cliente\n");
	    printf(" 5 - Estatisticas\n");
    	printf("\n");
	    printf(" 0 - Sair\n");
    	printf("\n");
	    printf(" Selecione uma opcao: ");
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
		    	printf(" Voce selecionou: 'Cadastrar Novo Cliente'...\n");
		    	printf(" Aguarde um segundo...\n");
		    	sleep(1);
		    	printf("\n");
		    	system("@cls||clear");
		    	cadastro();
		    	break;
	    	case 2:
                printf("\n");
                printf(" Voce selecionou: 'Alterar Cliente'...\n");
			    printf(" Aguarde um segundo...\n");
                sleep(1);
			    printf("\n");
			    system("@cls||clear");
			    editar();
			    break;
		    case 3:
			    printf("\n");
			    printf(" Voce selecionou: 'Excluir Cliente'...\n");
			    printf(" Aguarde um segundo...\n");
			    break;
            case 4:
			    printf("\n");
			    printf(" Voce selecionou: 'Visualizar Cliente'...\n");
			    printf(" Aguarde um segundo...\n");
                sleep(1);
		    	printf("\n");
		    	system("@cls||clear");
		    	visualizar();
		    	break;
	    	default:
             printf("\n");
		    	printf(" Ei, parece que voce digitou uma opcao invalida.\n");
		    	printf("\n");
		    	return main();
		    	break;
	    }
    }
    else
    {
        printf(" Senha errada...\n");
        main();
    }
}

// FIM DA FUNCAO PRINCIPAL
