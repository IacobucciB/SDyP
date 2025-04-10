#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

int N = 1024;
int T = 4;
double *A;
double *B;
double *C;

double dwalltime(){
        double sec;
        struct timeval tv;

        gettimeofday(&tv,NULL);
        sec = tv.tv_sec + tv.tv_usec/1000000.0;
        return sec;
}

void *thread(void *arg) {
    int tid = *(int *)arg;
    printf("Thread %d \n", tid);
    int slice = N/T;
    int ini = tid * slice;
    int lim = ini + slice;
    double sum;
    int i, j, k;

// TODO Optimize indexes
// iN = i*N; iJ = j*N

    for (i = ini; i < lim; i++) {
        for (j = 0; j < N; j++) {
	    sum = 0;
            for (k = 0; k < N; k++) {
		sum = sum + A[i*N + k] * B[k + j*N];
            }
	    C[i*N + j] = sum;
        }
    }

    pthread_exit(NULL);
}

void printMatrix(void) {
    int i, j;
    for (i = 0; i < N; i++) {
	printf("\n");
	for (j = 0; j < N; j++) {
	    printf("%.0f ", C[i*N + j]);
	}
    }
    printf("\n");
}

// int main(int argc, char *argv[]) {
int main(void) {
    int i, j;
    int check = 1;
    double timetick;


    int threads_ids[T];
    pthread_t misThreads[T];

    A = (double *)malloc(sizeof(double) * N * N);
    B = (double *)malloc(sizeof(double) * N * N);
    C = (double *)malloc(sizeof(double) * N * N);


    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            A[i * N + j] = 1;
            B[i * N + j] = 1;
        }
    }
    
    timetick = dwalltime();

    for (int id = 0; id < T; id++) {
        threads_ids[id] = id;
        pthread_create(&misThreads[id], NULL, &thread,(void *)&threads_ids[id]);
    }

    for (int id = 0; id < T; id++) {
        pthread_join(misThreads[id], NULL);
    }

    printf("Tiempo en segundos %f\n", dwalltime() - timetick);

    for (i = 0; i < N; i++) {
	for (j = 0; j < N; j++) {
            check = check && (C[i * N + j] == N);
	}
    }   

    if (check) {
	printf("Multiplicacion de matrices resultado correcto\n");
    } else {
	printf("Multiplicacion de matrices resultado erroneo\n");
	printMatrix();
    }

    
    free(A);
    free(B);
    free(C);

    return 0;
}
