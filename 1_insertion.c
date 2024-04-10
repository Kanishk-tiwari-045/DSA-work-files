#include <stdio.h>

int main(){
    int size = 10;
    int arr[size];
    int val,indx;
    printf("Enter value to be inserted: ");
    scanf("%d",&val);  

    printf("Enter position: ");
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
    int i = size-1;
    size = size+1;
    while(i>=indx-1){
        arr[i+1] = arr[i];
        i--;
    }

    arr[indx-1] = val;

    for(int i = 0; i<size ; i++){
        printf("%d ", arr[i]);
    }printf("\n");
    return 0;
}

