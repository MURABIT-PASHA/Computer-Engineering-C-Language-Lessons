#include <stdio.h>
#include <string.h>
#define MAX 82
int firstnumb=MAX;
struct rectype{
	char track;
	char city[20];
	char platenumb[20];
}record[MAX];

int main(){
	char a[5];
	int meter=0;
	FILE *cc=fopen ("sehirler.dat","r+");
	if(cc==NULL){
		printf("Dosya Bulunamadi");
	}
	else{
		printf ("Bulmak istediginiz sehrin plaka numarasini giriniz: ");
		scanf("%s",&a);
		fscanf(cc,"%d",&firstnumb);
		fread(&record,sizeof(record),1,cc);		
				for(int b=0 ; b<firstnumb ; b++){
					if(strlen(a)==strlen(record[b].platenumb)){
						for(int c=0 ; c<strlen(a) ; c++){
							if (a[c]==record[b].platenumb[c]){
								meter++;
								if(strlen(a)==meter)
									printf ("Bulunan sehir: %s",record[b].city);												
							}
						}
					}

				}
	}
	fclose(cc);
return 0;
}
// Created by MURABIT-PASHA