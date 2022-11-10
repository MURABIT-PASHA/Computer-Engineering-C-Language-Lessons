/*Ödevimiz*/
#include <stdio.h>//printf ve FILE iþlemlerimiz için
#include <stdlib.h>//malloc için
#include <locale.h>//language için
#include <math.h>//üssünü almak için
//#include <conio.h>//ne olur ne olmaz diye
#include <windows.h>//sleep ve exit için
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
void menu(struct Dugum* ilk);//Burada adýný verdik en alta yazmayý düþünüyorum.

	void ekleme(int derrece,int katsayi,struct Dugum* ilk){	
		struct Dugum* gecici1;
		struct Dugum* gecici2;
		struct Dugum* yeni=(struct Dugum*)malloc(sizeof(struct Dugum));
		yeni->derece=derrece;
		yeni->katSayi=katsayi;
		yeni->sonraki=NULL;
		
		/*Herþeyden önce kontrol ediyor daha önce var mý diye*/
		if(kontrol(ilk,derrece)==1)
			printf("Daha önce bu dereceden bir terim eklenmiþ...\n");
		
		else{

			/*Þimdi eðer ilk boþ ise
			yeni dediðimiz elemaný ilke atýyor.*/
			if(ilk == NULL){
			ilk=yeni;
			}
			/*Diyelimki ikinciyi yapýyoruz. Bu durumda iki þýk vardýr. Derece ya ilkten büyük ya da küçük olmalýdýr.
			Eðer büyükse yer deðiþtiriyoruz. Eðer küçükse aþaðýdaki else bölümünde eklenecek*/
			else if(ilk->derece < yeni->derece){
			yeni->sonraki=ilk;
			ilk=yeni;			
			}
			/*Þimdi buraya kadar iyi de bir kýsmý atladým. Örneðin önce 4 sonra 7 ve sonra 2 ve en sonunda 5 ekledik diyelim. 
			Ýlk=4 olacak 7 eklenince ilk=7 ve ilk->sonraki=4 olacak ancak 2 eklenince 2 yi nereye koyacaðýz. Yani 
			karýþýk bir konu bu sebeple tüm düðümleri gezecek gecici adlý düðümlerimiz var. Ýlkten büyük olmayan her sayý
			bu yöntemle eklenecek*/
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
			/*Sýralý ekleme tamamdýr. Menuye geri dönelim*/
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
		printf ("Aranan deðer bulunamadý.");
		break;
		case 1:	
		if(bul==ilk){
			printf ("\nAranan deðer bulundu!\n%x adresindeki sayý silindi.\n",gecici);
			ilk=ilk->sonraki;
			free(bul);
		}
		else{
			printf ("\nAranan deðer bulundu!\n%x adresindeki sayý silindi.\n",gecici);
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
	/*Eðer sondaki deðer (a) 1 ise ekrana yazdýrýyor 2 ise dosyaya yazdýrýyor*/
	if(a==1){
		if (ilk==NULL){
		printf("Liste boþ");
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
		printf("Liste boþ");
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
		/*Þimdi kullanýcýnýn eriþip gelen 
		sayýyý 1 yada 2 dýþýnda bir þey yapmasý 
		imkansýz ama bu kodu inceleyen birisi kod üzerinde
		deðiþiklik yaparsa hatayý alacak.*/ 
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
	printf("Sonuç: %d",sonuc);
	menu(ilk);
}
int main(){
setlocale (LC_ALL, "Turkish");
struct Dugum* ilk=NULL;
	menu(ilk); /*Menuyu main içerisinde de yazabilirdik 
	ancak ben sürekli her iþlemden sonra menüye dönmesini
	istiyorum goto kullanarak da pek saðlýklý olmuyor. Bu sebeple 
	menu ayrý bir fonksiyon olarak yazýldý.*/
}
void menu(struct Dugum* ilk){
	int a;
	int xkatsayi, xderece;
	printf ("Hangi iþlemi yapmak istiyorsunuz?\n1-Ekleme\n2-Çýkarma\n3-Yazdýrma\n4-Hesaplama\n5-Çýkýþ\n");
	scanf("%d",&a);
		switch(a){
			int x;
			case 1:
				printf("Eklenecek sayýnýn derecesini giriniz: ");
				scanf("%d",&xderece);
				printf("Eklenecek sayýnýn katsayýsýný giriniz: ");
				scanf("%d",&xkatsayi);
				ekleme(xderece,xkatsayi,ilk);
				break;
			case 2:
				printf("Çýkarmak istediðiniz deðiþkenin katsayýsýný giriniz: ");
				scanf("%d",&xkatsayi);
				printf("Çýkarmak istediðiniz deðiþkenin derecesini giriniz: ");
				scanf("%d",&xderece);
				cikarma(xderece,xkatsayi,ilk);
				break;
			case 3:
				printf("Fonksiyonunuz: ");
				yazdirma(ilk,1);
				break;
			case 4:
				printf("x deðiþkenini giriniz: ");
				scanf("%d",&x);
				hesaplama(ilk,x);
				break;
			case 5: 
				yazdirma(ilk,2);//yazdirma fonksiyonuna gidiyor.
				exit(1);
				break;
		}
}
/* Her þey tamam */

