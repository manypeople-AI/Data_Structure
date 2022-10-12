#include <stdio.h>
#include <stdlib.h>

#define MAX_TERMS 101 // terms 안에 항의 총개수가 MAX_TERM을 넘지만 않으면 많은 다항식 저장 가능

typedef struct { //구조체 만들기
    float coef;
    int expon;
}polynomial; // 새로운 type의 데이터 생성

polynomial terms[MAX_TERMS] = {{8,3}, {7,1}, {1,0}, {10,3}, {3,2}, {1,0}}; // 배열 생성
int avail = 6; // 현재 비어있는 요소의 인덱스

// 두개의 정수를 비교
char compare(int a, int b){
    if (a>b) return '>';
    else if (a == b) return '=';
    else return '<';
}

// 새로운 항을 다항식에 추가한다.
// 덧셈의 결과를 추가해야함.
void attach(float coef, int expon){
    if (avail>MAX_TERMS){
        fprintf(stderr, "항의 개수가 너무 많음\n");
        exit(1);
    }
    terms[avail].coef = coef;
    terms[avail].expon = expon;
    avail++;
}

void poly_add(int As, int Ae, int Bs, int Be, int *Cs, int *Ce){
    float tempcoef;
    *Cs = avail; // cs의 포인터가 가리키는 주소가 avail 
    // * 연산자는 포인터가 가리키는 장소에 값을 저장하는 연산자 Cs가 가리키는 장소에 avail 저장
    while (As<=Ae && Bs<=Be){ 
        switch (compare(terms[As].expon, terms[Bs].expon)){ //A의 시작과 B의 시작값의 차수 비교
            case '>': //A의 차수 > B의 차수
                attach(terms[As].coef, terms[As].expon);
                As++;   break;
            case '=': //A의 차수 = B의 차수
                tempcoef = terms[As].coef+terms[Bs].coef;
                if (tempcoef){ //계수가 0일때는 빼려고?
                    attach(tempcoef, terms[As].expon);
                }
                As++;
                Bs++;   break;
            case '<': //A의 차수 < B의 차수
                attach(terms[Bs].coef, terms[Bs].expon);
                Bs++;   break;
        }
        // As<=Ae 와 Bs<=Be 조건을 모두 만족하지 않으면 while문 나오기 때문에
        // 그런 경우 남아있는 것들을 넘겨주어야한다
        for (;As<=Ae;As++){
                attach(terms[As].coef, terms[As].expon);
        }
        for (;Bs<=Be;Bs++){
            attach(terms[Bs].coef, terms[Bs].expon);
        }
        *Ce = avail-1; //ce는 avail -1을 가리킴
}





























