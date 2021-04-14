#include <stdio.h>

int asal(int, int);

int main()
{
    int sayi, kontrol;
    printf("Asal olup olmadigini ogrenmek istediginiz sayiyi giriniz : ");
    scanf("%d", &sayi);
    kontrol = asal(sayi, sayi / 2);
    if (kontrol == 1)
    {
        printf("%d <-- Heey!Bu bir asal sayi :) \n", sayi);
    }
    else
    {
        printf("%d <-- Maalesef,bu bir asal sayi degil :( \n", sayi);
    }
    return 0;
}

int asal(int sayi, int i)
{
    if (i == 1)
    {
        return 1;
    }
    else
    {
       if (sayi % i == 0)
       {
         return 0;
       }
       else
       {
         return asal(sayi, i - 1);
       }
    }
}
