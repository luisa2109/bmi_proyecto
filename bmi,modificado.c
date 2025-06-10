#include <stdio.h>

int main() {
    float peso, altura, bmi;

    printf("Ingrese el peso en kg: ");
    scanf("%f", &peso);

    printf("Ingrese la altura en metros: ");
    scanf("%f", &altura);

    if (altura <= 0) {
        printf("Error: la altura debe ser mayor a 0.\n");
        return 1;
    }

    bmi = peso / (altura * altura);

    printf("\nSu índice de masa corporal es: %.2f\n", bmi);
    printf("\nÍndice\t\t| Condición\n");
    printf("-------------------------------\n");

    if (bmi < 18.5) {
        printf("<18.5\t\t| Bajo peso\n");
        printf("Usted se encuentra en la categoría: Bajo peso\n");
    } else if (bmi < 25.0) {
        printf("18.5 a 24.9\t| Normal\n");
        printf("Usted se encuentra en la categoría: Normal\n");
    } else if (bmi < 30.0) {
        printf("25.0 a 29.9\t| Sobrepeso\n");
        printf("Usted se encuentra en la categoría: Sobrepeso\n");
    } else {
        printf(">=30\t\t| Obesidad\n");
        printf("Usted se encuentra en la categoría: Obesidad\n");
    }

    return 0;
}
