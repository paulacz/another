#include <stdio.h>

int main(){
	int i, pilares, vigas , valorpilar1 ,valorpilar2 , valorviga1,  valorviga2;
	
	printf("			CALCULO DE ERRO RELATIVO DE PILARES E VIGAS\n\n");
	printf("Quantidades de pilares:");scanf("%i",&pilares);
	printf("valores aceitaveis pilares..:"); scanf("%i",&valorpilar1);
	printf("Valores aceitaveis totais pilares..:"); scanf("%i",&valorpilar2);
	printf("\n\nQuantidades de vigas:");scanf("%i",&vigas);
	printf("Valores aceitaveis de vigas..:"); scanf("%i",&valorviga1);
	printf("Valores aceitaveis vigas totais..:"); scanf("%i",&valorviga2);
	
	
	float valorcal,valorexe;
	float erropilares[pilares],erepilares[pilares],etpilares=0;
	float errovigas[vigas],erevigas[vigas],etvigas=0;
	

for(i=0;i<pilares;i++){
	printf("\n\n\nDigite os valores calculados dos pilares %i...:",i+1); scanf("%f",&valorcal);
	printf("Digite os valores executados dos pilares %i...:",i+1); scanf("%f",&valorexe);	
	erropilares[i]=valorcal-valorexe;
	
if(erropilares[i]<0){
		erropilares[i]=erropilares[i]*(-1);}
	
	erepilares[i]=(erropilares[i]/valorcal)*100;
	printf("Erro absoluto pilares %.2f\n",erropilares[i]);
	printf("Erro relativo pilares %.2f%%\n",erepilares[i]);
	
if(erepilares[i]>valorpilar1){
	printf("erro relativo acima dos parametros aceitaveis\n\n");}
	
	etpilares=etpilares+erepilares[i];           }
	
	
	
	printf("erro total %.2f%%\n",etpilares);
if(etpilares>valorpilar2){
	printf("erro total acima dos parametros permitidos ");}
	
	for(i=0;i<vigas;i++){
	printf("\n\n\nDigite os valores calculados das vigas %i...:",i+1); scanf("%f",&valorcal);
	printf("Digite os valores executados das vigas %i...:",i+1); scanf("%f",&valorexe);	
	errovigas[i]=valorcal-valorexe;
	
if(errovigas[i]<0){
		errovigas[i]=errovigas[i]*(-1);}
	
	erevigas[i]=(errovigas[i]/valorcal)*100;
	printf("Erro absoluto vigas %.2f\n",errovigas[i]);
	printf("Erro relativo vigas %.2f%%\n",erevigas[i]);
	
if(erevigas[i]>valorviga1){
	printf("Erro relativo acima dos parametros aceitaveis\n\n");}
	
	etvigas=etvigas+erevigas[i];           }
	
		
	printf("Erro total vigas %.2f%%\n",etvigas);
if(etvigas>valorviga2){
	printf("Erro total acima dos parametros permitidos ");}
}
