/*�devimiz*/
#include <stdio.h>//printf ve FILE i�lemlerimiz i�in
#include <stdlib.h>//malloc i�in
#include <locale.h>//language i�in
#include <math.h>//�ss�n� almak i�in
//#include <conio.h>//ne olur ne olmaz diye
#include <windows.h>//sleep ve exit i�in
struct Dugum{
	int derece;
	int katSayi;
	struct Dugum* sonraki=NULL;
};
int kontrol(struct Dugum* ilk,int derece){
		struct Dugum* gecici;
		gecici=ilk;
		while(gecici!=NULL){
			if(gecici->derece==derece)
				return 1;
			
			gecici=gecici->sonraki;
		}
		return 2;
}
void menu(struct Dugum* ilk);//Burada ad�n� verdik en alta yazmay� d���n�yorum.

	void ekleme(int derrece,int katsayi,struct Dugum* ilk){	
		struct Dugum* gecici1;
		struct Dugum* gecici2;
		struct Dugum* yeni=(struct Dugum*)malloc(sizeof(struct Dugum));
		yeni->derece=derrece;
		yeni->katSayi=katsayi;
		yeni->sonraki=NULL;
		
		/*Her�eyden �nce kontrol ediyor daha �nce var m� diye*/
		if(kontrol(ilk,derrece)==1)
			printf("Daha �nce bu dereceden bir terim eklenmi�...\n");
		
		else{

			/*�imdi e�er ilk bo� ise
			yeni dedi�imiz eleman� ilke at�yor.*/
			if(ilk == NULL){
			ilk=yeni;
			}
			/*Diyelimki ikinciyi yap�yoruz. Bu durumda iki ��k vard�r. Derece ya ilkten b�y�k ya da k���k olmal�d�r.
			E�er b�y�kse yer de�i�tiriyoruz. E�er k���kse a�a��daki else b�l�m�nde eklenecek*/
			else if(ilk->derece < yeni->derece){
			yeni->sonraki=ilk;
			ilk=yeni;			
			}
			/*�imdi buraya kadar iyi de bir k�sm� atlad�m. �rne�in �nce 4 sonra 7 ve sonra 2 ve en sonunda 5 ekledik diyelim. 
			�lk=4 olacak 7 eklenince ilk=7 ve ilk->sonraki=4 olacak ancak 2 eklenince 2 yi nereye koyaca��z. Yani 
			kar���k bir konu bu sebeple t�m d���mleri gezecek gecici adl� d���mlerimiz var. �lkten b�y�k olmayan her say�
			bu y�ntemle eklenecek*/
			else{
			gecici1=ilk;
			gecici2=ilk->sonraki;
				while(gecici2 != NULL){
				if(gecici2->derece > yeni->derece){
					gecici1=gecici1->sonraki;
					gecici2=gecici2->sonraki;
				}
				else				
					break;				
				}
				
				if(gecici2 == NULL)			
				gecici1->sonraki=yeni;			
				
				else{
				gecici1->sonraki=yeni;
				yeni->sonraki=gecici2;
				}			
			}
			/*S�ral� ekleme tamamd�r. Menuye geri d�nelim*/
		}
	menu(ilk);
	}
