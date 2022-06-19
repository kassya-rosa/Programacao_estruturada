#include<stdio.h> //biblioteca para printf e scanf 
#include<stdlib.h> //biblioteca para comandos Windows
#include<string.h> //biblioteca para string: http://linguagemc.com.br/a-biblioteca-string-h/
#include<ctype.h> //biblioteca para o uso do toupper e tolower: http://linguagemc.com.br/ctype-h-toupper-tolower-isalpha-isdigit-em-c/
#include<locale.h> // biblioteca para utilizar acentuação do português: http://linguagemc.com.br/localizacao-de-programas-com-locale-h/

#define MAX_CIRCUITOS 30
#define MAX_PILOTO 100

void le_valida_nome_piloto();
void le_valida_nome_circuito();
void escolher_pais();
void valida_id_piloto();
void saida();
void valida_idade_piloto();
void sexo_piloto();
void le_valida_equipe();
void le_valida_data();
void le_valida_tempo();
void valida_tam_circuito();
void escolhe_piloto_volta();
void escolhe_circuito_volta();

int main(void){
	setlocale(LC_ALL,"Portuguese");
	
	struct Piloto{  //struct - agrupamento lógico de dados que pode ser heterogêneo, boa prática começar com letra maiúscula
		char nome[MAX_PILOTO], sexo, pais[20], equipe[20];
		int idade, id_piloto;		
	};
	
	struct Circuito{
		char nome[MAX_CIRCUITOS], pais[20];
		int id_circuito;
		float tamanho;
		struct Piloto piloto;
	};
	
	struct Volta{
		int dia, mes, ano, min, seg, mil, anomesdia, tempo;
		struct Piloto piloto;
		struct Circuito circuito;
	};
	struct Circuito circuito[30];
	struct Piloto piloto[400];
	struct Volta volta[400];
	
	// Declaração das variáveis para os menus
	
	char vetor_pilotos[400], vetor_circuitos[30], aux_nome_piloto[MAX_PILOTO], aux_pais_piloto[20], aux_equipe[20], aux_sexo;
	char aux_nome_circuito[MAX_CIRCUITOS], aux_pais_circuito[20], menu_saida, menu_saida_rel, menu_saida_cad;
	int aux_id_pilotos, aux_id_piloto2, aux_id_circuito, aux_idade, menu_opcao, menu_opcao_cad, id_cadastro=0, i=0, id_circ=0,aux_busca_volta;
	int j=0, id_volta=0, aux_dia, aux_mes, aux_ano,aux_min, aux_seg, aux_mil, aux_piloto_volta, aux_circuito_volta, menu_opcao_rel, localizado;
	int menor_volta, id_melhor_volta, aux_dup_volta, dupla_volta, aux_tempo, tam_busca_circ, aux_busca, aux_busca_piloto,piloto_localizado;
	int sem_cad=0;
	float aux_tam_circuito;
	
		// Vetor para identificar os circuitos cadastrados
	
	for(aux_id_circuito=0;aux_id_circuito<30;aux_id_circuito++){ // V de vazio
			vetor_circuitos[aux_id_circuito] = 'V';
		}
	
	// Vetor para identificar os pilotos cadastrados
	
	for(aux_id_pilotos=100;aux_id_pilotos<501;aux_id_pilotos++){ // V de vazio
			vetor_pilotos[aux_id_pilotos] = 'V';
		}
	
	// Início do programa
do{

	printf("*************************************************\n");
	printf("***************** Sistema F1 ********************\n");
	printf("*************************************************\n\n\n");
	printf("    MENU DE OPÇÕES\n\n\n");
    printf("1 - CADASTRAMENTOS (piloto, circuito e volta)\n\n");
    printf("2 - RELATÓRIOS\n\n");
    printf("3 - ENCERRAR O PROGRAMA\n\n");
    printf("    INFORME A OPÇÃO DESEJADA: ");
    scanf("%d", &menu_opcao);
   
    system("cls");
	
	switch(menu_opcao){
    	case 1:
			do{
				printf("*************************************************\n");
				printf("********** Sistema F1 - Cadastramentos **********\n");	
				printf("*************************************************\n\n\n");
				printf("    MENU DE OPÇÕES\n\n\n");
			    printf("1 - CADASTRAMENTO DE PILOTOS\n\n");
			    printf("2 - CADASTRAMENTO DE CIRCUITOS\n\n");
			    printf("3 - CADASTRAMENTO DE VOLTAS\n\n");
				printf("4 - VOLTAR AO MENU PRINCIPAL\n\n");
			    printf("    INFORME A OPÇÃO DESEJADA: ");
			    scanf("%d", &menu_opcao_cad);
			   
			    system("cls");	
			    
			    switch(menu_opcao_cad){
			    	case 1:
			    		printf("*************************************************\n");
						printf("************ Cadastro de Pilotos ****************\n");
						printf("*************************************************\n\n\n");
						
						//Inclusçao do nome do piloto
						le_valida_nome_piloto(&aux_nome_piloto);
						
						strcpy(piloto[id_cadastro].nome, aux_nome_piloto);
						
						//Inclusão da id do piloto
						do{
							valida_id_piloto(&aux_id_piloto2);
							piloto[id_cadastro].id_piloto = aux_id_piloto2;
												
							if(vetor_pilotos[piloto[id_cadastro].id_piloto] != 'V'){
								printf("\nIdentificação utilizada em outro piloto. Favor informar nova identificação");
							}
							
						}while(vetor_pilotos[piloto[id_cadastro].id_piloto] != 'V');
						
						// Altera a situação do vetor de pilotos para cadastrado (C)
						
						vetor_pilotos[piloto[id_cadastro].id_piloto] = 'C';
						
						//Inclusão do país do piloto
						escolher_pais(&aux_pais_piloto);
						
						strcpy(piloto[id_cadastro].pais, aux_pais_piloto);
						
						//Inclusão idade do piloto
						
						valida_idade_piloto(&aux_idade);
						piloto[id_cadastro].idade = aux_idade;
						
						//Inclusão sexo do piloto
						
						sexo_piloto(&aux_sexo);
						piloto[id_cadastro].sexo = aux_sexo;
						
						//Inclusão equipe do piloto
						
						le_valida_equipe(&aux_equipe);
						strcpy(piloto[id_cadastro].equipe, aux_equipe);
			    		
						system("cls");
						
						printf("Piloto cadastrado com sucesso!");
						id_cadastro++;
											
						break;
					case 2:
						printf("*************************************************\n");
						printf("************ Cadastro de Circuitos **************\n");
						printf("*************************************************\n\n\n");
						
						//Inclusão do nome do circuito
						le_valida_nome_circuito(&aux_nome_circuito);
						
						strcpy(circuito[id_circ].nome, aux_nome_circuito);
						
						//Inclusão da id do circuito
						
						circuito[id_circ].id_circuito = id_circ;
												
						// Altera a situação do vetor de circuitos para cadastrado (C)
										
						vetor_circuitos[circuito[id_circ].id_circuito]='C';
						
						//Inclusão do país do circuito
						escolher_pais(&aux_pais_circuito);
						
						strcpy(circuito[id_circ].pais, aux_pais_circuito);
						
						//Inclusão tamanho do circuito
						
						valida_tam_circuito(&aux_tam_circuito);
						
						circuito[id_circ].tamanho = aux_tam_circuito;
						
						printf("\n\nCircuito cadastrado com sucesso!");
						printf("\nId Circuito: %d", id_circ);
						id_circ++;									
						break;
					case 3: 
					
						printf("*************************************************\n");
						printf("************** Cadastro de Voltas ***************\n");
						printf("*************************************************\n\n\n");
						
						do{
							if(id_circ == 0 || id_cadastro == 0){
								printf("Para cadastrar voltas, deve haver piloto e circuito cadastrado\n\n");
								system("pause");
								sem_cad=1;
								break;
							}
							// Inclusão da data da volta
							le_valida_data(&aux_dia, &aux_mes, &aux_ano);
							volta[id_volta].dia = aux_dia;
							volta[id_volta].mes = aux_mes;
							volta[id_volta].ano = aux_ano;
							
							// Conta auxiliar para identicar a data
							volta[id_volta].anomesdia = (volta[id_volta].ano * 10000) + (volta[id_volta].mes * 100) + volta[id_volta].dia;
							
							// Inclusão da melhor volta
							le_valida_tempo(&aux_min, &aux_seg, &aux_mil);
							volta[id_volta].min = aux_min;
							volta[id_volta].seg = aux_seg;
							volta[id_volta].mil = aux_mil;
							
							// Conta auxiliar para descobrir a melhor volta
							volta[id_volta].tempo = (volta[id_volta].min * 100000) + (volta[id_volta].seg * 1000) + volta[id_volta].mil;
							
							// Identificando o piloto que fez a volta
							printf("Escolha o piloto que fez a volta: ");
							for(i=0;i<id_cadastro;i++){
								printf("\n%d - %-*s", i+1, 20, piloto[i].nome);
							}
							
							escolhe_piloto_volta(id_cadastro, &aux_piloto_volta);
														
							volta[id_volta].piloto.id_piloto = piloto[aux_piloto_volta-1].id_piloto;
							strcpy(volta[id_volta].piloto.equipe, piloto[aux_piloto_volta-1].equipe);
							strcpy(volta[id_volta].piloto.nome, piloto[aux_piloto_volta-1].nome);
													
							// Identificando o circuito que teve a melhor volta
							
							printf("Escolha o circuito da volta: ");
							for(i=0;i<id_circ;i++){
								printf("\n%d - %-*s", i+1, 20, circuito[i].nome);
							}
							
							escolhe_circuito_volta(id_circ, &aux_circuito_volta);
							
							volta[id_volta].circuito.id_circuito = circuito[aux_circuito_volta-1].id_circuito;
							strcpy(volta[id_volta].circuito.nome, circuito[aux_circuito_volta-1].nome);
							
							// Verifica se já há outra volta cadastrada para o mesmo piloto, circuito e dia
							aux_dup_volta = id_volta;
							dupla_volta=0;
							for(i=0;i<id_volta;i++){
								if(i == id_volta){
									break;
								}else{
									if(volta[aux_dup_volta].piloto.id_piloto == volta[i].piloto.id_piloto){
										if(volta[aux_dup_volta].circuito.id_circuito == volta[i].circuito.id_circuito){
											if(volta[aux_dup_volta].anomesdia == volta[i].anomesdia){
												printf("\nVolta já cadastrada para esse piloto neste circuito e data.\n");
												dupla_volta++;
											}
										}
									}
								}
							}
						}while(dupla_volta != 0);
						
						if(sem_cad !=1){
							printf("\nVolta rápida cadastrada com sucesso!");
							id_volta++;
							break;
						} else{
							break;
						}
						
					case 4: ;break;
					default: printf("\nOpção Inválida\n");
				};
								
				if(menu_opcao_cad!=4){
					saida(&menu_saida_cad);
				} else{
					break;
				}
											
				system("cls");
			}while(menu_saida_cad == 'S');
			
			break;
		case 2: 
			do{
				printf("*************************************************\n");
				printf("************ Sistema F1 - Relatórios ************\n");	
				printf("*************************************************\n\n\n");
				printf("    MENU DE OPÇÕES\n\n\n");
			    printf("1 - TODOS OS DADOS CADASTRADOS\n\n");
			    printf("2 - PESQUISAR PILOTOS\n\n");
			    printf("3 - DADOS DOS CIRCUITOS\n\n");
				printf("4 - PESQUISA POR MELHOR TEMPO\n\n");
				printf("5 - VOLTAR AO MENU PRINCIPAL\n\n");
			    printf("    INFORME A OPÇÃO DESEJADA: ");
			    scanf("%d", &menu_opcao_rel);
				
				system("cls");
				
				switch(menu_opcao_rel){
					case 1: 
						// Visualização de todas as informações sobre os pilotos cadastrados
						printf("Dados dos pilotos: \n");
						for(i=0;i<id_cadastro;i++){
							printf("\n\nNome: %-*s\t", 15, piloto[i].nome);
							printf("Identificação: %-*d", 10, piloto[i].id_piloto);
							printf("\nIdade: %-*d\t", 15, piloto[i].idade);
							printf("Sexo: %-*c", 10, piloto[i].sexo);
							printf("\nEquipe: %-*s\t", 15, piloto[i].equipe);
							printf("País de origem: %-*s", 10, piloto[i].pais);
							printf("\n--------------------------------------------\n");
						}
						
						//Visualização das informações dos circuitos cadastrados
						printf("\n\nDados dos circuitos: \n");
						for(i=0;i<id_circ;i++){
							menor_volta=9999999;
							printf("\nNome: %-*s\t", 15, circuito[i].nome);
							printf("Identificação: %-*d", 10, circuito[i].id_circuito);
							printf("\nPaís: %-*s\t", 15, circuito[i].pais);
							printf("Tamanho[km]: %-*.3f", 10, circuito[i].tamanho);
							for(j=0;j<id_volta;j++){
								if(volta[j].circuito.id_circuito==circuito[i].id_circuito){
									if(volta[j].tempo<menor_volta){
										menor_volta = volta[j].tempo;
										id_melhor_volta = j;
									}
								}
							}
							if(menor_volta==9999999){
								printf("\nMelhor volta: Não há volta cadastrada\nPiloto: --------------------");
								printf("\n--------------------------------------------\n");
							}else{
								printf("\nMelhor volta: %d.%d.%d", volta[id_melhor_volta].min, volta[id_melhor_volta].seg, volta[id_melhor_volta].mil);
								printf("\nPiloto: %s", volta[id_melhor_volta].piloto.nome);
								printf("\n--------------------------------------------\n");
							}
						}
						
						// Visualização das informações das voltas cadastradas
						printf("\n\nDados das voltas cadastradas: \n");
						for(i=0;i<id_volta;i++){
							printf("\n\nId Piloto: %-*d\t", 10, volta[i].piloto.id_piloto);
							printf("Id Circuito: %-*d", 10, volta[i].circuito.id_circuito);
							printf("\nEquipe: %-*s\t", 10, volta[i].piloto.equipe);
							printf("Data da volta: %d/%d/%d", volta[i].dia, volta[i].mes, volta[i].ano);
							printf("\nVolta: %d.%d.%d", volta[i].min, volta[i].seg, volta[i].mil);
							printf("\n--------------------------------------------\n");
						}
						
						break;
					case 2: 
						aux_busca_piloto=0;
						
						le_valida_nome_piloto(&aux_nome_piloto);
						
						for(i=0;i<id_cadastro;i++){
							piloto_localizado = strcmp(aux_nome_piloto, piloto[i].nome);
							if(piloto_localizado == 0){
								printf("\nId piloto: %d", piloto[i].id_piloto);
								printf("\nIdade: %d", piloto[i].idade);
								printf("\nEquipe: %s", piloto[i].equipe);
								printf("\nSexo: %c", piloto[i].sexo);
								aux_busca_piloto++;
							}
						}
						
						if(aux_busca_piloto == 0){
							printf("\nO piloto %s não está cadastrado", aux_nome_piloto);
						}
						
						break;
					case 3: 
						aux_busca=0;
						
						le_valida_nome_circuito(&aux_nome_circuito);
												
						printf("\nPilotos que deram voltas no circuito: %s\n", aux_nome_circuito);
						for(j = 0; j < id_volta; j++){
							localizado = strcmp(aux_nome_circuito, volta[j].circuito.nome);
							if(localizado == 0){
								printf("\n%*s | %*d.%d.%d |  %*d/%d/%d", 20, volta[j].piloto.nome, 10, volta[j].min, volta[j].seg, volta[j].mil, 10, volta[j].dia, volta[j].mes, volta[j].ano);
							aux_busca++;
							}
						}
						
						if(aux_busca == 0){
							printf("\n\nNão há voltas cadastradas no circuito %s", aux_nome_circuito);
						}
												
						break;
					case 4: 
						aux_busca_volta=0;
						printf("Informe o minuto, segundo e milésimo que deseja pesquisar: \n");
						
						// Guarda os dados digitados
						le_valida_tempo(&aux_min, &aux_seg, &aux_mil);
													
						// Conta auxiliar para descobrir a melhor volta
						aux_tempo = (aux_min * 100000) + (aux_seg * 1000) + aux_mil;
						
						system("cls");
						
						printf("Abaixo os pilotos que fizeram tempo melhor do que: %d.%d.%d\n", aux_min, aux_seg, aux_mil);
						
						for(i=0;i<id_volta;i++){
							if(volta[i].tempo<aux_tempo){
								printf("\nPiloto: %s", volta[i].piloto.nome);
								printf("\nCircuito: %s", volta[i].circuito.nome);
								printf("\nData: %d/%d/%d", volta[i].dia, volta[i].mes, volta[i].ano);
								printf("\nTempo: %d.%d.%d", volta[i].min, volta[i].seg, volta[i].mil);
								printf("\n--------------------------------------------------\n");
								aux_busca_volta++;
							}
						}
						
						if(aux_busca_volta == 0){
							printf("\nNão há volta melhor que o tempo informado.");
						}
						
						break;
					case 5: ;break;
					default: printf("\nOpção Inválida\n"); 
					
					
				};
				
				if(menu_opcao_rel!=5){
						saida(&menu_saida_rel);
					} else{
						break;
					}
												
					system("cls");
				
			}while(menu_saida_rel == 'S');
			
			break;
		case 3: ;break;
		default: printf("\nOpção Inválida\n");
	};
	
	if(menu_opcao==1|| menu_opcao==2){
		saida(&menu_saida);
	} else{
		break;
	}
		
	system("cls");
	
}while(menu_saida == 'S');

return 0;	
	
}

