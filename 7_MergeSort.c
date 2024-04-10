#include <stdio.h>
void ArrayMerging(int a[],int b[],int sa,int sb);
void selectionSort(int arr[],int s);
int main(){
    int a[] = {66,1,2,87,19};
    int b[] = {32,23,4,67,7,91,83};
    int sa = 5;
    int sb = 7;
    ArrayMerging(a,b,sa,sb);
    return 0;
}

void ArrayMerging(int a[],int b[],int sa,int sb){
    int s = sa+sb;
    int mergedArr[s];

    for(int i = 0; i<sa ; i++){
        mergedArr[i] = a[i];
    }
    for(int i = 0; i<s ; i++){
        mergedArr[sa+i] = b[i];
    }
    printf("Merged Array\n");
    for(int i = 0; i<s; i++){
       printf("%d ",mergedArr[i]);
    }
    printf("\n");

    selectionSort(mergedArr,s);
}

void selectionSort(int arr[],int s){
    for(int i = 0 ; i<s-1 ; i++){
        for(int j = i+1; j<s ; j++){
            if(arr[i] > arr[j]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    printf("Merged Sorted Array\n");
    for(int i = 0; i<s; i++){
       printf("%d ",arr[i]);
    }
    printf("\n");
}
