#include<stdio.h>
#include<time.h>
#include<stdlib.h>

#define ARRAYSIZE 100

void selectionSortDes(int* array);
void insertionSortAsc(int* array);
void fillArray(int* array);
void printSortedArray(int* array);
int i,j;

main(){
	srand(time(NULL));
	int* array = (int*)malloc(sizeof(int)*ARRAYSIZE);
	
	fillArray(array);
	selectionSortDes(array);
	insertionSortAsc(array);
	printSortedArray(array);
	
}
void fillArray(int* array){
	for(i=0;i<ARRAYSIZE;i++){		
		*(array+i)=rand()%100;
		printf("%d: %d\n",i+1,*(array+i));
	}
}
void printSortedArray(int* array){
	for(i=0;i<ARRAYSIZE;i++){
		printf("%d: %d\n",i+1,*(array+i));
	}
}

void selectionSortDes(int* array){
	int maxValueIndex,temp;
	for(i=0;i<ARRAYSIZE/2;i++){
		maxValueIndex=i;
		for(int j=i+1;j<ARRAYSIZE/2;j++){
			if(*(array+j)>*(array+maxValueIndex)){
				maxValueIndex=j;
			}
		}
		temp=*(array+i);
		*(array+i)=*(array+maxValueIndex);
		*(array+maxValueIndex)=temp;
	}
}

void insertionSortAsc(int* array){
	int temp;
	for(int i=(ARRAYSIZE/2)+1;i<ARRAYSIZE;i++){
		temp = *(array+i);
		j=i-1;
		while(j>=(ARRAYSIZE/2) && *(array+j)>temp){
			*(array+j+1)= *(array+j);
			j--;
		}
		*(array+j+1)=temp;
	}
}
// Created by MURABIT-PASHA