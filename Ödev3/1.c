/*								*****
								*###*
								*#?#*
								*###*
								***** 																	Seklini ekrana yazdirin
*/
#include <stdio.h>
int main(){
	int matrix[5][5];
	for(int i=0 ; i<5 ; i++){
		for(int j=0 ; j<5 ; j++)
		matrix[i][j]='*';
	}
	for(int k=1 ; k<4 ; k++){
		for(int l=1 ; l<4 ; l++)
		matrix[k][l]='#';
	}
	matrix[2][2]='?';
	for(int i=0 ; i<5 ; i++){
		for(int j=0 ; j<5 ; j++)
		printf("%c",matrix[i][j]);
		printf("\n");
	}
}
// Created by MURABIT-PASHA
