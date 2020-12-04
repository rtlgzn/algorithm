#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <conio.h>
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
            shell(n, mass);
            for (int i = 0; i < n; i++)
                printf("%d ", mass[i]);
            printf("\n");
    free(mass);
    getch();
    return 0;
}
