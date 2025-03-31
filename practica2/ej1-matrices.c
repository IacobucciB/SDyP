#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

int N = 100;
double *A;
double *B;
double *C;

/*
(N / NumThreads) * id --> inicio
(N / NumThreads) * (id + 1) --> fin
*/

void *funcion(void *arg) {
    int tid = *(int *)arg;
    printf("Hilo id: %d \n\n", tid);
    // codigo

    // mutex para saber el valor de N?

    int i, j, k;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            C[i * N + j] = 0;  // ORDENXFILAS
            for (k = 0; k < N; k++) {
                C[i * N + j] += A[i * N + k] * B[k * N + j];  // ORDENXFILAS
            }
        }
    }

    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    // double *A, *B, *C;
    int i, j, k;
    int check = 1;
    double timetick;

    int T = atoi(argv[1]);
    int threads_ids[T];
    pthread_t misThreads[T];

    A = (double *)malloc(sizeof(double) * N * N);
    B = (double *)malloc(sizeof(double) * N * N);
    C = (double *)malloc(sizeof(double) * N * N);

    // Inicializa las matrices A y B en 1, el resultado sera una matriz con
    // todos sus valores en N
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            A[i * N + j] = 1;  // ORDENXFILAS
            B[i * N + j] = 1;  // ORDENXFILAS
        }
    }

    // Realiza la multiplicacion
    timetick = dwalltime();

    for (int id = 0; id < T; id++) {
        threads_ids[id] = id;
        pthread_create(&misThreads[id], NULL, &funcion,
                       (void *)&threads_ids[id]);
    }

    for (int id = 0; id < T; id++) {
        pthread_join(misThreads[id], NULL);
    }

    printf("Tiempo en segundos %f\n", dwalltime() - timetick);

    return 0;
}