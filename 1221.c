#include <stdio.h>
#include <math.h>

int primo(int y){    
    for(int i = 2; i<sqrt(y);i++){
        if(y%i == 0){
            return 0;
        }
    }
    return 1;
}

int main(){
    int calculo, N;
    scanf("%d", &calculo);

    for(int i = 0; i<calculo;i++){

        scanf("%d", &N);
        if(N == 1 || N == 2 ){
            printf("Prime\n");
        }else if(N%2 ==0){
            printf("Not Prime\n");
        }else if(primo(N) == 0){
            printf("Not Prime\n");
        }else{
            printf("Prime\n");
        }
    }
    
    return 0;
}