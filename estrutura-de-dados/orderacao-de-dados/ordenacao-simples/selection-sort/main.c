
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printVector(int vector[], int length);
void selectionSort(int vector[], int length);
int searchMinValue(int vector[],int initVec,int totalLength);
void swapValues(int* value1, int* value2);

int main(){
    int length=8;
    int vector[]={4,6,3,1,2,9,1,7};

    printVector(vector,length);
    printf("fim print \n");
    selectionSort(vector,length);
    printVector(vector,length);
    printf("fim");
    system("pause");
    return (0);
}
//
void printVector(int vector[], int length){
    for(int position=0; position < length; position++){
        printf("%d \n", vector[position]);
    }
}

void selectionSort(int vector[], int length){
    for(int currentPosition=0;currentPosition<(length);currentPosition++){
        printf("%d vez\n",(currentPosition+1));
        int minValuePosition=currentPosition;

        minValuePosition=searchMinValue(vector,currentPosition,length);

        //if(vector[minValuePosition] < vector[currentPosition]){
            swapValues(&vector[minValuePosition],&vector[currentPosition]);
        //}
    }
} 
//
int searchMinValue(int vector[],int initVec,int totalLength){
    int minValuePosition=initVec;
    for(int cont=1;initVec<totalLength;initVec++,cont++){
        printf("%d procura\n",cont);
        if(vector[initVec]<vector[minValuePosition]){
            minValuePosition=initVec;
        }
    }
    return (minValuePosition);
}

void swapValues(int *value1, int *value2){
    int aux=*value1;
    *value1=*value2;
    *value2=aux;
}