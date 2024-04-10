#include <stdio.h>
int BinarySearch(int arr[], int target, int s, int e);

int main(){
    int target,s,e,size;
    size = 10;
    s = 0;e = size -1;
    target = 7;
    int arr[] = {1,2,3,4,5,6,7,8,9};
    int x = BinarySearch(arr,target,s,e);
    printf("Position of element %d: %d\n",target,x);
    return 0;
}

int BinarySearch(int arr[], int target,int s,int e){
    if(s>e){
        return -1;
    }
    int m = s+(e-s)/2;      
    if(arr[m]==target){
        return m;
    }
    if(arr[m] < target){
        return BinarySearch(arr,target,m+1,e);
    }
    else{
        return BinarySearch(arr,target,s,m-1);
    }
}
