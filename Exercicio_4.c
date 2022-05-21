/*
Desenvolva um programa que receba um nome e retorne em formato de passagens aéreas:

Ex:
Nome: Diego Silva Marques Rodrigues
-> RODRIGUES, D. S. M.
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){

	char nome[100];
	int tamanho=0, i = 0, contador = 0, nomes[20];

	printf("Informe o nome completo do pesquisador: ");
	scanf("%[^\n]s", &nome);
	
	tamanho = strlen(nome);
	
	for(i=0;i<tamanho;i++){
		if(nome[i]==' ') {
			nomes[contador] = i;
			contador++;
		} 
	}
		
	for(i=nomes[contador-1]+1; i<=tamanho-1;i++){
		printf("%c", toupper(nome[i]));
	}
	
	printf("/ ");
	
	for(i=0; i<contador-1;i++){
		if(i==0){
			printf("%c. ", toupper(nome[0]));
			printf("%c. ", toupper(nome[nomes[i]+1]));
		} else{
			printf("%c. ", toupper(nome[nomes[i]+1]));
		}
	}
	
	return 0;
}
