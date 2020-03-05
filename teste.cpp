#include <stdio.h>
#include <stdlib.h>

int main(){
	
	int opc,valor;
	//1 base 10 para 16
	//2 base 16 para 10
	printf("opcao 1 Base10 para Base16 \nopcao 2 Base16 para Base10\n");
	printf("\nescolha opcao");scanf("%d",&opc);
	
	if(opc==1){
		printf("digite valor na b10..:");scanf("%d",&valor);
		printf("%x",valor);
	}
		if(opc==2){
		printf("digite valor na b16..:");scanf("%x",&valor);
		printf("%d",valor);
	}
}
