#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
	//5. Biti sifir ise 4. biti bir olacak
	//5. Biti bir ise 3. biti sifir olacak
	FILE *fp1 = fopen("Sayilar0.txt","w+");
	FILE *fp2 = fopen("Sayilar1.txt","w+");
	srand(time(NULL));
	int num;
	printf ("BU PROGRAM RASTGELE OLUSTURULAN SAYILARI\nBESINCI BITLERININ DURUMUNA GORE DOSYALARA YAZDIRIR.");
	for (int i=0 ; i<100 ; i++){
		num=rand()%100+1;
		printf("%d. say�: %d\n",i+1,num);
		if(num&1<<5){
			num&~(1<<3);
			printf("5. Biti 1 oldugu icin sayi %d oldu.\n",num);
			fprintf(fp1,"%d	",num);
		}
		else{
			num|=(1<<4);
			printf("5. Biti 0 oldugu icin sayi %d oldu.\n",num);
			fprintf(fp2,"%d	",num);
		}
	}
	fclose (fp1);
	fclose (fp2);
// 0110 0010 1111 1010
// 1111 0101 0001 1101
// 1001 1010 1110 0000
	return 0;
}
// Created by MURABIT-PASHA