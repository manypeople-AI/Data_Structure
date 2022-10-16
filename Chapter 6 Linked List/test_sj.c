
int main(){
    for(int i=0; ++i <5 ;){ // 1234
        printf("%d",i);
    }
    int i =0;
    while(++i<5){  // i++ -> if (i=1)<5  -> printf 
        printf("%d",i);
    }

    printf("\n");
    for(int i=0; i++ <5 ;){ //12345
        printf("%d",i);
    }
    int i =0;
    while(i++<5){ //if (i=0)<5 -> i++ -> printf 
        printf("%d",i);
    }
}