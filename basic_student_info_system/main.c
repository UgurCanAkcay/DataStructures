#include <stdio.h>
#include <stdlib.h>

typedef struct OgrenciBilgisi
{
    char Ad[100];
    char Soyad[100];
    int Numara;

    char Bolum[100];
    int Sinif;

    struct OgrenciBilgisi *frontside;
    struct OgrenciBilgisi *backside;
}
NODE;
NODE *bas = NULL, *son = NULL;

    void writeS(NODE *yazilacak)
{   printf("Ad : %s // Soyad : %s // Numara: %d // Bolum : %s // Sinif : %d \n", yazilacak->Ad,yazilacak->Soyad,yazilacak->Numara,yazilacak->Bolum,yazilacak->Sinif);}

int ekle(NODE *dataPtr)
{
    if (bas != NULL){
    son->backside = dataPtr;
     dataPtr->frontside= son;
     son = dataPtr;
     son->backside = NULL;
    }
    else{
        bas = dataPtr;
        son = dataPtr;
        bas->backside= NULL;
        bas->frontside= NULL;
            }
return 0;
}

int listele()
{
    NODE *p;
    p = bas;

    if (p == NULL) return -1;

    while (p)
    {
        writeS(p);
        p = p->backside;
    }
return 0;
}
NODE *arama(int aranan)
{
    NODE *p;
    p = bas;

    while (p != NULL)
    {
        if (aranan == p->Numara)
            return p;
        p = p->backside;
    }
return NULL;
}
NODE *silme(int silinen)
{
    NODE *p;
    p = arama(silinen);
    if (p == NULL)
        return NULL;
    if (bas == p)
    {if (bas->backside != NULL)
        {bas = p->backside;
            bas->frontside = NULL;
        }
        else
        {bas = NULL;
            son = NULL;}
    }
    else
    {
        p->frontside->backside = p->backside;
        if (p == son)
            son = son->frontside;
        else
            p->backside->frontside = p->frontside;
    }
    free(p);
return p;
}

int menu()
{
    int i;
    printf("\n-----------*MENU*--------------\n");
    printf(" \n (1) Listeye ogrenci ekleme \n (2) Listede ogrenci arama \n (3) Ogrencileri listeleme \n (4) Ogrenci bilgilerini silme \n (5) Sistemten cikis yapiliyor \n");

    do
    {printf("\nSECIMINIZ : ");
        scanf("%d", &i);
        printf("\n");
    }while (i<1 || i>7);

return i;
}

NODE *readKey()
{
    NODE *girilen;
    girilen = (NODE *) malloc(sizeof(NODE));

    if (girilen == NULL)
return NULL;

    printf("Lutfen adi giriniz:  ");
    scanf("%s", girilen->Ad);
    printf("Lutfen soyadi giriniz:  ");
    scanf("%s", girilen->Soyad);
    printf("Lutfen  ogrenci numarasini giriniz  :"); // sadece  sayi giriniz
    printf("Lutfen bolumu giriniz:  ");
    scanf("%s", girilen->Bolum);
    printf("Lutfen sinifi giriniz:  ");
    scanf("%d",&(girilen->Sinif));

return girilen;
}
int main (){

    NODE *eklenecek, *dataPtr;
    int Numara, sonuc, secim;
    while (1)
    {
        secim = menu();
        switch (secim)
        {
        case 1:
                eklenecek = readKey();
            if (eklenecek != NULL)
                ekle(eklenecek);
            else
                printf("Ekleme yapilamiyor,bellek dolu! \n");
            break;
        case 2:
                printf("Aranmasi istenilen ogrenci numarasi \n");
                scanf("%d",&Numara);

            dataPtr = arama(Numara);
            if (dataPtr == NULL)
                printf("Belirtilen ogrenci bulunamamistir! \n");
            else
                writeS(dataPtr);
            break;
        case 3:
            sonuc = listele();
            if (sonuc == -1)
                printf("Liste Bos!!!\n");
            break;
        case 4:
                printf("Silmek istediginiz ogrenci numarasi \n");
                scanf("%d",&Numara);
            dataPtr = silme(Numara);
            if (dataPtr != NULL)
                printf("Ogrenci kaydi silinmistir! \n\n");
            else
                printf("Silmek istediginiz ogrenci listede bulunmamaktadir! \n \n");
            break;
        case 5:
            puts(" Sistemden Cikis Yapildi... \n");

            exit(0);
        }
    }
    return 0 ;
}
