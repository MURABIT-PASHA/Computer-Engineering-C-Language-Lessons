#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
int main(){

int A[10], B[10], C[20];
int randa, randb, sayac=1;//A ve B'ye atanacak random
srand(time(0));
int toplam=0;
printf ("A kumesi: ");
		for(int i=0 ; i<=9 ; i++){
		randa=rand()%100+1;
		randb=rand()%100+1;
		A[i]=randa;
		B[i]=randb;
		printf("%d  ",A[i]);
		}
		printf("\nB kumesi: ");
				for(int i=0 ; i<=9 ; i++){
				printf("%d  ",B[i]);
				}
				C[0]=A[0];
				for (int i=1 ; i<10 ; i++){
					bool kontrol=false;
					for (int j=0 ; j<sayac ; j++){
						if(A[i]>C[j])
						{
							for (int k=sayac ; k>j ; k--)
							C[k]=C[k-1];
							C[j]=A[i];
							sayac++;
							kontrol=true;
							break;
						}
						
					}
					if (!kontrol)
					{
						C[sayac]=A[i];
						sayac++;
					}
				}
				for(int i=0 ; i<10 ; i++)
				{
					bool kontrol=false;
					for (int j=0 ; j<sayac ; j++)
					{
						if(B[i]>C[j]){
							for (int k=sayac ; k>j ; k--)
							C[k]=C[k-1];
							C[j]=B[i];
							sayac++;
							kontrol=true;
							break;
						}
						
					}
					if (!kontrol)
					{
						C[sayac]=B[i];
						sayac++;
					}
				}
	printf("\nC kumesinin siralanmasi:\n");
	for (int i=0 ; i<20 ; i++)
	{
		printf ("%d  ",C[i]);
	}			
	return 0;
}
// Created by MURABIT-PASHA