#include<stdio.h>//biblioteca para entrada e saída
#include<ctype.h>
#include<math.h>
#include<stdlib.h>

#define TAM 2

char menu(char saida);

int main(){
	
	struct Cadastro{  //struct - agrupamento lógico de dados que pode ser heterogêneo, boa prática começar com letra maiúscula
		char nome[200], endereco[250], complemento[20], bairro[30], uf[4], cidade[30], email[30], receb_email, contato_resp[20], placa[10];
		char modelo[20], cor[20];
		int num_end, cep, ddd_tel_resid, tel_resid, ddd_cel, celular, cpf, cnpj, insc_est, 	insc_mun, cnae, dt_nasc, tel_com, data_doc, ano_carro;
	};
	
	struct Cadastro professor[TAM];
	
	// declaração das variaveis
	int num_cadastro=0;
	char saida, aux_saida;
	int i=0;
	
	printf("----------CADASTRO DO CARRO DOS PROFESSORES----------\n");
		
	do{

		printf("Informe o nome: ");
		scanf("%[^\n]s", &professor[i].nome);
		fflush(stdin);
		
		printf("\nInforme o endereco: ");
		scanf("%[^\n]s", &professor[i].endereco);
		fflush(stdin);
		
		printf("\nInforme o numero do endereco: ");
		scanf("%d", &professor[i].num_end);
		fflush(stdin);
		
		printf("\nInforme o complemento do endereco: ");
		scanf("%[^\n]s", &professor[i].complemento);
		fflush(stdin);
		
		printf("\nInforme o bairro: ");
		scanf("%[^\n]s", &professor[i].bairro);
		fflush(stdin);
		
		printf("\nInforme o CEP (somente numeros): ");
		scanf("%d", &professor[i].cep);
		fflush(stdin);
		
		printf("\nInforme a UF: ");
		scanf("%[^\n]s", &professor[i].uf);
		fflush(stdin);
		
		printf("\nInforme a cidade: ");
		scanf("%[^\n]s", &professor[i].cidade);
		fflush(stdin);
		
		printf("\nInforme o DDD do telefone residencial: ");
		scanf("%d", &professor[i].ddd_tel_resid);
		fflush(stdin);
		
		printf("\nInforme o telefone residencial: ");
		scanf("%d", &professor[i].ddd_tel_resid);
		fflush(stdin);
		
		printf("\nInforme o DDD do telefone celular: ");
		scanf("%d", &professor[i].ddd_cel);
		fflush(stdin);
		
		printf("\nInforme o telefone celular: ");
		scanf("%d", &professor[i].celular);
		fflush(stdin);
		
		printf("\nInforme o CPF (somente numeros): ");
		scanf("%d", &professor[i].cpf);
		fflush(stdin);
		
		printf("\nInforme o CNPJ: ");
		scanf("%d", &professor[i].cnpj);
		fflush(stdin);
		
		printf("\nInforme a inscricao estadual: ");
		scanf("%d", &professor[i].insc_est);
		fflush(stdin);
		
		printf("\nInforme a inscricao municipal: ");
		scanf("%d", &professor[i].insc_mun);
		fflush(stdin);
		
		printf("\nInforme o CNAE: ");
		scanf("%d", &professor[i].cnae);
		fflush(stdin);
		
		printf("\nInforme a data de nascimento (somente numeros sem espaco): ");
		scanf("%d", &professor[i].dt_nasc);
		fflush(stdin);
		
		printf("\nInforme o e-mail: ");
		scanf("%[^\n]s", &professor[i].email);
		fflush(stdin);
		
		printf("\nDeseja receber o boleto por e-mail? [S|N] ");
		scanf("%c", &professor[i].receb_email);
		fflush(stdin);
		
		printf("\nInforme o nome do responsável (caso PJ): ");
		scanf("%c", &professor[i].contato_resp);
		fflush(stdin);
		
		printf("\nInforme o telefone comercial: ");
		scanf("%d", &professor[i].tel_com);
		fflush(stdin);
		
		printf("\nInforme a data do preenchimento do formulario (somente numeros, sem espaco): ");
		scanf("%d", &professor[i].data_doc);
		fflush(stdin);
				
		printf("\n-------------------DADOS DO CARRO -------------------------\nInforme a placa do carro: ");
		scanf("%[^\n]s", &professor[i].placa);
		fflush(stdin);
		
		printf("\nInforme o modelo do carro: ");
		scanf("%[^\n]s", &professor[i].modelo);
		fflush(stdin);
		
		printf("\nInforme o ano do carro: ");
		scanf("%d", &professor[i].ano_carro);
		fflush(stdin);
		
		printf("\nInforme a cor do carro: ");
		scanf("%[^\n]s", &professor[i].cor);
		fflush(stdin);
		
		i++;
		
		printf("\n-------------------------------------------------------------\nDeseja cadastrar outro professor?[S|N] ");// Opção para fazer novo cadastro
		scanf("%c", &aux_saida);
		
		saida=menu(aux_saida);
					
		system("cls");

	}while(saida=='S');
	
	do{
		num_cadastro=0;
		
		printf("Informe o numero do credenciado que deseja visualizar os dados: ");
		scanf("%d", &num_cadastro);
		fflush(stdin);
		
		system("cls");
		
		printf("DADOS DO CREDENCIADO");
		
		printf("\nRazao Social e Nome Completo:\n%s", professor[num_cadastro].nome);
		printf("\nEndereco: \n%s", professor[num_cadastro].endereco);
		printf("\nNumero:\t\tComplemento:\t\tBairro:");
		printf("\n%d\t\t%s\t\t\t%s", professor[num_cadastro].num_end, professor[num_cadastro].complemento, professor[num_cadastro].bairro);	
		printf("\nCEP:\t\t\tEstado:\t\tCidade:");
		printf("\n%d\t\t\t%s\t%s", professor[num_cadastro].cep, professor[num_cadastro].uf, professor[num_cadastro].cidade);
		printf("\nDDD\tTelefone Residencial ou Comercial:\tDDD\tTelefone Celular:");
		printf("\n%d\t%d\t%d\t%d", professor[num_cadastro].ddd_tel_resid, professor[num_cadastro].tel_resid, professor[num_cadastro].ddd_cel, professor[num_cadastro].celular);
		printf("\nCPF:\t\t\t\tCNPJ: (Preenchimento exclusivo para PJ)");
		printf("\n%d\t\t\t\t%d", professor[num_cadastro].cpf, professor[num_cadastro].cnpj);
		printf("\nInsc. Estadual: (Preenchimento exclusivo para PJ)\tInsc. Municipal: (Preenchimento exclusivo para PJ)");
		printf("\n%d\t\t\t\t%d", professor[num_cadastro].insc_est, professor[num_cadastro].insc_mun);
		printf("\nCNAE: (Preenchimento exclusivo para PJ)\tData de Nasc.:\tDeseja receber os próximos boletos por e-mail?");
		printf("\n%d\t\t\t%d\t\t%c", professor[num_cadastro].cnae, professor[num_cadastro].dt_nasc, professor[num_cadastro].receb_email);
		printf("\nE-mail: \n%s", professor[num_cadastro].email);
		printf("\nContato do Responsavel (em caso de Pessoa Juridica)\tTelefone Comercial:");
		printf("\n%s\t\t\t%d", professor[num_cadastro].contato_resp, professor[num_cadastro].tel_com);
		printf("\nData:");
		printf("\n%d\t\t\t______________________", professor[num_cadastro].data_doc);
		printf("\n\t\t\t\tAssinatura do Responsavel");
		printf("\n\nDADOS DOS VEICULOS");
		printf("\nPlaca:\t\tModelo:\t\tAno:\t\tCor");
		printf("\n%s\t%s\t%d\t\t%s",  professor[num_cadastro].placa, professor[num_cadastro].modelo, professor[num_cadastro].ano_carro, professor[num_cadastro].cor);
				
		printf("\n-------------------------------------------------------------\nDeseja visualizar outro cadastro?[S|N] ");// Opção para visualizar novo cadastro
		scanf("%c", &aux_saida);
		
		saida=menu(aux_saida);
					
		system("cls");

		
	}while(saida=='S');
	
	return 0;
}
	

char menu(char saida){
	
	do{
		fflush(stdin);
		
		saida = toupper(saida);
		
			if(saida != 'S' && saida != 'N'){
				printf("Opcao Invalida\n");
				printf("\nDeseja fazer nova conta?[S|N] ");// Opção para fazer nova conta
				scanf("%c", &saida);
			}
	}while(saida != 'S' && saida != 'N');
	
	return saida;
}

