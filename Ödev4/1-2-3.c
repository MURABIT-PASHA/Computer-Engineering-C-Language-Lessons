#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main (){
	char metin[100], kelime[100];
	int i, j, sayac1=0, sayac2=0, sayac3=0, result=0;
	printf("Metin giriniz: ");
 	gets(metin);

	for (i=0 ; metin[i]!='\0' ; i++)
		if (metin[i]==' ')
		sayac1++;
		printf("Girdiginiz metinde %d kelime var",sayac1+1);
			getch();	


	printf("\nAramak istediginiz kelimeyi giriniz:");
	gets(kelime);
	while(metin[sayac2] != '\0')
	{
	sayac3=0;
	if(metin[sayac2] == kelime[sayac3])
	{
		while(metin[sayac2+sayac3] == kelime[sayac3])
		sayac3++;
		if(kelime[sayac3]=='\0')
			result = 1;
	}
	if(result == 1)break;
	sayac2++;
	}
	if(result)
	printf("Aranan kelime metin icerisinde var");
	else
	printf("Aranan kelime metin icerisinde bulunamadi");
			getch();
			
 	int fark='a'-'A';
 	for (int k=0 ; metin[k]!='\0' ; k++)
 		if(metin[k]>'Z'){
 			 metin[k]-=fark;
 		}
		else{
 			metin[k]+=fark;
		}
		printf("\nYeni metniniz: %s",metin);
	return 0;
}
// Created by MURABIT-PASHA