void escolher_pais(char *pnome_pais){
	
	const char* paises[] = {"Reino Unido", "Alemanha", "França", "México", "Espanha", "Dinamarca", "Finlândia", "Holanda", "Canadá", "Japão", "China", "Tailândia", "Bélgica", "Brasil", "Mônaco", "Estados Unidos", "Portugal", "Itália", "Singapura", "Austrália", "Azerbaijão", "Arábia Saudita", "Qatar", "Bahrein", "Emirados Árabes", "Rússia", "Argentina", "Áustria", "Hungria", "Coreia do Sul"};
	char nome_pais[20];
	int opcao_pais, tam_nome, i=0;
	
	printf("\nEscolha o país: \n");
	
	for(i=0; i<30; i++){
		printf("%d - %-*s\t", i+1, 15, paises[i]);
		if(i>0 && i%4==0){
			printf("\n");
		}
	}
	printf("\nInforme a opção desejada: ");
	scanf("%d", &opcao_pais);
	fflush(stdin);
	switch(opcao_pais){
		case 1:
			strcpy(nome_pais, paises[0]);
			tam_nome = 	strlen(nome_pais);
	
			for(i=0; i<tam_nome;i++){
				*pnome_pais = nome_pais[i];
				++pnome_pais;
			}	
			
			*pnome_pais = '\0';
			
			break;
		case 2:
			strcpy(nome_pais, paises[1]);
			tam_nome = 	strlen(nome_pais);
	
			for(i=0; i<tam_nome;i++){
				*pnome_pais = nome_pais[i];
				++pnome_pais;
			}	
			
			*pnome_pais = '\0';
			
			break;
		case 3:
			strcpy(nome_pais, paises[2]);
			tam_nome = 	strlen(nome_pais);
	
			for(i=0; i<tam_nome;i++){
				*pnome_pais = nome_pais[i];
				++pnome_pais;
			}	
			
			*pnome_pais = '\0';
			
			break;
		case 4:
			strcpy(nome_pais, paises[3]);
			tam_nome = 	strlen(nome_pais);
	
			for(i=0; i<tam_nome;i++){
				*pnome_pais = nome_pais[i];
				++pnome_pais;
			}	
			
			*pnome_pais = '\0';
			
			break;
		case 5:
			strcpy(nome_pais, paises[4]);
			tam_nome = 	strlen(nome_pais);
	
			for(i=0; i<tam_nome;i++){
				*pnome_pais = nome_pais[i];
				++pnome_pais;
			}	
			
			*pnome_pais = '\0';
			
			break;
		case 6:
			strcpy(nome_pais, paises[5]);
			tam_nome = 	strlen(nome_pais);
	
			for(i=0; i<tam_nome;i++){
				*pnome_pais = nome_pais[i];
				++pnome_pais;
			}	
			
			*pnome_pais = '\0';
			
			break;
		case 7:
			strcpy(nome_pais, paises[6]);
			tam_nome = 	strlen(nome_pais);
	
			for(i=0; i<tam_nome;i++){
				*pnome_pais = nome_pais[i];
				++pnome_pais;
			}	
			
			*pnome_pais = '\0';
			
			break;
		case 8:
			strcpy(nome_pais, paises[7]);
			tam_nome = 	strlen(nome_pais);
	
			for(i=0; i<tam_nome;i++){
				*pnome_pais = nome_pais[i];
				++pnome_pais;
			}	
			
			*pnome_pais = '\0';
			
			break;
		case 9:
			strcpy(nome_pais, paises[8]);
			tam_nome = 	strlen(nome_pais);
	
			for(i=0; i<tam_nome;i++){
				*pnome_pais = nome_pais[i];
				++pnome_pais;
			}	
			
			*pnome_pais = '\0';
			
			break;
		case 10:
			strcpy(nome_pais, paises[9]);
			tam_nome = 	strlen(nome_pais);
	
			for(i=0; i<tam_nome;i++){
				*pnome_pais = nome_pais[i];
				++pnome_pais;
			}	
			
			*pnome_pais = '\0';
		
			break;
		case 11:
			strcpy(nome_pais, paises[10]);
			tam_nome = 	strlen(nome_pais);
	
			for(i=0; i<tam_nome;i++){
				*pnome_pais = nome_pais[i];
				++pnome_pais;
			}	
			
			*pnome_pais = '\0';
			
			break;
		case 12:
			strcpy(nome_pais, paises[11]);
			tam_nome = 	strlen(nome_pais);
	
			for(i=0; i<tam_nome;i++){
				*pnome_pais = nome_pais[i];
				++pnome_pais;
			}	
			
			*pnome_pais = '\0';
			
			break;
		case 13:
			strcpy(nome_pais, paises[12]);
			tam_nome = 	strlen(nome_pais);
	
			for(i=0; i<tam_nome;i++){
				*pnome_pais = nome_pais[i];
				++pnome_pais;
			}	
			
			*pnome_pais = '\0';
			
			break;
		case 14:
			strcpy(nome_pais, paises[13]);
			tam_nome = 	strlen(nome_pais);
	
			for(i=0; i<tam_nome;i++){
				*pnome_pais = nome_pais[i];
				++pnome_pais;
			}	
			
			*pnome_pais = '\0';
			
			break;
		case 15:
			strcpy(nome_pais, paises[14]);
			tam_nome = 	strlen(nome_pais);
	
			for(i=0; i<tam_nome;i++){
				*pnome_pais = nome_pais[i];
				++pnome_pais;
			}	
			
			*pnome_pais = '\0';
			
			break;
		case 16:
			strcpy(nome_pais, paises[15]);
			tam_nome = 	strlen(nome_pais);
	
			for(i=0; i<tam_nome;i++){
				*pnome_pais = nome_pais[i];
				++pnome_pais;
			}	
			
			*pnome_pais = '\0';
			
			break;
		case 17:
			strcpy(nome_pais, paises[16]);
			tam_nome = 	strlen(nome_pais);
	
			for(i=0; i<tam_nome;i++){
				*pnome_pais = nome_pais[i];
				++pnome_pais;
			}	
			
			*pnome_pais = '\0';
			
			break;
		case 18:
			strcpy(nome_pais, paises[17]);
			tam_nome = 	strlen(nome_pais);
	
			for(i=0; i<tam_nome;i++){
				*pnome_pais = nome_pais[i];
				++pnome_pais;
			}	
			
			*pnome_pais = '\0';
			
			break;
		case 19:
			strcpy(nome_pais, paises[18]);
			tam_nome = 	strlen(nome_pais);
	
			for(i=0; i<tam_nome;i++){
				*pnome_pais = nome_pais[i];
				++pnome_pais;
			}	
			
			*pnome_pais = '\0';
			
			break;
		case 20:
			strcpy(nome_pais, paises[19]);
			tam_nome = 	strlen(nome_pais);
	
			for(i=0; i<tam_nome;i++){
				*pnome_pais = nome_pais[i];
				++pnome_pais;
			}	
			
			*pnome_pais = '\0';
			
			break;
		case 21:
			strcpy(nome_pais, paises[20]);
			tam_nome = 	strlen(nome_pais);
	
			for(i=0; i<tam_nome;i++){
				*pnome_pais = nome_pais[i];
				++pnome_pais;
			}	
			
			*pnome_pais = '\0';
			
			break;
		case 22:
			strcpy(nome_pais, paises[21]);
			tam_nome = 	strlen(nome_pais);
	
			for(i=0; i<tam_nome;i++){
				*pnome_pais = nome_pais[i];
				++pnome_pais;
			}	
			
			*pnome_pais = '\0';
			
			break;
		case 23:
			strcpy(nome_pais, paises[22]);
			tam_nome = 	strlen(nome_pais);
	
			for(i=0; i<tam_nome;i++){
				*pnome_pais = nome_pais[i];
				++pnome_pais;
			}	
			
			*pnome_pais = '\0';
			
			break;
		case 24:
			strcpy(nome_pais, paises[23]);
			tam_nome = 	strlen(nome_pais);
	
			for(i=0; i<tam_nome;i++){
				*pnome_pais = nome_pais[i];
				++pnome_pais;
			}	
			
			*pnome_pais = '\0';
			
			break;
		case 25:
			strcpy(nome_pais, paises[24]);
			tam_nome = 	strlen(nome_pais);
	
			for(i=0; i<tam_nome;i++){
				*pnome_pais = nome_pais[i];
				++pnome_pais;
			}	
			
			*pnome_pais = '\0';
			
			break;
		case 26:
			strcpy(nome_pais, paises[25]);
			tam_nome = 	strlen(nome_pais);
	
			for(i=0; i<tam_nome;i++){
				*pnome_pais = nome_pais[i];
				++pnome_pais;
			}	
			
			*pnome_pais = '\0';
			
			break;
		case 27:
			strcpy(nome_pais, paises[26]);
			tam_nome = 	strlen(nome_pais);
	
			for(i=0; i<tam_nome;i++){
				*pnome_pais = nome_pais[i];
				++pnome_pais;
			}	
			
			*pnome_pais = '\0';
			
			break;
		case 28:
			strcpy(nome_pais, paises[27]);
			tam_nome = 	strlen(nome_pais);
	
			for(i=0; i<tam_nome;i++){
				*pnome_pais = nome_pais[i];
				++pnome_pais;
			}	
			
			*pnome_pais = '\0';
			
			break;
		case 29:
			strcpy(nome_pais, paises[28]);
			tam_nome = 	strlen(nome_pais);
	
			for(i=0; i<tam_nome;i++){
				*pnome_pais = nome_pais[i];
				++pnome_pais;
			}	
			
			*pnome_pais = '\0';
			
			break;
		case 30:
			strcpy(nome_pais, paises[29]);
			tam_nome = 	strlen(nome_pais);
	
			for(i=0; i<tam_nome;i++){
				*pnome_pais = nome_pais[i];
				++pnome_pais;
			}	
			
			*pnome_pais = '\0';
			
			break;
		default:printf("\nOpção Inválida\n");
	};
}

