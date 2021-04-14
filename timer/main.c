#include <stdio.h>
#include <stdlib.h>
#include <time.h>

main(){
    int dizi[500000];
    int i;
    srand(time(NULL));
    clock_t start,end;
    double cpu_time_used;
    start = clock();
    for(i=0;i<500000;i++){
        dizi[i]=(rand()%100);
    }
    for(i=0;i<500000;i++){
        printf("%d\n", dizi[i]);
    }
    end = clock();
    cpu_time_used= ((double) (end - start)) /CLOCKS_PER_SEC;
  printf("Geçen Süre=%.9f saniyedir.", cpu_time_used);//süreleri buradan alıyorum hocam
}
