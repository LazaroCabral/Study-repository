
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printVector(int vector[], int length);
void bubbleSort(int vector[], int length);
void searchMinValue(int vector[],int currentPosition,int totalLength);
void swapValues(int* value1, int* value2);

int main(){
    int length=9;
    int vector[]={4,6,3,4,1,2,9,1,7};

    printVector(vector,length);
    printf("fim print \n");
    bubbleSort(vector,length);
    printVector(vector,length);
    printf("fim");
    system("pause");
    return (0);
}

void printVector(int vector[], int length){
    for(int position=0; position < length; position++){
        printf("%d \n", vector[position]);
    }
}

void bubbleSort(int vector[], int length){
    for(int currentPosition=0;currentPosition<(length-1);currentPosition++){
        printf("%d vez\n",(currentPosition+1));
        searchMinValue(vector,currentPosition,length);
    }
}

void searchMinValue(int vector[],int currentPosition,int totalLength){
    for(int nextPosition=(currentPosition+1);nextPosition<totalLength;nextPosition++){
        if(vector[currentPosition]>vector[nextPosition]){
            swapValues(&vector[currentPosition],&vector[nextPosition]);
        }
    }
}

void swapValues(int *value1, int *value2){
    int aux=*value1;
    *value1=*value2;
    *value2=aux;
}