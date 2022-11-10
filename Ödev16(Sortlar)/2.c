#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

void degistir(int *x,int *y){
	int gecici = *x;
	*x = *y;
	*y = gecici;
}
void bastir (int *z,int w){
	for(int i=0 ; i<w ; i++){
		printf("%d\t",*z);	
		z=z+1;
	}
}
void quicksort(int dizi[],int ayrac, int uzunluk,int a){
	//switch 1 ise k���kten b�y��e s�ral�yor, switch 2 ise b�y�kten k����e
	switch(a){
	case 1:{
		int ayrac2 = ayrac+1;
 	if(ayrac==uzunluk)
  		return bastir(&dizi[0],50);
	else{
  		for (int i=ayrac ; i<uzunluk ; i++){
 	 		if (dizi[i] < dizi[ayrac])
  	   		degistir(&dizi[i], &dizi[ayrac]);
		}
	}
	quicksort(dizi,ayrac2,uzunluk,1);
		break;
	}
	case 2:{
		int ayrac2 = ayrac+1;
 	if(ayrac==uzunluk)
  		return bastir(&dizi[50],50);
	else{
  		for (int i=ayrac ; i<uzunluk ; i++){
 	 		if (dizi[i] > dizi[ayrac])
  	   		degistir(&dizi[i], &dizi[ayrac]);
		}
	}
	quicksort(dizi,ayrac2,uzunluk,2);
		break;
	}
}
}
int main(){
	int dizi[100];
	int a,b=0;
	int minimum;
	srand(time(NULL));
	for(int i=0;i<100;i++){
		a=rand()%100+1;
		dizi[i]=a;
	}
	printf("100 Elemanli Dizi:\n");
		for(int i=0;i<100;i++){
			printf("%d\t",dizi[i]);
	}
	printf("\n\nDevam etmek icin bir tusa bas...");
	getch();
		printf("\n\nIlk 50 elemanin siralanmasi:\n");
		quicksort(dizi,0,50,1);
		
		printf("\n\nSon 50 elemanin siralanmasi:\n");
		quicksort(dizi,50,100,2);
		
		printf("\n\n\nTum dizinin siralamasi: \n");
		bastir(&dizi[0],100);
}
// Created by MURABIT-PASHA