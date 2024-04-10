#include <stdio.h>

int main(){
    int a = 80;
    int *p = &a;
    printf("%d\n",p);
    printf("%d\n",*p);
    p = p+2;
    printf("%d\n",p);
    printf("%d\n",*p); 

    char s[] = "Man";
    for(int i = 0 ; s[i] ; i++){
        printf("%c %c %c %c\n",s[i],*(s+i),*(i+s),i[s]);
    }
    return 0;
}