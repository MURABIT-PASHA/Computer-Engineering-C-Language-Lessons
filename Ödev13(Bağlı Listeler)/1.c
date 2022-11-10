#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
struct Node{
	int numb;
	struct Node *next;
};
int main(){
	int a;
	char b;
	struct Node *first=NULL;
	struct Node *ptr=NULL;
	struct Node *temporary=NULL;
do{
	printf("Bir sayi gir: ");
	scanf("%d",&a);
	if (first==NULL){
		first = (struct Node*) malloc(sizeof(struct Node));
		first->numb=a;
		first->next = NULL;
		ptr = first;
	}
	else{
		ptr->next = (struct Node*) malloc(sizeof(struct Node));
		ptr = ptr->next;
		ptr->numb = a;
		ptr->next = NULL;
	}
	temporary=first;
	printf("Devam edilsin mi?(E/H)");
	b=getch();
	system("CLS");
}while(b=='E' || b=='e');
		while(temporary!=NULL){
		printf("Adresi: %x Degeri: %d Sonraki Adresi: %x\n",
		temporary,temporary->numb,temporary->next);
		temporary = temporary->next;
	}
	return 0;
}
// Created by MURABIT-PASHA