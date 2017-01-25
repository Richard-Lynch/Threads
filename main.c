#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#define NUM_THREADS 6

pthread_mutex_t lock;
int sum = 0;

void *PrintHello(void *threadid){
    pthread_mutex_lock(&lock);

    printf("Hello thread: %d\n", threadid);

    sum = sum + threadid;

    printf("Current Sum: %d\n", sum);

    pthread_mutex_unlock(&lock);

    pthread_exit(NULL);
}

int main(int argc, const char* argv[]){
    if (pthread_mutex_init(&lock, NULL) != 0)
    {
        printf("\n mutex init failed\n");
        return 1;
    }

    printf("hello\n");
    pthread_t threads[NUM_THREADS];
    int rc, t;

    for(t=0; t<NUM_THREADS; t++){
        printf("Creating thread %d.\n", t);
        
        rc = pthread_create(&threads[t], NULL, PrintHello, (void*)t);
        
        if(rc){
            printf("ERROR - return code from pthread_create: %d\n", rc);
            exit(-1);
        }
    }

    for(t=0; t<NUM_THREADS; t++){
        printf("Joining thread %d.\n", t);

        pthread_join(&threads[t], NULL);
    }

    pthread_mutex_destroy(&lock);

    return 0;
}



