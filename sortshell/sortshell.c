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

void shell(int n, int mass[]){
int i, j, step;
int tmp;
for (step = n / 2; step > 0; step /= 2)
    for (i = step; i < n; i++){
        tmp = mass[i];
        for (j = i; j >= step; j -= step){
            if (tmp < mass[j - step])
                mass[j] = mass[j - step];
            else
                break;
        }
    mass[j] = tmp;
    }
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
            shell(n, mass);
            printf("%ld", time_stop());
            for (int i = 0; i < n; i++)
                printf("%d ", mass[i]);
            printf("\n");
    free(mass);
    getch();
    return 0;
}
