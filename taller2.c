#include <stdio.h>
#include <string.h>

#define ESTUDIANTES 5
#define ASIGNATURAS 3
#define MAX_NOMBRE 50

int main() {
    char nombres[ESTUDIANTES][MAX_NOMBRE];
    float calificaciones[ESTUDIANTES][ASIGNATURAS];
    float promedioEstudiante[ESTUDIANTES];
    float promedioAsignatura[ASIGNATURAS];
    float maxEstudiante[ESTUDIANTES], minEstudiante[ESTUDIANTES];
    float maxAsignatura[ASIGNATURAS], minAsignatura[ASIGNATURAS];
    int aprobados[ASIGNATURAS] = {0}, reprobados[ASIGNATURAS] = {0};
    int opcion;
    int datosIngresados = 0;

    do {
        printf("\nMENU\n");
        printf("1. Ingresar nombres y calificaciones\n");
        printf("2. Mostrar resultados\n");
        printf("3. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                for (int i = 0; i < ESTUDIANTES; i++) {
                    printf("\nIngrese el nombre del estudiante %d: ", i + 1);
                    scanf("%s", nombres[i]);

                    for (int j = 0; j < ASIGNATURAS; j++) {
                        do {
                            printf("Ingrese la calificacion del estudiante %s en la asignatura %d (0 - 10): ", nombres[i], j + 1);
                            scanf("%f", &calificaciones[i][j]);
                            if (calificaciones[i][j] < 0 || calificaciones[i][j] > 10)
                                printf("Error: la calificacion debe estar entre 0 y 10.\n");
                        } while (calificaciones[i][j] < 0 || calificaciones[i][j] > 10);
                    }
                }
                datosIngresados = 1;
                break;

            case 2:
                if (!datosIngresados) {
                    printf("Primero debe ingresar los datos.\n");
                } else {
                    // Calculo de promedios, máximos y mínimos por estudiante
                    for (int i = 0; i < ESTUDIANTES; i++) {
                        float suma = 0;
                        maxEstudiante[i] = minEstudiante[i] = calificaciones[i][0];
                        int materiaMin = 0;

                        for (int j = 0; j < ASIGNATURAS; j++) {
                            suma += calificaciones[i][j];
                            if (calificaciones[i][j] > maxEstudiante[i])
                                maxEstudiante[i] = calificaciones[i][j];

                            if (calificaciones[i][j] < minEstudiante[i]) {
                                minEstudiante[i] = calificaciones[i][j];
                                materiaMin = j;
                            }
                        }
                        promedioEstudiante[i] = suma / ASIGNATURAS;
                        printf("\nEstudiante: %s\n", nombres[i]);
                        printf("Promedio: %.2f\n", promedioEstudiante[i]);
                        printf("Maxima calificacion: %.2f \n", maxEstudiante[i]);
                        printf("Minima calificacion: %.2f (Asignatura %d)\n", minEstudiante[i], materiaMin + 1);
                    }

                    // Calculo de promedios, máximos, mínimos y aprobados por asignatura
                    for (int j = 0; j < ASIGNATURAS; j++) {
                        float suma = 0;
                        maxAsignatura[j] = minAsignatura[j] = calificaciones[0][j];
                        aprobados[j] = reprobados[j] = 0;

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
                    printf("\nPromedio por Asignatura:\n");
                    for (int j = 0; j < ASIGNATURAS; j++) {
                        printf("Asignatura %d: %.2f\n", j + 1, promedioAsignatura[j]);
                    }

                    printf("\nMaxima y Minima por Asignatura:\n");
                    for (int j = 0; j < ASIGNATURAS; j++) {
                        printf("Asignatura %d -> Maxima: %.2f | Minima: %.2f\n", j + 1, maxAsignatura[j], minAsignatura[j]);
                    }

                    printf("\nAprobados y Reprobados por Asignatura:\n");
                    for (int j = 0; j < ASIGNATURAS; j++) {
                        printf("Asignatura %d -> Aprobados: %d | Reprobados: %d\n", j + 1, aprobados[j], reprobados[j]);
                    }
                }
                break;

            case 3:
                printf("Fin del programa\n");
                break;

            default:
                printf("ingrese una opcion del 1 al 3. NADA MAS\n");
        }
    } while (opcion != 3);

    return 0;
}
