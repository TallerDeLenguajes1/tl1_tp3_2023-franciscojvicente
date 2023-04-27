#include<stdio.h>
#include<string.h>
#include<stdlib.h>
// #define cantfilas 5

int main(){
    char **punt;
    int cant;
    int cantpalabras;
    printf("Cuantas palabras desea ingresar? ");
    scanf("%d", &cantpalabras);
    punt=(char**)malloc(cantpalabras*sizeof(char*));

    for(int i=0;i<cantpalabras;i++){
        printf("\nIngrese la cantidad de caracteres de la palabra %d: ",i+1);
        scanf("%d",&cant);
        punt[i]=(char*)malloc(cant*sizeof(char));
        printf("\nIngrese la palabra que desea guardar: ");
        fflush(stdin);
        gets(punt[i]);
    }

    for(int j=0;j<cantpalabras;j++){
        printf("\n-----PALABRA %d-----\n",j+1);
        puts(punt[j]);
    }

    for(int k=0;k<cantpalabras;k++){
        free(punt[k]);
    }

    free(punt);
    return 0;
}