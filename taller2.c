#include <stdio.h>

#define ESTUDIANTES 5
#define ASIGNATURAS 3

int main() {
    [ESTUDIANTES], minEstudiante[ESTUDIANTES];
    float maxAsignatura[ASIGNATURAS], minAsignatura[ASIGNATURAS];
    int aprobados[ASIGNATURAS] = {0}, reprobados[ASIGNATURAS] = {0};

    // Ingreso de calificaciones
    for (int i = 0; i < ESTUDIANTES; i++) {
        printf("\nIngreso de calificaciones para el estudiante %d\n", i + 1);
        for (int j = 0; j < ASIGNATURAS; j++) {
            do {
                printf("Ingrese la calificacion del estudiante %d en la asignatura %d (0 - 10): ", i + 1, j + 1);
                scanf("%f", &calificaciones[i][j]);
                if (calificaciones[i][j] < 0 || calificaciones[i][j] > 10)
                    printf("Error la calificacion debe estar entre 0 y 10.\n");
            } while (calificaciones[i][j] < 0 || calificaciones[i][j] > 10);
        }
    }

    // Cálculo de promedios, maximos y minimos por estudiante
    for (int i = 0; i < ESTUDIANTES; i++) {
        float suma = 0;
        maxEstudiante[i] = minEstudiante[i] = calificaciones[i][0];
        for (int j = 0; j < ASIGNATURAS; j++) {
            suma += calificaciones[i][j];
            if (calificaciones[i][j] > maxEstudiante[i])
                maxEstudiante[i] = calificaciones[i][j];
            if (calificaciones[i][j] < minEstudiante[i])
                minEstudiante[i] = calificaciones[i][j];
        }
        promedioEstudiante[i] = suma / ASIGNATURAS;
    }

    // Cálculo de promedios, máximos, mínimos y aprobados por la asignatura
    for (int j = 0; j < ASIGNATURAS; j++) {
        float suma = 0;
        maxAsignatura[j] = minAsignatura[j] = calificaciones[0][j];
        for (int i = 0; i < ESTUDIANTES; i++) {
            suma += calificaciones[i][j];
            if (calificaciones[i][j] > maxAsignatura[j])
                maxAsignatura[j] = calificaciones[i][j];
            if (calificaciones[i][j] < minAsignatura[j])
                minAsignatura[j] = calificaciones[i][j];
            if (calificaciones[i][j] >= 6)
                aprobados[j]++;
            else
                reprobados[j]++;
        }
        promedioAsignatura[j] = suma / ESTUDIANTES;
    }

    // Muestra los resultados
    printf("\nLos resultados son:\n");

    for (int i = 0; i < ESTUDIANTES; i++) {
        printf("\nEstudiante %d:\n", i + 1);
        printf("Promedio: %.2f\n", promedioEstudiante[i]);
        printf("Maxima calificacion: %.2f\n", maxEstudiante[i]);
        printf("Minima calificacion: %.2f\n", minEstudiante[i]);
    }

    printf("\nEl Promedio por Asignatura\n");
    for (int j = 0; j < ASIGNATURAS; j++) {
        printf("Asignatura %d: %.2f\n", j + 1, promedioAsignatura[j]);
    }

    printf("\nMaxima y Minima por Asignatura\n");
    for (int j = 0; j < ASIGNATURAS; j++) {
        printf("Asignatura %d -> Maxima: %.2f | Minima: %.2f\n", j + 1, maxAsignatura[j], minAsignatura[j]);
    }

    printf("\nAprobados y Reprobados por Asignatura\n");
    for (int j = 0; j < ASIGNATURAS; j++) {
        printf("Asignatura %d -> Aprobados: %d | Reprobados: %d\n", j + 1, aprobados[j], reprobados[j]);
    }

    return 0;
}
