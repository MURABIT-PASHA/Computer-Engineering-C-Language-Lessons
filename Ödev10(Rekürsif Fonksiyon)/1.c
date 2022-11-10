#include <stdio.h>
int rekursif(int d, int e,int f);
int main(){
	int a, b;
	printf ("Ilk sayiyi giriniz: ");
	scanf("%d",&a);
	printf ("Ikinci sayiyi giriniz: ");
	scanf("%d",&b);
	int c=a;
	printf ("OBEB: %d",rekursif(a,b,c));
	return 0;
}
int rekursif(int d,int e,int f){
	int obeb;
	if(d%f==0 && e%f==0){
		obeb=f;
	}
	else{
		obeb=rekursif(d,e,f-1);
	}
	return obeb;
}
// Created by MURABIT-PASHA
