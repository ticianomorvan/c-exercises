/* Simple multi-threaded program that DOES allow mutual exclusion, but it does an unoptimal lock acquiring process. */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int volatile counter = 0;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void *my_thread(void *arg) {
    int *limit = (int *) arg;
    for (int i = 0; i < *limit; ++i) {
        pthread_mutex_lock(&lock);
        counter++;
        pthread_mutex_unlock(&lock);
    }
    return NULL;
}

int main(int argc, char* argv[]) {
    pthread_t p1, p2;
    int *limit = NULL;

    if (argc <= 1) {
        fprintf(stderr, "ERROR: <limit> must be provided.\n");
        exit(EXIT_FAILURE);
    }

    limit = (int *) malloc(sizeof (int));

    if (limit == NULL) {
        fprintf(stderr, "ERROR: failed to allocate memory for limit.\n");
        exit(EXIT_FAILURE);
    }

    *limit = atoi(argv[1]);

    pthread_create(&p1, NULL, my_thread, limit);
    pthread_create(&p2, NULL, my_thread, limit);
    pthread_join(p1, NULL);
    pthread_join(p2, NULL);
    printf("Counter at %i\n", counter);
    return EXIT_SUCCESS;
}
