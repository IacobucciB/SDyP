#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

// Dimension por defecto de las matrices
int N = 100;

// Para calcular tiempo
double dwalltime() {
    double sec;
    struct timeval tv;

    gettimeofday(&tv, NULL);
    sec = tv.tv_sec + tv.tv_usec / 1000000.0;
    return sec;
}

int main(int argc, char *argv[]) {
    double *A, *B, *C;
    int i, j, k;
    int check = 1;
    double timetick;

    // Controla los argumentos al programa
    if ((argc != 2) || ((N = atoi(argv[1])) <= 0)) {
        printf("\nUsar: %s n\n  n: Dimension de la matriz (nxn X nxn)\n",
               argv[0]);
        exit(1);
    }

    // Aloca memoria para las matrices
    A = (double *)malloc(sizeof(double) * N * N);
    B = (double *)malloc(sizeof(double) * N * N);
    C = (double *)malloc(sizeof(double) * N * N);


    


    free(A);
    free(B);
    free(C);
    return (0);
}