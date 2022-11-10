#include <stdio.h>
int sayibulma(int a){
	int top;
	if (a<=0){
		top=0;
	}
	else{
		top=a+sayibulma(a-1);
	}
	return top;
}
int main(){
	int a;
	printf ("Bir sayi giriniz: ");
	scanf("%d",&a);
	printf("Girdiginiz sayiya kadar olan sayilarin toplami: %d\nGirdiiiniz sayi dahil: %d",sayibulma(a)-a,sayibulma(a));
}
// Created by MURABIT-PASHA