void escolhe_piloto_volta(int id, int *paux_piloto){
	
	do{
		printf("\nInforme a opção escolhida: ");
		scanf("%d", &*paux_piloto);
		fflush(stdin);
		
		if(*paux_piloto > id || *paux_piloto < 1){
			printf("\nOpção inválida");
		}
	}while(*paux_piloto > id || *paux_piloto < 1);
}

void escolhe_circuito_volta(int id, int *paux_circuito){
	
	do{
		printf("\nInforme a opção escolhida: ");
		scanf("%d", &*paux_circuito);
		fflush(stdin);
		
		if(*paux_circuito > id || *paux_circuito < 1){
			printf("\nOpção inválida");
		}
	}while(*paux_circuito > id || *paux_circuito < 1);
}

void le_valida_data(int *pdia, int *pmes, int *pano){
	do{
		printf("\nInforme o dia da volta: ");
		scanf("%d", &*pdia);
		fflush(stdin);
		
		if(*pdia<1 || *pdia>31){
			printf("Dia inválido.");
		}
	}while(*pdia<1 || *pdia>31);
	
	do{
		printf("\nInforme o mês da volta: ");
		scanf("%d", &*pmes);
		fflush(stdin);
		
		if(*pmes<1 || *pmes>12){
			printf("Mês inválido.");
		}
	}while(*pmes<1 || *pmes>12);
	
	do{
		printf("\nInforme o ano da volta: ");
		scanf("%d", &*pano);
		fflush(stdin);
		
		if(*pano<1950 || *pano>2022){
			printf("Ano inválido.");
		}
	}while(*pano<1950 || *pano>2022);
	
}

