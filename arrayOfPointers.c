#include <stdio.h>

int main(){
    int a[] = {100,206,300,409,509,601};
    int *p[] = {a,a+1,a+2,a+3,a+4,a+5};
    int **pp = p;
    pp++;
    printf("%d %d %d\n",pp-p , *pp-a , **pp);
    *pp++;
    printf("%d %d %d\n",pp-p , *pp-a , **pp);
    ++*pp;
    printf("%d %d %d\n",pp-p , *pp-a , **pp);
    return 0;
}