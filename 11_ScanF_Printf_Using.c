#include <stdio.h>

struct Student{
    char name[100];
    int rollno;
};

int main(){
    struct Student ptr;
 
    printf("Enter student name: ");
    gets(ptr.name);
    printf("Enter roll no ");
    scanf("%d",&ptr.rollno);   
    puts(ptr.name);
    printf("%d\n",ptr.rollno);

}