void le_valida_tempo(int *pmin, int *pseg, int *pmil){
	do{
		printf("\nInforme o minuto da volta: ");
		scanf("%d", &*pmin);
		fflush(stdin);
		
		if(*pmin<0 || *pmin>59){
			printf("Minuto inválido.");
		}
	}while(*pmin<0 || *pmin>59);
	
	do{
		printf("\nInforme o segundo da volta: ");
		scanf("%d", &*pseg);
		fflush(stdin);
		
		if(*pseg<0 || *pseg>59){
			printf("Segundo inválido.");
		}
	}while(*pseg<0 || *pseg>59);
	
	do{
		printf("\nInforme os milésimos da volta: ");
		scanf("%d", &*pmil);
		fflush(stdin);
		
		if(*pmil<0 || *pmil>999){
			printf("Milésimo inválido.");
		}
	}while(*pmil<0 || *pmil>999);
	
}

void le_valida_nome_piloto(char *pnome_piloto){
	char nome_piloto[MAX_PILOTO];
	int tam_nome, i=0;
	fflush(stdin);
	do{// do-while para verificação de campo sem valor
			printf("Informe o nome do piloto: ");
		    scanf("%[^\n]s", &nome_piloto);
		    fflush(stdin);
				if(strlen(nome_piloto) <= 5)
					printf("\nNome Inválido\n\n");
		}while(strlen(nome_piloto) <= 5);
		
	tam_nome = 	strlen(nome_piloto);
	
	for(i=0; i<tam_nome;i++){
		*pnome_piloto = nome_piloto[i];
		++pnome_piloto;
	}	
	
	*pnome_piloto = '\0';
}