void cikarma(int derrece,int katsayi,struct Dugum* ilk){
	struct Dugum* gecici;
	struct Dugum* bul;
	gecici=ilk;
	int c=0;
		while(gecici!=NULL){
			if (gecici->derece==derrece && gecici->katSayi==katsayi){
				bul = gecici;
				c=1;
				break;
			}
			else
				gecici = gecici->sonraki;			
		}
	
	switch(c){
		case 0:
		printf ("Aranan de�er bulunamad�.");
		break;
		case 1:	
		if(bul==ilk){
			printf ("\nAranan de�er bulundu!\n%x adresindeki say� silindi.\n",gecici);
			ilk=ilk->sonraki;
			free(bul);
		}
		else{
			printf ("\nAranan de�er bulundu!\n%x adresindeki say� silindi.\n",gecici);
			gecici=ilk;
			while (gecici->sonraki!=bul)
			gecici=gecici->sonraki;
			gecici->sonraki=gecici->sonraki->sonraki;
			free(bul);
		}
		break;
	}
	menu(ilk);
}
void yazdirma(struct Dugum* ilk,int a){
	/*E�er sondaki de�er (a) 1 ise ekrana yazd�r�yor 2 ise dosyaya yazd�r�yor*/
	if(a==1){
		if (ilk==NULL){
		printf("Liste bo�");
		Sleep(1000);
		printf(".");
		Sleep(1000);
		printf(".");
		Sleep(1000);
		printf(".\n");
		menu(ilk);
		}	
		struct Dugum* gecici;
		gecici=ilk;
		while(gecici!=NULL){
			printf("%dx^%d ",gecici->katSayi,gecici->derece);
			if(gecici->sonraki!=NULL)
			printf("+ "); 
			gecici=gecici->sonraki;
		}
		printf("\n");
		menu(ilk);
		}
	else if(a==2){
		if (ilk==NULL){
		printf("Liste bo�");
		Sleep(1000);
		printf(".");
		Sleep(1000);
		printf(".");
		Sleep(1000);
		printf(".\n");
		system("cls");
		menu(ilk);
		}
		FILE *fp = fopen("Polinom.txt","w+");	
		struct Dugum* gecici;
		gecici=ilk;
		while(gecici!=NULL){
			fprintf(fp,"%dx^%d ",gecici->katSayi,gecici->derece);
			if(gecici->sonraki!=NULL)
			fprintf(fp,"+ "); 
			gecici=gecici->sonraki;
		}
		fclose(fp);	
	}
	else{
		/*�imdi kullan�c�n�n eri�ip gelen 
		say�y� 1 yada 2 d���nda bir �ey yapmas� 
		imkans�z ama bu kodu inceleyen birisi kod �zerinde
		de�i�iklik yaparsa hatay� alacak.*/ 
		for(int i=0 ; i<10000 ; i++){
			printf("System Failure");
		}
	}
}
void hesaplama(struct Dugum* ilk, int x){
	struct Dugum* gecici;
	int sonuc=0;
	gecici=ilk;
	while(gecici!=NULL){
		sonuc += pow(x,gecici->derece)*gecici->katSayi;
		gecici=gecici->sonraki;
	}
	printf("Sonu�: %d",sonuc);
	menu(ilk);
}
int main(){
setlocale (LC_ALL, "Turkish");
struct Dugum* ilk=NULL;
	menu(ilk); /*Menuyu main i�erisinde de yazabilirdik 
	ancak ben s�rekli her i�lemden sonra men�ye d�nmesini
	istiyorum goto kullanarak da pek sa�l�kl� olmuyor. Bu sebeple 
	menu ayr� bir fonksiyon olarak yaz�ld�.*/
}
void menu(struct Dugum* ilk){
	int a;
	int xkatsayi, xderece;
	printf ("Hangi i�lemi yapmak istiyorsunuz?\n1-Ekleme\n2-��karma\n3-Yazd�rma\n4-Hesaplama\n5-��k��\n");
	scanf("%d",&a);
		switch(a){
			int x;
			case 1:
				printf("Eklenecek say�n�n derecesini giriniz: ");
				scanf("%d",&xderece);
				printf("Eklenecek say�n�n katsay�s�n� giriniz: ");
				scanf("%d",&xkatsayi);
				ekleme(xderece,xkatsayi,ilk);
				break;
			case 2:
				printf("��karmak istedi�iniz de�i�kenin katsay�s�n� giriniz: ");
				scanf("%d",&xkatsayi);
				printf("��karmak istedi�iniz de�i�kenin derecesini giriniz: ");
				scanf("%d",&xderece);
				cikarma(xderece,xkatsayi,ilk);
				break;
			case 3:
				printf("Fonksiyonunuz: ");
				yazdirma(ilk,1);
				break;
			case 4:
				printf("x de�i�kenini giriniz: ");
				scanf("%d",&x);
				hesaplama(ilk,x);
				break;
			case 5: 
				yazdirma(ilk,2);//yazdirma fonksiyonuna gidiyor.
				exit(1);
				break;
		}
}
/* Her �ey tamam */

