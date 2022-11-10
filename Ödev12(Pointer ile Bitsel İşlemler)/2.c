#include <stdio.h>
#include <stdlib.h>
main(){
	int numb,*array=NULL, i=1;
	
	while(1==1){
		printf("Say� girin: ");
		scanf("%d",&numb);
		if(numb<0)
		break;
		if(numb%15==0){
			array = (int *)realloc(array,sizeof(int)*i);
			*(array+i-1)=numb;
			printf("\n%d\n",*(array+i-1));
			i++;
		}
	}
}
// Created by MURABIT-PASHA