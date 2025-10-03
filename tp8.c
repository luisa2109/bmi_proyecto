/*
 * tp8.c - Uso de punteros en lenguaje C
 * https://github.com/luisa2109/bmi_proyecto/tree/main
 */

#include <stdio.h>
#include <stdlib.h>
#define TAM 20


int cuantas_piezas(int);
int rectificable(float, float);
int rechazada(float, float);
void cargar_piezas(float *, int);
int contar(int (*)(float, float), float, float *, int);
float* reservar_memoria(int);
void segregar(int (*)(float, float), float, float *, int, float *);
void mostrar_piezas(char *, float *, int);

int main (void) {
    float diametros[TAM] = {0};
    int n;
    float max = 12;
    float min = 10;

    n = cuantas_piezas(TAM);
    cargar_piezas(diametros, n);

    int n_rectificar = contar(rectificable, max, diametros, n);
    float *p_rectificables = reservar_memoria(n_rectificar);
    segregar(rectificable, max, diametros, n, p_rectificables);

    int n_rechazar = contar(rechazada, min, diametros, n);
    float *p_rechazadas = reservar_memoria(n_rechazar);
    segregar(rechazada, min, diametros, n, p_rechazadas);

    mostrar_piezas("Piezas rectificables", p_rectificables, n_rectificar);
    mostrar_piezas("Piezas rechazadas", p_rechazadas, n_rechazar);

    free(p_rectificables);
    free(p_rechazadas);

    return 0;
}


int cuantas_piezas(int max) {
    int n;
    do {
        printf("Cuántas piezas ingresará? ");
        scanf("%d", &n);
    } while (n < 0 || n > max);
    return n;
}

int rectificable(float diametro, float valor) {
    return (diametro > valor) ? 1 : 0;
}

int rechazada(float diametro, float valor) {
    return (diametro < valor) ? 1 : 0;
}


void cargar_piezas(float *p, int n) {
    for (int i = 0; i < n; i++) {
        float d;
        do {
            printf("Ingrese diámetro de pieza %d: ", i);
            scanf("%f", &d);
            if (d <= 0) {
                printf("Error. El diámetro debe ser positivo.\n");
            }
        } while (d <= 0);
        *(p+i) = d;  
    }
}

int contar(int (*criterio)(float, float), float valor, float *p, int n) {
    int c = 0;
    for (int i = 0; i < n; i++) {
        if (criterio(*(p+i), valor)) {
            c++;
        }
    }
    return c;
}

float* reservar_memoria(int n) {
    float *q = (float*) malloc(n * sizeof(float));
    if (q == NULL && n > 0) {
        printf("Error: no se pudo reservar memoria.\n");
        exit(1);
    }
    return q;
}

void segregar(int (*criterio)(float, float), float valor, float *p, int n, float *q) {
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (criterio(*(p+i), valor)) {
            *(q+j) = *(p+i);
            j++;
        }
    }
}

void mostrar_piezas(char *mensaje, float *p, int n) {
    printf("\n%s:\n", mensaje);
    for (int i = 0; i < n; i++) {
        printf("Diámetro: %.2f\n", *(p+i));
    }
}
