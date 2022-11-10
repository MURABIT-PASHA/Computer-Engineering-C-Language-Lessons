//Calculator created by MURABIT-PASHA
#include <stdio.h>
#include <locale.h>
void kiyaslama(int a,int b){
	if(a<b)
	printf("First number smaller than second");
	else if(b<a)
	printf("Second number smaller than first");
	else
	printf("Those numbers are equals each other");
}
int main(){
	setlocale (LC_ALL, "Turkish");
	int a;
	int ilk,ikinci,sonuc;
	double ilk1,ikinci1,sonuc1;
	printf("What do you want to do:\n1-Sum\n2-Ext\n3-Mul\n4-Div\n");
	scanf("%d",&a);
	switch(a){
		case 1:
			printf("First number: ");
			scanf("%d",&ilk);
			printf("Then the other one: ");
			scanf("%d",&ikinci);
			sonuc = ilk + ikinci;
			printf("Result: %d\n",sonuc);
			kiyaslama(ilk,ikinci);
			break;
		case 2:
			printf("First number: ");
			scanf("%d",&ilk);
			printf("Then the other one: ");
			scanf("%d",&ikinci);
			sonuc = ilk - ikinci;
			printf("Result: %d\n",sonuc);
			kiyaslama(ilk,ikinci);
			break;
		case 3:
			printf("First number: ");
			scanf("%d",&ilk);
			printf("Then the other one: ");
			scanf("%d",&ikinci);
			sonuc = ilk * ikinci;
			printf("Result: %d\n",sonuc);
			kiyaslama(ilk,ikinci);
			break;
		case 4:
			printf("First number: ");
			scanf("%d",&ilk1);
			printf("Then the other one: ");
			scanf("%d",&ikinci1);
			sonuc1 = ilk1 / ikinci1;
			printf("Result: %.2f\n",sonuc1);
			kiyaslama(ilk,ikinci);
			break;
		default:
			printf("TypeError: Not found...");
			break;
	}
	return 0;
}
