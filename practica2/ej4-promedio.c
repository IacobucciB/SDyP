#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

int N = 1024;
int T = 4;
int *V;
int PROM = 0;
pthread_mutex_t mutex;

void *worker(void *arg) {
    int tid = *(int *)arg;
    int i;
    int local_prom = 0;
    int sum = 0;
    int slice = N/T;
    int ini = tid * slice;
    int lim = ini + slice;

    for (i = ini; i < lim; i++) {
	sum = sum + V[i];
    }
    local_prom = sum / slice;
    
    pthread_mutex_lock(&mutex);
    PROM = PROM + local_prom;
    pthread_mutex_unlock(&mutex);
    
    pthread_exit(NULL);
}


int main(void)
{
    int i;

    int threads_ids[T];
    pthread_t misThreads[T];
    
    V = (int *)malloc(sizeof(int) * N);
    for (i = 0; i < N; ++i) {
	V[i] = 100;
    }
    V[100] = 1024;
    V[500] = 1024;

    pthread_mutex_init(&mutex, NULL);

    for (int id = 0; id < T; id++) {
        threads_ids[id] = id;
        pthread_create(&misThreads[id], NULL, &worker,(void *)&threads_ids[id]);
    }

    for (int id = 0; id < T; id++) {
        pthread_join(misThreads[id], NULL);
    }

    pthread_mutex_destroy(&mutex);

    printf("PROM %d\n", PROM);
    free(V);

    return 0;
}
