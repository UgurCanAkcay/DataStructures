#include <stdio.h>

int uzunluk(char [], int);
int main()
{
    char kelime[20];
    int count;

    printf("Uzunlugunu bulmak istediginiz sozcugu giriniz: ");
    scanf("%s", kelime);
    count = uzunluk(kelime, 0);
    printf("%s , Kelimesindeki karakter sayisi %d.\n", kelime, count); //kelimedeki karakter sayisini yazar
    return 0;
}

int uzunluk(char kelime[], int indeks)
{
    if (kelime[indeks] == '\0')  //sonlandiricida bitirir
    {
        return 0;
    }
    return (1 + uzunluk(kelime, indeks + 1));
}
