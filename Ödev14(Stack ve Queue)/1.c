#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <stdlib.h>
struct numaralar{
	int numara;
	int sira;
	struct numaralar* yukari = NULL;
	struct numaralar* asagi = NULL;
};
int main(){
	setlocale (LC_ALL, "Turkish");
	struct numaralar* ilk = NULL;
	struct numaralar* tepe = NULL;
	struct numaralar* gecici = NULL;
	struct numaralar* gecici2 = NULL;
	int a,b=1,c;
	char d;
	do{
		printf("Bir sayi gir: ");
		scanf("%d",&a);
		if(ilk == NULL){
			ilk = (struct numaralar*) malloc(sizeof(struct numaralar));
			ilk->asagi = NULL;
			ilk->yukari = NULL;
			ilk->numara = a;
			ilk->sira = b;
			b++;
			tepe = ilk;
		}
		else{
			tepe->yukari = (struct numaralar*) malloc(sizeof(struct numaralar));
			gecici = tepe;
			tepe = tepe->yukari;
			tepe->numara=a;
			tepe->sira=b;
			b++;
			tepe->asagi=gecici;
			tepe->yukari=NULL;			
		}
		printf("Devam edilsin mi? (E)vet & (H)ayir\n");
		d=getch();
	}while(d=='E' || d=='e');
		printf ("\nYigin Veri Yapisina Gore:\n");
		gecici2 = tepe;
		while(gecici2!=NULL){
			printf ("%d. Sayi: %d\n",gecici2->sira,gecici2->numara);
			gecici2=gecici2->asagi;
		}
		gecici2 = ilk;
		printf ("\nKuyruk Veri Yapisina Gore:\n");
		while(gecici2!=NULL){
			printf ("%d. Sayi: %d\n",gecici2->sira,gecici2->numara);
			gecici2=gecici2->yukari;
		}
		
}
// Created by MURABIT-PASHA