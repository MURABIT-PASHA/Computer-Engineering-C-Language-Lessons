//  Syraly ekleme �rne?ini �ift y�nl� ba?ly listelerle ger�ekle?tiriniz.  

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct Node{
	int sayi;
	struct Node *sonraki;
	struct Node *onceki;
};


int main(){
	
	struct Node *ilk=NULL;
	struct Node *gecici1=NULL;
	struct Node *gecici2=NULL;
	int kontrol;
	char ch;
	
	do{
		struct Node *yeni=(struct Node*)malloc(sizeof(struct Node));
		printf("Eklenecek Sayiyi Giriniz -->  ");
		scanf("%d",&yeni->sayi);
		yeni->sonraki=NULL;
		yeni->onceki=NULL;
		if(ilk == NULL)
		{
			ilk=yeni;
		}
		else if(ilk->sayi > yeni->sayi)
		{
			yeni->sonraki=ilk;
			ilk=yeni;
			ilk->sonraki->onceki=ilk;
			
		}
		else
		{
			gecici1=ilk;
			gecici2=ilk->sonraki;
			while(gecici2 != NULL)
			{
				if(gecici2->sayi < yeni->sayi)
				{
					gecici1=gecici1->sonraki;
					gecici2=gecici2->sonraki;
				}
				else
				{
					break;	
				}
				
				
			}
			if(gecici2 == NULL)
			{
				gecici1->sonraki=yeni;
				gecici1->sonraki->onceki=gecici1;
			}
			else
			{
				gecici1->sonraki=yeni;
				gecici1->sonraki->onceki=gecici1;
				yeni->sonraki=gecici2;
				yeni->sonraki->onceki=yeni;
			}
			
			
		}

	printf("\nDevam etmek ister misiniz?(E/H)\n");
	ch=getch();
	}while(ch=='e' || ch=='E');
			
	
	printf("\nSiralama\n");
	gecici1=ilk;
	while(gecici1 != NULL)
	{
		printf("Sayi : %5.1d\tAdresi : %6.1X\n",gecici1->sayi,gecici1);
		gecici1=gecici1->sonraki;
	}

	
	getch();
	return 0;
}
// Created by MURABIT-PASHA