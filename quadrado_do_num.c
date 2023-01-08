#include<stdio.h>

float calcular() {
    float num;
    printf("\nDigite um número: ");
    scanf("%f", &num);
    return num * num;
}

int main(){
    float resultado = 0;
    resultado = calcular();
    printf("\nO quadrado do número digitado é %.2f ", resultado);
    return 0;
}
