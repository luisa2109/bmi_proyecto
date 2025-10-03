/*
 * tp7.c - Gestión de lista de precios y códigos de barra
 * https://github.com/luisa2109/bmi_proyecto
 *
 * Requisitos:
 * - Arreglos paralelos: codigos[] y precios[]
 * - TAM constante simbólica
 * - Código de barras: entero en [1, 999999999]
 * - Precio: real >= 0
 * - Mostrar lista, el más caro (y su código) y el más barato (y su código)
 */

#include <stdio.h>

#define TAM       5              
#define COD_MIN   1
#define COD_MAX   999999999

int main(void) {
    int   codigos[TAM] = {0};
    float precios[TAM] = {0.0f};

    printf("Ingrese %d productos, se solicitará el código y precio:\n\n", TAM);

    for (int i = 0; i < TAM; i++) {
        for (;;) {
            int ok = 0;
            printf("Ingrese el código de barras (%d-%d): ", COD_MIN, COD_MAX);
            ok = scanf(" %d", &codigos[i]);

            if (ok != 1) {
                int c;
                while ((c = getchar()) != '\n' && c != EOF) { }
                printf("Error. Debe ingresar un entero.\n");
                continue;
            }

            if (codigos[i] < COD_MIN || codigos[i] > COD_MAX) {
                printf("Error. El código de barras debe estar entre %d y %d\n", COD_MIN, COD_MAX);
                continue;
            }
            break;
        }
        for (;;) {
            int ok = 0;
            printf("Ingrese el precio: ");
            ok = scanf(" %f", &precios[i]);

            if (ok != 1) {
                int c;
                while ((c = getchar()) != '\n' && c != EOF) { }
                printf("Error. Ingrese un número real (use punto como separador decimal).\n");
                continue;
            }

            if (precios[i] < 0.0f) {
                printf("Error. El precio no puede ser negativo.\n");
                continue;
            }
            break;
        }

        printf("\n");
    }
    
    printf("Código\t\tPrecio\n\n");
    for (int i = 0; i < TAM; i++) {
        printf("%d\t%.2f\n", codigos[i], precios[i]);
    }

    int idx_max = 0, idx_min = 0;
    for (int i = 1; i < TAM; i++) {
        if (precios[i] > precios[idx_max]) idx_max = i;
        if (precios[i] < precios[idx_min]) idx_min = i;
    }

    printf("\nMás caro:   [%d] %.2f\n", codigos[idx_max], precios[idx_max]);
    printf("Más barato: [%d] %.2f\n", codigos[idx_min], precios[idx_min]);

    return 0;
}
