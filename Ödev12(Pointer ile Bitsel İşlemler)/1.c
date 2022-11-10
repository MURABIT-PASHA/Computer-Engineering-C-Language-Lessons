#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int main(){
	int i, numb,*array=NULL;
	FILE *fp;
	srand(time(NULL));
	fp = fopen ("sayi.txt","w");
	if(fopen ("sayi.txt","w")==NULL){
		printf ("Dosya A��lamad�...");
		exit(1);
	}
	for (i=0 ; i<100 ; i++){
		fprintf(fp,"%d\n",rand()%101);
	}
	fclose(fp);
	fp= fopen ("sayi.txt","r");
	i=0;
	printf("5. biti 0 olanlar ([32,63] ve [96,100] arasi olamaz.)\n");
	while(!feof(fp)){
		fscanf(fp,"%d\n",&numb);
		if ((numb & (1<<5))==0){
			i++;
			array = (int*)realloc(array,sizeof(int)*i);
			*(array+i-1)=numb;
			printf("%d\n",*(array+i-1));
		}
	}
	fclose(fp);
	exit(0);
	return 0;
}
// Created by MURABIT-PASHA