#include <stdio.h>
void selectionSort(int arr[],int s);
int main(){
    int size = 6;
    int arr[] = {55,15,55,37,93,15};

    for(int i = 0; i<size ; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    selectionSort(arr,size);

    printf("Sorted array:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
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
}
