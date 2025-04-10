#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <limits.h>

int N = 1024;
int T = 4;
int *V;
int MIN = INT_MAX;
int MAX = INT_MIN;
pthread_mutex_t mutex;

void *worker(void *arg) {
    int tid = *(int *)arg;
    int i;
    int local_min = INT_MAX;
    int local_max = INT_MIN;
    int slice = N/T;
    int ini = tid * slice;
    int lim = ini + slice;

    for (i = ini; i < lim; i++) {
	if (V[i] < local_min) {
	    local_min = V[i];
	}
	if (V[i] > local_max) {
	    local_max = V[i];
	}
    }

    pthread_mutex_lock(&mutex);
    if (local_min < MIN) {
	MIN = local_min;
    }
    if (local_max > MAX) {
	MAX = local_max;
    }
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
    V[100] = 512;
    V[500] = 5;

    pthread_mutex_init(&mutex, NULL);

    for (int id = 0; id < T; id++) {
        threads_ids[id] = id;
        pthread_create(&misThreads[id], NULL, &worker,(void *)&threads_ids[id]);
    }

    for (int id = 0; id < T; id++) {
        pthread_join(misThreads[id], NULL);
    }

    pthread_mutex_destroy(&mutex);

    printf("MIN %d \n", MIN);
    printf("MAX %d \n", MAX);

    free(V);

    return 0;
}
