#include <stdio.h>
float calcularAreaRectangulo(float longitud, float altura) {
    return longitud * altura;
}

float calcularPerimetroRectangulo(float longitud, float altura) {
    return 2 * (longitud + altura);
}

float calcularDiagonalRectangulo(float longitud, float altura) {
    // Usamos Pitágoras sin sqrt: mostramos la suma de cuadrados
    // porque raíz cuadrada todavía no se vio en las unidades.
    return (longitud * longitud) + (altura * altura);
}

float calcularAreaCirculo(float radio) {
    float PI = 3.14159;   // constante definida a mano
    return PI * (radio * radio);
}

float calcularPerimetroCirculo(float radio) {
    float PI = 3.14159;
    return 2 * PI * radio;
}

void imprimirResultados(float area, float perimetro) {
    printf("\nEl área es: %.2f\n", area);
    printf("El perímetro es: %.2f\n", perimetro);
}

int main() {
    int opcion;
    float longitud, altura, radio;
    float area, perimetro, diagonal;

    do {
        printf("Ingrese la figura que desea calcular (1: rectángulo, 2: círculo): ");
        scanf("%d", &opcion);

        if(opcion != 1 && opcion != 2) {
            printf("Opción inválida. Intente nuevamente.\n\n");
        }
    } while(opcion != 1 && opcion != 2);

    if(opcion == 1) {
        printf("\nOpción de rectángulo seleccionada\n");
        printf("Ingrese la longitud del rectángulo: ");
        scanf("%f", &longitud);
        printf("Ingrese la altura del rectángulo: ");
        scanf("%f", &altura);

        area = calcularAreaRectangulo(longitud, altura);
        perimetro = calcularPerimetroRectangulo(longitud, altura);
        diagonal = calcularDiagonalRectangulo(longitud, altura);

        imprimirResultados(area, perimetro);
        printf("La diagonal al cuadrado del rectángulo es: %.2f\n", diagonal);
        printf("(Recuerda: diagonal^2 = longitud^2 + altura^2)\n");
    }
    else {
        printf("\nOpción de círculo seleccionada\n");
        printf("Ingrese el radio del círculo: ");
        scanf("%f", &radio);

        area = calcularAreaCirculo(radio);
        perimetro = calcularPerimetroCirculo(radio);

        imprimirResultados(area, perimetro);
    }

    return 0;
}
