// Kombinasyon sonucunu yazdiran makine
#include <stdio.h>
int kombin1=1, kombin2=1, kombin3=1, sonuc;
int kombinasyon(int n, int r)
{
for (int i=1 ; i<=n ; i++) //n! almak icin
kombin1=kombin1*i;

for (int j=1 ; j<=n-r ; j++) //(n-r)! almak icin
kombin2=kombin2*j;

for (int k=1 ; k<=r ; k++) // r! almak icin
kombin3=kombin3*k;
sonuc=kombin1/(kombin2*kombin3);
return(sonuc);
}
int main()
{
	int a, b;
	printf("n degerini giriniz : ");
    scanf("%d",&a);
    printf("r degerini giriniz : ");
    scanf("%d",&b);
    kombinasyon(a,b);
    printf ("Kombinasyon sonucu: %d", sonuc);
    
	return 0;
}
// Created by MURABIT-PASHA