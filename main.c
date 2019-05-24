#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void limpar(void)
{
    int c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}

int cod;
cod = 0;

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
    char nascimento[60];
    char rg[60];
    char cpf[60];
    char sexo[60];
    char estado_civil[60];
    char email[60];
    char nacionalidade[60];
    char celular[60];

};

struct cadastro cliente[100];

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

void cadastro()
{
    cod ++;
	printf(" ID do Cliente: #%i\n", cod);
	printf("\n");
	printf(" Digite o nome do Cliente: ");
	scanf("%s", &cliente[cod].nome);
	limpar();
	printf(" Digite o endereco do Cliente: ");
	scanf("%s", &cliente[cod].endereco);
	limpar();
    printf(" Digite o municipio do Cliente: ");
	scanf("%s", &cliente[cod].municipio);
	limpar();
    printf(" Digite o bairro do Cliente: ");
	scanf("%s", &cliente[cod].bairro);
	limpar();
    printf(" Digite o CEP do Cliente: ");
	scanf("%s", &cliente[cod].cep);
	limpar();
    printf(" Digite o numero da residencia do Cliente: ");
	scanf("%s", &cliente[cod].numero);
	limpar();
    printf(" Digite o UF do Cliente: ");
	scanf("%s", &cliente[cod].uf);
	limpar();
	printf(" Digite o telefone do Cliente: ");
	scanf("%s", &cliente[cod].telefone);
	limpar();
	printf(" Digite o celular do Cliente: ");
	scanf("%s", &cliente[cod].celular);
	limpar();
	printf(" Digite a data de nascimento do Cliente (DD-MM-AAAA): ");
	scanf("%s", &cliente[cod].nascimento);
	limpar();
	printf(" Digite o sexo do Cliente: ");
	scanf("%s", &cliente[cod].sexo);
	limpar();
	printf(" Digite a nacionalidade do Cliente: ");
	scanf("%s", &cliente[cod].nacionalidade);
	limpar();
	printf(" Digite o RG do Cliente: ");
	scanf("%s", &cliente[cod].rg);
	limpar();
	printf(" Digite o CPF do Cliente: ");
	scanf("%s", &cliente[cod].cpf);
	limpar();
	printf(" Digite o estado civil do Cliente: ");
	scanf("%s", &cliente[cod].estado_civil);
	limpar();
	printf(" Digite o email do Cliente: ");
	scanf("%s", &cliente[cod].email);
	limpar();
	sleep(1);
	printf("\n");
	printf(" Cadastro concluido!\n");
    sleep(1);
    printf("\n");
	menu();
}

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
            printf(" Alteracao feita com sucesso!\n");
            printf("\n");
            menu();
            break;
        case 2:
            printf(" Informe o novo 'Endereco': ");
            scanf("%s", &cliente[codigo].endereco);
            limpar();
            sleep(1);
            printf(" Alteracao feita com sucesso!\n");
            printf("\n");
            menu();
            break;
        case 3:
            printf(" Informe o novo 'Municipio': ");
            scanf("%s", &cliente[codigo].municipio);
            limpar();
            sleep(1);
            printf(" Alteracao feita com sucesso!\n");
            printf("\n");
            menu();
            break;
        case 4:
            printf(" Informe o novo 'Bairro': ");
            scanf("%s", &cliente[codigo].bairro);
            limpar();
            sleep(1);
            printf(" Alteracao feita com sucesso!\n");
            printf("\n");
            menu();
            break;
        case 5:
            printf(" Informe o novo 'CEP': ");
            scanf("%s", &cliente[codigo].cep);
            limpar();
            sleep(1);
            printf(" Alteracao feita com sucesso!\n");
            printf("\n");
            menu();
            break;
        case 6:
            printf(" Informe o novo 'Numero da Residencia': ");
            scanf("%s", &cliente[codigo].numero);
            limpar();
            sleep(1);
            printf(" Alteracao feita com sucesso!\n");
            printf("\n");
            menu();
            break;
        case 7:
            printf(" Informe a nova 'UF': ");
            scanf("%s", &cliente[codigo].uf);
            limpar();
            sleep(1);
            printf(" Alteracao feita com sucesso!\n");
            printf("\n");
            menu();
            break;
        case 8:
            printf(" Informe o novo 'Telefone': ");
            scanf("%s", &cliente[codigo].telefone);
            limpar();
            sleep(1);
            printf(" Alteracao feita com sucesso!\n");
            printf("\n");
            menu();
            break;
        case 9:
            printf(" Informe o novo 'Celular': ");
            scanf("%s", &cliente[codigo].celular);
            limpar();
            sleep(1);
            printf(" Alteracao feita com sucesso!\n");
            printf("\n");
            menu();
            break;
        case 10:
            printf(" Informe a nova 'Data de Nascimento': ");
            scanf("%s", &cliente[codigo].nascimento);
            limpar();
            sleep(1);
            printf(" Alteracao feita com sucesso!\n");
            printf("\n");
            menu();
            break;
        case 11:
            printf(" Informe o novo 'Sexo': ");
            scanf("%s", &cliente[codigo].sexo);
            limpar();
            sleep(1);
            printf(" Alteracao feita com sucesso!\n");
            printf("\n");
            menu();
            break;
        case 12:
            printf(" Informe a nova 'Nacionalidade': ");
            scanf("%s", &cliente[codigo].nacionalidade);
            limpar();
            sleep(1);
            printf(" Alteracao feita com sucesso!\n");
            printf("\n");
            menu();
            break;
        case 13:
            printf(" Informe o novo 'RG': ");
            scanf("%s", &cliente[codigo].rg);
            limpar();
            sleep(1);
            printf(" Alteracao feita com sucesso!\n");
            printf("\n");
            menu();
            break;
        case 14:
            printf(" Informe o novo 'CPF': ");
            scanf("%s", &cliente[codigo].cpf);
            limpar();
            sleep(1);
            printf(" Alteracao feita com sucesso!\n");
            printf("\n");
            menu();
            break;
        case 15:
            printf(" Informe o novo 'Estado Civil': ");
            scanf("%s", &cliente[codigo].estado_civil);
            limpar();
            sleep(1);
            printf(" Alteracao feita com sucesso!\n");
            printf("\n");
            menu();
            break;
        case 16:
            printf(" Informe o novo 'Email': ");
            scanf("%s", &cliente[codigo].email);
            limpar();
            sleep(1);
            printf(" Alteracao feita com sucesso!\n");
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

main()
{

	int opcao;
	struct cadastro cliente[100];

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

