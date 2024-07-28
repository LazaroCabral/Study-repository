
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printVector(int vector[], int length);
void recursiveShellSort(int vector[], int length, int interval,int startRecursion);
void shellSort(int vector[], int length);
void insertionSort(int vector[], int length, int interval);
void searchMinValue(int vector[],int currentPosition,int totalLength, int interval);
void swapValues(int* value1, int* value2);

int main(){
    int length=9;
    int vector[]={4,6,3,4,1,2,9,1,7};

    printVector(vector,length);
    printf("fim print \n");
    shellSort(vector,length);
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

void recursiveShellSort(int vector[], int length, int interval,int startRecursion){
    if(startRecursion==1){
        interval=(int)length/2;
    } else{
        interval=(int)interval/2;
    }

    if(interval<=0){
        return;
    }
    insertionSort(vector,length,interval);
    recursiveShellSort(vector,length,interval,0);
}

void shellSort(int vector[], int length){
    recursiveShellSort(vector,length,0,1);
}

void insertionSort(int vector[], int length, int interval){
    for(int currentPosition=0, nextPosition=interval;
        nextPosition<=(length-1);
            currentPosition++,nextPosition+=interval){

        printf("%d vez\n",(currentPosition+1));
        
        if(vector[currentPosition]>vector[nextPosition]){
            swapValues(&vector[currentPosition],&vector[nextPosition]);
        }
        searchMinValue(vector,currentPosition,length,interval);
    }
}

void searchMinValue(int vector[],int currentPosition,int totalLength, int interval){
    int backPosition=currentPosition-interval;
    while (currentPosition > 0 && backPosition > 0 &&
        vector[currentPosition]<vector[backPosition]) {
            
        swapValues(&vector[currentPosition],&vector[backPosition]);
        currentPosition-=interval;
        backPosition-=interval;
    }
    
}

void swapValues(int *value1, int *value2){
    int aux=*value1;
    *value1=*value2;
    *value2=aux;
}