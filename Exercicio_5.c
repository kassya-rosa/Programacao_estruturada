#include<stdio.h>//biblioteca para entrada e saída
#include<ctype.h>
#include<math.h>
#include<stdlib.h>

// prototipação

float soma(float n1, float n2);
float subtracao(float n1, float n2);
float mult(float n1, float n2);
float divisao(float n1, float n2);
char menu(char saida);
char le_valida_operador();

int main(){
	
	// declaração das variaveis
	float n1, n2, result;
	char op, saida, aux_saida;
	int i=0, div_0=0;
	
	printf("----------Calculadora----------\n");
		
	do{

		div_0=0;
		saida='S';
		
		printf("Informe o primeiro numero: ");
		scanf("%f", &n1);
		
		printf("Operador matematico: ");
		op=le_valida_operador();
				
		printf("Informe o segundo numero: ");
		scanf("%f", &n2);
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
			printf("Resultado: %.1f ", result);
		} 
		
		printf("\nDeseja fazer nova conta?[S|N] ");// Opção para fazer nova conta
		scanf("%c", &aux_saida);
		
		saida=menu(aux_saida);
					
		system("cls");

	}while(saida=='S');
	
	return 0;
	}
	

float soma(float n1, float n2){
	return n1+n2;
}

float subtracao(float n1, float n2){
	return n1-n2;
}

float mult(float n1, float n2){
	return n1*n2;
}

float divisao(float n1, float n2){
	return n1/n2;
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

char le_valida_operador(){
	int i=0;
	char op;
			
	do{	
				
		if (i!=0){
			printf("Operador nao aceito\n");
		}
		scanf(" %c", &op);
		i++;
				
	}while (op!='+' && op!='-' && op!='*' && op!='/');
	
	return op;
}
