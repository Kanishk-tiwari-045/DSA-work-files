#include <stdio.h>
void BubbleSort(int arr[],int s);
int main(){
    int size = 6;
    int arr[] = {55,22,99,37,93,15};

    for(int i = 0; i<size ; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    BubbleSort(arr,size);

    printf("Sorted array:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}

void BubbleSort(int arr[],int s){
    for(int i = 0 ; i<s ; i++){
        for(int j = 0; j<s-i-1 ; j++){
            if(arr[j+1] < arr[j]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
