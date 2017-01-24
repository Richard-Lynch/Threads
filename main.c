#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#define NUM_THREADS 6

//seems to be fixed

// int pthread_create(

//     pthread_t *thread,  //retured thread id

//     const pthread_attr_t *attr, //starting attriubes - if null then it will start immediatly 

//     void *(*start routine)(void*),  //the function to run

//     void * arg ); //paramater

// int pthread_join(pthread_t thread, void **value_ptr);

void *PrintHello(void *threadid){
    printf("Hello thread: %d\n", threadid);
    pthread_exit(NULL);
}

int main(int argc, const char* argv[]){

    pthread_t threads[NUM_THREADS];
    int rc, t;

    for(t=0; t<NUM_THREADS; t++){
        prinft("Creating thread %d.\n", t);

        rc = pthread_create(&threads[t], NULL, PrintHello, (void*)t);
        
        if(rc){
            prinf("ERROR - return code from pthread_create: %d\n", rc);
            exit(-1);
        }
    }

    for(t=0; t<NUM_THREADS; t++){
        prinft("Joining thread %d.\n", t);

        pthread_join(&threads[t], NULL);
    }


    return 0;

}



