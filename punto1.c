#include <stdio.h>
#include<time.h>
#include<stdlib.h>
#define ANIO 5
#define MES 12

int* gananciapanio(int matriz[ANIO][MES], int*punteroanio);
void maxandmin(int matriz[ANIO][MES], int max, int min);

int main(){
int matriz[ANIO][MES];
int max = 0;
int minimo = 99999999;
int* punteroanio;

    for (int i=0;i<5;i++){
        for(int j=0;j<12;j++){
            matriz[i][j]=rand()%40000+10000;
            printf("%4d  ",matriz[i][j]);
        }
        printf("\n");
    }
    punteroanio=gananciapanio(matriz,punteroanio);
    
    maxandmin(matriz,max,minimo);
    return 0;
}

int* gananciapanio(int matriz[ANIO][MES], int*punteroanio){
    int promedio = 0;
    for(int i=0;i<5;i++){
        int promedio = 0;
        punteroanio[i] = 0;
        for(int j=0;j<12;j++){
        punteroanio[i] += matriz[i][j];
        promedio += matriz[i][j];
        }
        promedio /= 12;
        printf("El promedio de las ganancias por anio en el anio %d es: %d\n",i+1,promedio);
    }

    return(punteroanio);
}

void maxandmin(int matriz[ANIO][MES], int max, int min){
    int aniomaximo;
    int aniominimo;
    int mesmaximo;
    int mesminimo;
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if(matriz[i][j]>=max){
                max=matriz[i][j];
                mesmaximo=j;
                aniomaximo=i;
            }
            if(matriz[i][j]<=min){
                min=matriz[i][j];
                mesminimo=j;
                aniominimo=i;
            }
        }
    }
    printf("La ganancia maxima es %d y se dio el mes %d/%d\n",max,mesmaximo+1,aniomaximo+1);
    printf("La ganancia minima es %d y se dio el mes %d/%d\n",min,mesminimo+1,aniominimo+1);
}