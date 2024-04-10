#include <stdio.h>

void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

// calling heapify for every phase
void heapify(int arr[],int size,int i){      // i -> stores index of parent node 
    int max = i;
    int l = 2*i+1;
    int r = 2*i+2;

    // assign max to the left or right value accordingly 
    if(l<size && arr[l] > arr[max]){
        max = l;
    }if(r<size && arr[r] > arr[max]){
        max = r;                     
    }if(max != i){
        swap(&arr[i],&arr[max]);    //  max value in of parent is replaced by min value of its child
        heapify(arr,size,max);
    }
}

// Main function to do heap sort
void heapSort(int arr[],int size){
    for(int i = size/2-1 ; i>=0 ; i--){        // this loop is used to build the initial max heap from the given array. This loop runs only once and serves the purpose of creating the initial heap structure.
        heapify(arr,size,i);
    }
    for(int i = size-1 ; i>=0 ; i--){
        swap(&arr[0],&arr[i]);
        heapify(arr,i,0);
    }
}
/*    for loop 2 in heapSort
The second for loop (from size - 1 to 0) repeatedly extracts elements from the heap.
In each iteration, it swaps the root element (maximum element) with the last element in the heap.
After swapping, it reduces the heap size (passing i as the new size) and calls heapify to maintain the max heap property.
This process effectively places the maximum element at the end of the array, building a sorted array segment in ascending order from the end towards the beginning.

*/ 
int main(){
    int arr[] = {6,14,3,26,8,18,21,9,5};
    int size = sizeof(arr)/sizeof(arr[0]);
    printf("Heap Sort: ");
    for(int i = 0 ; i<size ; i++){
        printf("%d ",arr[i]);
    }
    heapSort(arr,size);
    printf("\nAfter Heap Sort: ");
    for(int i = 0 ; i<size ; i++){
        printf("%d ",arr[i]);
    }
    return 0;
}