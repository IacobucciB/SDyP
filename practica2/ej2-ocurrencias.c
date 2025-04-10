#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

int N = 1024;
int T = 4;
int *V;
int occ = 0;
pthread_mutex_t mutex;

void *worker(void *arg) {
    int tid = *(int *)arg;
    int i;
    int sum = 0;
    int slice = N/T;
    int ini = tid * slice;
    int lim = ini + slice;

    for (i = ini; i < lim; i++) {
	if (V[i] == 1) {
	    sum = sum + 1;
	}
    }

    pthread_mutex_lock(&mutex);
    occ = occ + sum;
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
	V[i] = 0;
	if (i % 5 == 0) {
	    V[i] = 1;
	}
    }

    pthread_mutex_init(&mutex, NULL);

    for (int id = 0; id < T; id++) {
        threads_ids[id] = id;
        pthread_create(&misThreads[id], NULL, &worker,(void *)&threads_ids[id]);
    }

    for (int id = 0; id < T; id++) {
        pthread_join(misThreads[id], NULL);
    }



    pthread_mutex_destroy(&mutex);

    printf("%d\n", occ);

    free(V);

    return 0;
}
