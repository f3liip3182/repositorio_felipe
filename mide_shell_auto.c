#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void lee_datos(int *array, int n);
void muestra_datos(int *array, int n);

int main(){
    time_t t_1,t_2;
    int N, i, j, aux, salto, cambios;
    int array[500000];
    //largo_array = 500000;
    FILE *sal;
    lee_datos(array, 500000);
    for (N = 0; N <= 500000; N = N + 10000){

        t_1=time(NULL);

        //int array[N];
        for(salto=500000/2;salto!=0;salto = salto/2){
            cambios = 1;
            while (cambios != 0){   
                cambios=0;     
                for(i=salto;i<500000;i++){   
                    if(array[i-salto]>array[i]){
                        aux=array[i];
                        array[i]=array[i-salto];
                        array[i-salto]=aux;
                        cambios++;
                    }
                }
            } 
        }

        t_2=time(NULL);
        printf("N: %d\n", N);
        sal = fopen("salida_aleatorios_shell.csv", "at");
        fprintf(sal,"%d,%d\n", N,(int)difftime(t_2,t_1));
        fclose(sal);
     }
    return 0;
}

void lee_datos(int *array, int n){
    FILE *ent;
    int i;
    int dato;
    ent = fopen("datos_a1_felipe.txt","r");
    for (i = 0; i < n; i++){
        fscanf(ent, "%d", &dato);
        array[i] = dato;
    }
    fclose(ent);
}

void muestra_datos(int *array, int n){
    int i;
    for (i= 0; i <n; i++){
        printf("%d\n", array[i]);
    }
}