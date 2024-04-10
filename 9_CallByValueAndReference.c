#include <stdio.h>
void ValueSwap(int a , int b);
void RefereceSwap(int *p1 , int *p2);

int main(){
    int a = 5;
    int b = 3;
    int *ptr1 = &a;
    int *ptr2 = &b;
    printf("Pass by value swap -> a: %d  b:%d\n", a,b);
    ValueSwap(a,b);
    printf("Pass by referecnce swap -> a: %d  b:%d\n", *ptr1,*ptr2);
    RefereceSwap( &a ,  &b);

    return 0;
}

void ValueSwap(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
    printf("a: %d  b:%d\n", a, b);
}
void RefereceSwap(int *p1, int *p2) {
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
    printf("a: %d  b:%d\n", *p1, *p2);
}