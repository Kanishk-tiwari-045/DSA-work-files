#include <stdio.h>

int main(){
    int size = 5;
    int arr[size];
    int val,indx;

    printf("Enter position to be deleted: ");
    scanf("%d",&indx);

    printf("Enter values in the array: \n");
    for(int i = 0; i<size ; i++){
        scanf("%d",&arr[i]);
    }
    printf("\n");

    for(int i = 0; i<size ; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
// shifting 
    int i = indx-1;
    while(i<size-1){
        arr[i] = arr[i+1];
        i++;
    }
    --size;
    for(int i = 0; i<size ; i++){
        printf("%d ", arr[i]);
    }printf("\n");
    return 0;
}

