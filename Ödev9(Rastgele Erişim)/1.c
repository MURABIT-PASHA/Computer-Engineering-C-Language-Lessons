#include <stdio.h>
#include <conio.h>
#include <errno.h>
#define MAX 82
int a=MAX;
struct rectype{
	char track;
	char city[20];
	char platenumb[20];
}record[MAX];
FILE *dd;
int reclong;
long int recpos;
int main(){
	dd=fopen("sehirler.dat","w+");
	printf("Kaydini girmek istediginiz sehir adedi: ");
	scanf("%d",&a);
	fprintf(dd,"%d",a);
		for(int b=0 ; b<a ; b++){
		printf ("%d. Sehrin adini giriniz: ",b+1);
		scanf("%s",record[b].city);
		printf("%d. Sehrin plaka numarasini giriniz: ",b+1);
		scanf("%s",record[b].platenumb);
		record[b].track = '*';
		}
		fwrite(&record,sizeof(record),1,dd);
		fclose(dd);
		printf("Dosya basariyla yazildi");
return 0;
}
// Created by MURABIT-PASHA
