#include <stdio.h>
#define size 100

void merge(int arr[], int start, int mid, int end);
void merge_sort(int arr[], int start, int end);

int main(){
    int i;
    int arr[] = {55,22,99,37,93,15};
    int s = sizeof(arr)/sizeof(arr[0]);

    merge_sort(arr, 0, s - 1);

    printf("\n The sorted array is: \n");
    for (i = 0; i < s; i++)
        printf(" %d\t", arr[i]);

    return 0;
}

void merge(int arr[], int start, int mid, int end)
{
    int i = start;
    int j = mid + 1;
    int index = start;
    int temp[size];
    int k;                         
    // till know we have got two halfs having sorted elements in both of them 

    while ((i <= mid) && (j <= end)) {        // selecting elements from both halves to select smallest and enter value into temp array
        if (arr[i] < arr[j])
        {
            temp[index++] = arr[i++];
        }
        else
        {
            temp[index++] = arr[j++];
        }
    }
    while (j <= end){                          // remaining elements from right half 
        temp[index++] = arr[j++];
    }
    
    while (i <= mid){                          // remaining elemtn from left half 
        temp[index++] = arr[i++];
    }

    for (k = start; k < index; k++)
        arr[k] = temp[k];
}

void merge_sort(int arr[], int start, int end)
{
    int mid;
    if (start < end)
    {
        mid = (start + end) / 2;
        merge_sort(arr, start, mid);
        merge_sort(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }
}
