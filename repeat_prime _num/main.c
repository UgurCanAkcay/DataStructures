#include<stdio.h>
void AsalSayi( int sayi);
void TekrarlananAsalSayi( int n);

int main( )
{
    int sayi;
    printf("Lutfen bir sayi giriniz: ");
    scanf("%d", &sayi);
    printf("\nInput: \n");
    AsalSayi(sayi);
    printf("\n");
    printf("\nOutput: \n");
    TekrarlananAsalSayi(sayi);
    printf("\n");
    return 0;

}

void AsalSayi( int sayi)
{
    int i = 2;
    if( sayi == 1 )
        return;
    while( sayi%i != 0)
        i++;
    printf("%d ", i);
    AsalSayi(sayi/i);
}


void TekrarlananAsalSayi( int sayi)
{
    int i;
    for( i = 2; sayi!=1; i++)
        while( sayi%i == 0 )
        {
            printf("%d ", i);
            sayi = sayi/i;
        }
}
