// To write a C program that implements producer consumer problem using semaphores.

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<semaphore.h>
#include<pthread.h>

// to write a c program that implements producer consumer problem using semaphores

#define BUFFER_SIZE 7
#define LOOP_COUNT 7

int buffer[BUFFER_SIZE];
int in = 0, out = 0;

sem_t mutex, empty, full;

void *producer(void *arg) {
    int i;
    for (i = 0; i < LOOP_COUNT; i++) {
        sem_wait(&empty);
        sem_wait(&mutex);
        buffer[in] = i;
        printf("Produced %d\n", i);
        in = (in + 1) % BUFFER_SIZE;
        sem_post(&mutex);
        sem_post(&full);
    }

    return NULL;
}

void *consumer(void *arg) {
    int item, i;
    for (i = 0; i < LOOP_COUNT; i++) {
        sem_wait(&full);
        sem_wait(&mutex);
        item = buffer[out];
        printf("Consumed %d\n", item);
        out = (out + 1) % BUFFER_SIZE;
        sem_post(&mutex);
        sem_post(&empty);
    }

    return NULL;
}

int main() {
    sem_init(&mutex, 0, 1);
    sem_init(&empty, 0, BUFFER_SIZE);
    sem_init(&full, 0, 0);
    pthread_t producerThread, consumerThread;
    pthread_create(&producerThread, NULL, producer, NULL);
    pthread_create(&consumerThread, NULL, consumer, NULL);
    pthread_join(producerThread, NULL);
    pthread_join(consumerThread, NULL);
    sem_destroy(&mutex);
    sem_destroy(&empty);
    sem_destroy(&full);
    return 0;
}
