// Informar a idade, se tiver menos do que 18, não vota, mais do que 18, vota.

/*
Menor que 0 - não nasceu
0 até 15 não vota
16 ou 17 - opcional
18 até 64 - obrigatório
65 ou mais - opcional
41 - ganha prêmio 1 $$$
82 - ganha prêmio 2 $$$
*/

// Não utilizar else if, e &&, ou ||, switch case. Apenas if else.

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
