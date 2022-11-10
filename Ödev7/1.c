#include <stdio.h>
int sayac=0;
int asal(int x){
	if ((x!=2) && (x%2==0) || (x!=3) && (x%3==0) || (x!=5) && (x%5==0) || (x!=7) && (x%7==0))
	printf("");
	else{
	printf("%d\t",x);
	sayac++;	}
	
}
int main(){
	int x;
	printf ("Bir pozitif tamsayi sayi giriniz: ");
	scanf ("%d",&x);
	for (int i=0 ; i<50 ; i++){
		asal(x+1);
		x++;
		if(sayac==10){
		break;
		}
	}
	
return 0;	
}
// Created by MURABIT-PASHA