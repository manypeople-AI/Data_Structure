#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct studentTag{
    char name[10];
    int age;
    double gpa;
}student;

int main(){
    student *s;
    // 구조체의 크기? -> 


    printf("%d\n",sizeof(student)); //24
    s = (student *)malloc(sizeof(student));
    if (s == NULL){
        fprintf(stderr,"no memory");
    }
    strcpy(s->name,"park");
    printf("%d\n",sizeof(s->name));//10
    
    
    s->age = 20;
    printf("%d\n",sizeof(s->age));//4
    s->gpa = 4.5;
    printf("%d\n",sizeof(s->gpa));//8
    printf("%d\n",sizeof(*s));
    free(s);
    return 0;

}


