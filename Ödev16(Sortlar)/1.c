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
	getch();
	//ilk 50 eleman selection sort ile b�y�kten k����e
	printf("\n\nIlk 50 elemanin siralanmasi:\n");
			for(int i=0 ; i<51 ; i++){
				minimum = i;
				for(int j=i+1; j<50 ; j++){
					if(dizi[j]>dizi[minimum])
					minimum=j;
				}	
				degistir(&dizi[minimum],&dizi[i]);
			}
			bastir(&dizi[0],50);
	//son 50 eleman insertion sort ile k���kten b�y��e
	printf("\n\nSon 50 elemanin siralanmasi:\n");
			for(int i=50 ; i < 100 ; i++){
				int j = i;
				while(j>50 && dizi[j-1]>dizi[j]){
					degistir(&dizi[j],&dizi[j-1]);
					j--;
				}
			}
			bastir(&dizi[50],50);
	return 0;				
}
// Created by MURABIT-PASHA