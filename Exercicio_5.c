#include<stdio.h>//biblioteca para entrada e saída
#include<ctype.h>
#include<math.h>
#include<stdlib.h>

// prototipação

int soma(int n1, int n2);
int subtracao(int n1, int n2);
int mult(int n1, int n2);
int divisao(int n1, int n2);
int menu(char saida);
int le_valida_operador(int op);

int main(){
	
	// declaração das variaveis
	int n1, n2, result;
	char op, saida, aux_saida;
	int i=0, div_0=0;
	
	printf("----------Calculadora----------\n");
		
	do{

		div_0=0;
		i=0;
		saida='S';
		
		printf("Informe o primeiro numero: ");
		scanf("%d", &n1);
		
		printf("Operador matematico: ");
		scanf(" %c", &op);
		
		op=le_valida_operador(op);
				
		printf("Informe o segundo numero: ");
		scanf("%d", &n2);
		fflush(stdin);
		
		if (op=='+'){
			result=soma(n1, n2);
		}
		else if (op=='-'){
			result=subtracao(n1,n2);
		}
		else if (op=='*'){
			result=mult(n1,n2);
		}
		else if (op=='/'){
			if(n2==0){
				printf("Nao eh possivel dividir por 0");
				div_0=1;
			} else{
			result=divisao(n1,n2);
			}
		}
		
		if(div_0==0){
			printf("Resultado: %i ", result);
		} 
		
		printf("\nDeseja fazer nova conta?[S|N] ");// Opção para fazer nova conta
		scanf("%c", &aux_saida);
		
		saida=menu(aux_saida);
					
		system("cls");

	}while(saida=='S');
	
	return 0;
	}
	

int soma(int n1, int n2){
	return n1+n2;
}

int subtracao(int n1, int n2){
	return n1-n2;
}

int mult(int n1, int n2){
	return n1*n2;
}

int divisao(int n1, int n2){
	return n1/n2;
}

int menu(char saida){
	
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

int le_valida_operador(int op){
	
	do{	
		fflush(stdin);
		
		if (op!='+' && op!='-' && op!='*' && op!='/'){
			printf("Operador nao aceito\n");
			printf("Operador matematico: ");
			scanf(" %c", &op);
		}
				
	}while (op!='+' && op!='-' && op!='*' && op!='/');
	
	return op;
}
