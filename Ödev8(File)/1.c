#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int main(){
	int sayilar[100];
	srand(time(NULL));
	for (int i=0 ; i<100 ; i++){
		sayilar[i]=rand()%1000;
	}
	FILE *filep = fopen("Sayilar.txt","w");
	for (int j=0 ; j<100 ; j++){
	fprintf(filep,"%d\n",sayilar[j]);
	}
	printf("Random sayilariniz basariyla olusturuldu...");
	fclose(filep);
}
// Created by MURABIT-PASHA