//Vari�vel � aloca��o de espa�o em mem�ria
// A vari�vel tem 3 elecomentos: nome (identifica��o), tipo e valor
// Tipos principais: Int, Char, Float e Double

// Informar a idade, se tiver menos do que 18, n�o vota, mais do que 18, vota.

/*
Menor que 0 - n�o nasceu
0 at� 15 n�o vota
16 ou 17 - opcional
18 at� 64 - obrigat�rio
65 ou mais - opcional
41 - ganha pr�mio 1 $$$
82 - ganha pr�mio 2 $$$
*/

// N�o utilizar else if, e &&, ou ||, switch case. Apenas if else.

#include<stdio.h>

int main(void) {
  int idade;
	
		printf("Informe a sua idade: ");
		scanf("%d", &idade);
		fflush;
		
		if (idade == 41){
      printf("Premio 1");
	    }else{
		      if (idade == 82){
		        printf("Premio 2");
		      }else{
			        if (idade < 0){
			    		printf("Nao nasceu");
			    	}else { 
			    			if (idade < 16) {
			    				printf("Nao vota");
			    			}else {
				    				if (idade < 18) {
				    					printf("Voto opcional");
				    				}else{
							              if (idade < 65){
							                printf("Voto obrigatorio");
							              }else{
							                     printf("Voto opcional");
							                }}}}}}
					  	
  return 0;
}
