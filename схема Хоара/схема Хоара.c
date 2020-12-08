#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <conio.h>
#include <time.h>
struct timeval tv1,tv2,dtv;

struct timezone tz;

void time_start() 
{ mingw_gettimeofday(&tv1, &tz); }

long time_stop()
{ mingw_gettimeofday(&tv2, &tz);

  dtv.tv_sec= tv2.tv_sec -tv1.tv_sec;

  dtv.tv_usec=tv2.tv_usec-tv1.tv_usec;

  if(dtv.tv_usec<0) { dtv.tv_sec--; dtv.tv_usec+=1000000; }

  return dtv.tv_sec*1000+dtv.tv_usec/1000;
}

void sort(int*arr, int l, int r){
    int i = l, j = r, d, m = arr[(l + r)/2];
    while(i <= j){
        for(; arr[i] < m; i++);
        for(; arr[j] > m; j--);
        if(i <= j){
            d = arr[i];
            arr[i++] = arr[j];
            arr[j--] = d;
        }
    }
    if(l < j) sort(arr, l, j);
    if(i < r) sort(arr, i, r);
}
 
int main(){
    int n;
    printf("input n: ");
    scanf("%d", &n);
    int* mass;
    mass = (int *)malloc(n * sizeof(int));
    printf("input elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &mass[i]);
    time_start();
    sort(mass, 0, n-1);
     printf("%ld", time_stop());
    for (int i = 0; i < n; i++)
        printf("%d ", mass[i]);
    printf("\n");
    free(mass);
    getch();
    return 0;
}