void le_valida_equipe(char *pnome_equipe){
	char nome_equipe[20];
	int tam_nome, i=0;
	fflush(stdin);
	do{// do-while para verificação de campo sem valor
			printf("\nInforme o nome da equipe do piloto: ");
		    scanf("%[^\n]s", &nome_equipe);
		    fflush(stdin);
				if(strlen(nome_equipe) <= 3)
					printf("\nNome Inválido\n\n");
		}while(strlen(nome_equipe) <= 3);
		
	tam_nome = 	strlen(nome_equipe);
	
	for(i=0; i<tam_nome;i++){
		*pnome_equipe = nome_equipe[i];
		++pnome_equipe;
	}	
	
	*pnome_equipe = '\0';
}

void le_valida_nome_circuito(char *pnome_circuito){
	char nome_circuito[MAX_CIRCUITOS];
	int tam_nome, i=0;
	fflush(stdin);
	do{// do-while para verificação de campo sem valor
			printf("Informe o nome do circuito: ");
		    scanf("%[^\n]s", &nome_circuito);
		    fflush(stdin);
				if(strlen(nome_circuito) <= 3)
					printf("\nNome Inválido\n\n");
		}while(strlen(nome_circuito) <= 3);
		
	tam_nome = 	strlen(nome_circuito);
	
	for(i=0; i<tam_nome;i++){
		*pnome_circuito = nome_circuito[i];
		++pnome_circuito;
	}	
	
	*pnome_circuito = '\0';
}

