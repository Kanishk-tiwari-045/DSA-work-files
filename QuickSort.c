#include <stdio.h>

void swap(int* a, int* b){
	int t = *a;
	*a = *b;
	*b = t;
}

int partition(int arr[], int low, int high){
	int pivot=arr[low];
    int i=low+1;
    int j=high;
    while(i<j){
        while(arr[i]<=pivot){
            i++;
        }
        while(arr[j]>pivot){
            j--;
        }
        if(i<j){
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[low],&arr[j]);
    return j;
}

void quickSort(int arr[], int low, int high)
{
	if (low < high) {
		int pi = partition(arr, low, high);
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}


int main()
{
	int arr[] = { 10, 7, 8, 9, 1, 5 };
	int N = sizeof(arr) / sizeof(arr[0]);

	quickSort(arr, 0, N - 1);
	printf("Sorted array: \n");
	for (int i = 0; i < N; i++)
		printf("%d ", arr[i]);
	return 0;
}


