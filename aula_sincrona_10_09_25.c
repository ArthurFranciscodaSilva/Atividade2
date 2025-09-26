
#include <stdio.h>

int main () {

    int A;
    int B;
   
    printf("Digite o valor de A (1 = verdadeiro, 0 = Falso)");
    scanf("%d", &A);

    printf("Digite o valor de B (1 = verdadeiro, 0 = Falso)");
    scanf("%d", &B);

    if(A == B){
        printf("Os valores são iguais");
    }
    else{
        printf("Condição não verdadeira");
    
    }
    return 0;
}


