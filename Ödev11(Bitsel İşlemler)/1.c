#include <stdio.h>
#include <locale.h>
int LeftRotate(int num , int step){
	unsigned short LeftShift,RightShift,LeftRotateShift;
	LeftShift = num << step;
	RightShift = num >> (16-step);
	LeftRotateShift = LeftShift | RightShift;
	return(LeftRotateShift);
}
int main(){
	setlocale(LC_ALL, "Turkish");
	int num, step;
	unsigned short int result;
	printf ("Bir sayi giriniz: ");
	scanf("%d",&num);
	printf("Kac adim Left Rotated Shift edilecek: ");
	scanf("%d",&step);
	step=step%16;
	result = LeftRotate(num,step);
	printf ("Left Rotate Shift Sonucu: %hu",result);
	return 0;
}
// Created by MURABIT-PASHA