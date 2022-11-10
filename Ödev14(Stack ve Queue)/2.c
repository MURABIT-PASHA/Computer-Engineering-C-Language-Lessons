#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
struct Node{
	int data;
	struct Node *sonraki;
} *tepe = NULL;

void ekle(int a){
	struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
	newNode->data = a;
	if(tepe == NULL)
		newNode->sonraki = NULL;
	else
		newNode->sonraki = tepe;
	tepe = newNode;
	system("cls");
}
void listele(){
	system("cls");
	if(tepe==NULL)
	printf("Stack bos\n");
	else{
			struct Node *gecici = tepe;
			while(gecici!=NULL){
				printf("%d\n",gecici->data);
				gecici = gecici->sonraki;
			}
	}
	getch();
	system("cls");
}
void bulvesil(int a){
	struct Node *gecici = tepe;
	struct Node *oncesi = tepe;
	if(tepe==NULL)
	printf("Stack bos\n");
	else{
			while(gecici->data!=a){
				oncesi = gecici;
				gecici = gecici->sonraki;		
			}
			if(gecici==tepe){
				tepe = gecici->sonraki;
				free(gecici);
			}else{
				oncesi->sonraki = gecici->sonraki;
				free(gecici);
			}
	}
}

void bulvegoster(int a){
	if(tepe==NULL)
	printf("Stack bos\n");
	else{
		struct Node *gecici = tepe;
			while(gecici!=NULL){
				if(gecici->data == a){
					printf("Bulunan deger: %d ve %x adresindedir.\n",gecici->data,gecici);
					break;
				}
				else
				gecici = gecici->sonraki;	
			}

	}
	getch();
	system("cls");
}
int main(){
	int choice, value;
	while(1){
		printf("1. Ekle\n2. Bul ve Sil\n3. Bul ve Goster\n4. Tumunu Listele\n5. Cikis\n");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				printf("Eklenecek degeri giriniz: ");
				scanf("%d",&value);
				ekle(value);
				break;
			case 2:
				printf("Silinecek degeri giriniz: ");
				scanf("%d",&value);
				bulvesil(value);
				break;
			case 3:
				printf("Bulunacak degeri giriniz: ");
				scanf("%d",&value);
				bulvegoster(value);
				break;
			case 4:
				listele();
				break;
			case 5:
				exit(0);
			default:
				printf("Hatali giris ahbap!");
				exit(0);		
		}
	}
}
// Created by MURABIT-PASHA