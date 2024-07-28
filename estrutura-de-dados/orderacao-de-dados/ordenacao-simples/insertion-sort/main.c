
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printVector(int vector[], int length);
void insertionSort(int vector[], int length);
void searchMinValue(int vector[],int currentPosition,int totalLength);
void swapValues(int* value1, int* value2);

int main(){
    int length=9;
    int vector[]={4,6,3,4,1,2,9,1,7};

    printVector(vector,length);
    printf("end print \n");
    insertionSort(vector,length);
    printVector(vector,length);
    printf("end");
    system("pause");
    return (0);
}
//
void printVector(int vector[], int length){
    for(int position=0; position < length; position++){
        printf("%d \n", vector[position]);
    }
}

void insertionSort(int vector[], int length){
    for(int currentPosition=0,nextPosition=1;
        currentPosition<(length-1);
            currentPosition++,nextPosition++){

        printf("turn %d\n",(currentPosition+1));
        
        if(vector[currentPosition]>vector[nextPosition]){
            swapValues(&vector[currentPosition],&vector[nextPosition]);
        }
        searchMinValue(vector,currentPosition,length);
    }
}

void searchMinValue(int vector[],int currentPosition,int totalLength){
    int backPosition=currentPosition-1;
    while (currentPosition > 0 &&
        vector[currentPosition]<vector[backPosition]) {
            
        swapValues(&vector[currentPosition],&vector[backPosition]);
        --currentPosition;
        --backPosition;
    }
    
}

void swapValues(int *value1, int *value2){
    int aux=*value1;
    *value1=*value2;
    *value2=aux;
}