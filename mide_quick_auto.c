#include<stdio.h>
#include <time.h>
#define N 500000

void lee_datos(int *array, int n);

void swap(int* a, int* b){
    int t = *a;
    *a = *b;
    *b = t;
}
 
int particion (int arr[], int bajo, int alto){
    int pivote, i, j;
    pivote = arr[alto];
    i = (bajo - 1);
 
    for (j = bajo; j <= alto- 1; j++){
        if (arr[j] <= pivote){
            i++; 
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[alto]);
    return (i + 1);
}
 
void quickSort(int arr[], int bajo, int alto){
	int pi;
    if (bajo < alto){
        pi = particion(arr, bajo, alto);
        quickSort(arr, bajo, pi - 1);
        quickSort(arr, pi + 1, alto);
    }
}

int main(){
    time_t t_1,t_2;
    int arr[N], i, j;
    j=0;
    int n = N;
    FILE *sal;
    lee_datos(arr, 500000);
    
    for (j; j<=500000; j=j+10000){

        t_1=time(NULL);
        quickSort(arr, 0, n-1);
    }
    t_2=time(NULL);
    printf("N: &d\n", j);
    sal = fopen("salida_ordenados_quick.csv", "at");
    fprintf(sal, "%d,%d\n", j,(int)difftime(t_2,t_1));
    fclose(sal);
    return 0;
}
void lee_datos(int *array, int n){
    FILE *ent;
    int i, dato;
    ent = fopen("datos_o_felipe.txt", "r");
    for (i=0; i<n; i++){
        fscanf(ent, "&d", &dato);
        array[i]=dato;
    }
    fclose(ent);
}