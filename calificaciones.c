#include <stdio.h>

int main()
{
   
    int calificacion;

    printf("Ingrese la calificación: ");
    scanf("%d", &calificacion);

    if (calificacion >= 90) {
        printf("Calificación: A\n");
    } else if (calificacion >= 80) {
        printf("Calificación: B\n");
    } else if (calificacion >= 70) {
        printf("Calificación: C\n");
    } else if (calificacion >= 60) {
        printf("Calificación: D\n");
    } else {
        printf("Calificación: F\n");
    }

   
    return 0;
}

//repositorio:https://github.com/luisa2109/bmi_proyecto
