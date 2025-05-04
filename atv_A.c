#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_APOSTA 300

int Rand(int N){
    return rand() % (N + 1);
}

float calcularRateio(int ficha1, int ficha2, float aposta){
    if (ficha1 == 0 && ficha2 == 0){
        return 0; // Branca + Branca
    } else if ((ficha1 == 0 && ficha2 == 1 ) || (ficha1 == 1 && ficha2 == 0)) {
        return aposta / 2;
    } else {
        return aposta * 2;
    }
}

int main(){
    int numApostadores;
    float aposta, valorRecebido;
    int ficha1, ficha2;

    srand(time(NULL));

    printf("Informe a quantidade de apostadores (entre 1 e 200):");
    scanf("%d", &numApostadores);

    if(numApostadores < 1 || numApostadores > 200) {
        printf("Quantidade de apostadores inválida. O valor dever ser entre 1 e 200. \n");
        return 1;
    }

    for (int i = 1; i <= numApostadores; i++){
        printf("\n Apostador %d, informe o valor da aposta (R$): ", i);
        scanf("%f", &aposta);

        if (aposta < 0 || aposta > MAX_APOSTA){
            printf("Valor da aposta inválido. O valor deve ser entre 0 e R$ 300,00. \n");
            return 1;
        }

        ficha1 = Rand(1);
        ficha2 = Rand(1);

        valorRecebido = calcularRateio(ficha1, ficha2, aposta);

        printf("Primeira Ficha: %s\n", ficha1 == 0 ? "Branca" : "Preta");
        printf("Segunda Ficha: %s\n", ficha2 == 0 ? "Branca" : "Preta");
        printf("Aposta: R$ %.2f\n", aposta);
        printf("Valor Recebido: R$ %.2f\n", valorRecebido);
    }

    return 0;
}