#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define THREAD_NUM 5

void *ThreadSample(void *arg)
{
    printf("Thread %ld : created \n", (long)arg);
    return (void*)arg;
}

int main()
{
    pthread_t tid[THREAD_NUM];
    int i, status;

    for (i = 0; i < THREAD_NUM; i++) {
        status = pthread_create(&tid[i], NULL, ThreadSample, (void*)(long)i);

        if (status != 0) {
            fprintf(stderr, "Create thread %d : %d", i, status);
            exit(1);
        }
    }

    for (i = 0; i < THREAD_NUM; i++) {
        pthread_join(tid[i], NULL);
    }

    return 0;
}
