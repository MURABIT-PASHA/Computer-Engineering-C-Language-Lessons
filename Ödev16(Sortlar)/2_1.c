#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<conio.h>

#define ARRAYSIZE 100
int partition (int*,int,int,bool);
void quickSort(int*,int,int,bool);
void swap(int*, int*);

int i,j;

main(){
	srand(time(NULL));
	int* array = (int*)malloc(sizeof(int)*ARRAYSIZE);
	
	for(i=0;i<ARRAYSIZE;i++){		
		*(array+i)=rand()%100;
		printf("%d: %d\n",i+1,*(array+i));
	}
	
	quickSort(array,0,ARRAYSIZE/2-1,true); //true = artan 
	quickSort(array,ARRAYSIZE/2,ARRAYSIZE-1,false); //false =azalan
	
	for(i=0;i<ARRAYSIZE;i++){
		printf("%d: %d\n",i+1,*(array+i));
	}
	
}

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition (int* array, int low, int high, bool asc){
	int pivot = *(array+high);
	i = low-1;
	for (j = low; j < high; j++){
		if(asc){		
			if (*(array+j)<= pivot){
				i++;
				swap(array+i, array+j);
			}
		}
		else{
			if (*(array+j)> pivot){
				i++;
				swap(array+i, array+j);
			}
		}

	}
	swap(array+i+1,array+high);
	return (i + 1);
}

void quickSort(int* array, int low, int high, bool asc){
	if (low < high){
		int part = partition(array, low, high, asc);
		quickSort(array, low, part - 1, asc);
		quickSort(array, part + 1, high, asc);
	}
}
// Created by MURABIT-PASHA
