#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

int* relativeSortArray(int* arr1,int arr1Size,int* arr2,int arr2Size,int* returnSize){
    int* result=(int*)malloc(sizeof(int)*arr1Size);
    int idx=0;

    for(int i=0;i<arr2Size;i++){
        int x=arr2[i];
        for(int j=0;j<arr1Size;j++){
            if(arr1[j]==x){
                result[idx++]=x;
            }
        }
    }

    int start=idx;

    for(int i=0;i<arr1Size;i++){
        int found=0;
        for(int j=0;j<arr2Size;j++){
            if(arr1[i]==arr2[j]){
                found=1;
                break;
            }
        }
        if(!found){
            result[idx++]=arr1[i];
        }
    }

    for(int i=start;i<arr1Size;i++){
        for(int j=i+1;j<arr1Size;j++){
            if(result[i]>result[j]){
                int tmp=result[i];
                result[i]=result[j];
                result[j]=tmp;
            }
        }
    }

    *returnSize=arr1Size;
    return result;
}

int main() {
    printf("Solution for Relative Sort Array is implemented. Add test cases as needed.\n");
    return 0;
}