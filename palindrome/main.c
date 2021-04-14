#include <stdio.h>
#include <string.h>

void kontrolPal(char [], int);

int main()
{
    char kelimePal[25];
    printf("\n\n Hadi bakalim kelimen palindrome mu!!! \n");
    printf("( Palindrome: sagdan sola veya soldan saga ayni okunan kelimelere denir.)\n");
	printf("--------------------------------------------------------------------------\n");

    printf(" Hadi bakalim Palindrome olup olmadigini ogrenmek istedigin kelimeyi yaz : ");
    scanf("%s", kelimePal);
    kontrolPal(kelimePal, 0);//Palindrome olup olmadigini kontrol icin cagri

    return 0;
}

void kontrolPal(char kelimePal[], int index) //karsilastirma icin
{
    int len = strlen(kelimePal) - (index + 1);
    if (kelimePal[index] == kelimePal[len])
    {
        if (index + 1 == len || index == len)
        {
            printf(" Iste bu palindrome :) \n\n");
            return;
        }
        kontrolPal(kelimePal, index + 1);// recursive icin cagri
    }
    else
    {
        printf(" E bu palindrome degil :(  \n\n");
    }
}

