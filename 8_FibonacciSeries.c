#include <stdio.h>

int main(){
    int s = 6;
    int n1,n2,n3;
    n1 = 0;
    n2 = 1;
    printf("%d %d ",n1,n2);
    for(int i = 2; i<s ; i++){
        n3 = n1+n2;
        printf("%d ",n3);
        n1 = n2;
        n2 = n3;

    }
    return 0;
}