void valida_id_piloto(int *pid_piloto){
	do{
		printf("\nInforme a identificação do piloto [valor entre 100 e 500]: ");
		scanf("%d", &*pid_piloto);
		fflush(stdin);
		
		if(*pid_piloto <100 || *pid_piloto >500){
			printf("\nNúmero inválido. A identificação deve ser entre 100 e 500");
		} 
		
	}while(*pid_piloto<100 || *pid_piloto >500);
}

void valida_tam_circuito(float *ptam_circ){
	do{
		printf("\nInforme o tamanho em km do circuito [valor entre 1 e 10]: ");
		scanf("%f", &*ptam_circ);
		fflush(stdin);
		
		if(*ptam_circ <1 || *ptam_circ >10){
			printf("\nTamanho inválido. O circuito deve ter entre 1 e 10km");
		} 
		
	}while(*ptam_circ<1 || *ptam_circ >10);
}

void valida_idade_piloto(int *pidade_piloto){
	do{
		printf("\nInforme a idade do piloto: ");
		scanf("%d", &*pidade_piloto);
		fflush(stdin);
		
		if(*pidade_piloto <15 || *pidade_piloto >50){
			printf("\nIdade inválida.");
		} 
		
	}while(*pidade_piloto<15 || *pidade_piloto >50);
}

void sexo_piloto(char *psexo_piloto){
	
	do{
		fflush(stdin);
		printf("\nInforme o sexo do piloto [F|M]: ");// Opção para voltar ao menu de cadastramento e visualização de jogos
		scanf("%s", &*psexo_piloto);
		fflush(stdin);
		
		*psexo_piloto = toupper(*psexo_piloto);
		
			if(*psexo_piloto != 'F' && *psexo_piloto != 'M')
				printf("\nOpção Inválida");
	}while(*psexo_piloto != 'F' && *psexo_piloto != 'M');
	
}

void saida(char *saida){
	
	do{
		fflush(stdin);
		printf("\n\nVoltar ao menu anterior?[S|N] ");// Opção para voltar ao menu de cadastramento e visualização de jogos
		scanf("%c", &*saida);
		fflush(stdin);
		
		*saida = toupper(*saida);
		
			if(*saida != 'S' && *saida != 'N')
				printf("\nOpção Inválida");
	}while(*saida != 'S' && *saida != 'N');
	
}
