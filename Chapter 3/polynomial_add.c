#include <stdio.h>
#define MAX_DEGREE 101

typedef struct{
    int degree;
    float coef[MAX_DEGREE];
}polynomial; //polynomial이라는 새로운 데이터 타입 생성 (int 같은 애라고 생각하고 해나가자)

polynomial polyadd(polynomial a, polynomial b){
    polynomial c; // 결과를 담을 c라는 다항식

    if (a.degree>b.degree){
        int d = a.degree - b.degree;
        c.degree = a.degree;
        for (int i=0; i<d;i++){
            c.coef[i] = a.coef[i];}
        
        for (int i=d;i<=a.degree;i++){
            c.coef[i] = a.coef[i] + b.coef[i];}
    }
    
    else if (a.degree == b.degree){
        for (int i=0;i<=a.degree;i++){
            c.coef[i] = a.coef[i] + b.coef[i];}
    }
    

    else{
        int d = b.degree - a.degree;
        c.degree = b.degree;
        for (int i=0; i<d;i++){
            c.coef[i] = a.coef[i];}
        
        for (int i=d;i<=b.degree;i++){
            c.coef[i] = a.coef[i] + b.coef[i];}
        }

    return c;
}

void print_poly(polynomial p){
    
}





