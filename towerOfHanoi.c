#include <stdio.h>

void towerOfHanoi(int n , char source , char dest, char aux){
    if(n==0){
        return;
    }
    towerOfHanoi(n-1 , source , aux , dest);
    printf("Move disk %d from %c to %c\n",n,source,dest);
    towerOfHanoi(n-1 , aux , dest , source);
}

int main(){
    int n = 3;
    towerOfHanoi(n,'A','B','C');
    return 0;
}