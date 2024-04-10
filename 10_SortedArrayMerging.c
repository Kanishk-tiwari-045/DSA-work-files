#include <stdio.h>

void mergeSortedArrays(int arr1[], int size1, int arr2[], int size2);

int main() {
    int a, b;     // size of array a and b
    printf("Enter value of size of a and b: \n");
    scanf("%d %d", &a, &b);

    int arr1[a], arr2[b];

    printf("Enter values for arr 1\n");
    for (int i = 0; i < a; i++) {
        scanf("%d", &arr1[i]);
    }

    printf("Enter values for arr 2\n");
    for (int i = 0; i < b; i++) {
        scanf("%d", &arr2[i]);
    }

    mergeSortedArrays(arr1, a, arr2, b);

    return 0;
}

void mergeSortedArrays(int arr1[], int size1, int arr2[], int size2) {
    int i = 0, j = 0, k = 0;
    int s = size1 + size2;
    int merged[s];

    while (i < size1 && j < size2) {
        if (arr1[i] < arr2[j]) {
            merged[k++] = arr1[i++];
        } else {
            merged[k++] = arr2[j++];
        }
    }

    while (i < size1) {
        merged[k++] = arr1[i++];
    }

    while (j < size2) {
        merged[k++] = arr2[j++];
    }

    printf("Merged Array: ");
    for (int i = 0; i < k; i++) {  // Print only merged elements
        printf("%d ", merged[i]);
    }
    printf("\n");
}


/*
2 6 10 15
3 5 8 9 
*/