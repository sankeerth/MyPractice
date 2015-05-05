#include <stdio.h>
#include <pthread.h>


pthread_mutex_t mutex;
pthread_cond_t cond;
int buffer = 0;

void* producer(void* arg)
{
    for(int i = 0; i < 5; ++i) {
        pthread_mutex_lock(&mutex);
        buffer = buffer + 1;
        printf("Buffer value in PRODUCER is : %d\n", buffer);
        pthread_cond_signal(&cond);
        pthread_mutex_unlock(&mutex);
    }
    printf("Producer finished\n");
}

void* consumer(void* arg)
{
    for (int i = 0; i < 5; ++i) {
        pthread_mutex_lock(&mutex);
        if (buffer == 0) {
            printf("Consumer waiting!\n");
            pthread_cond_wait(&cond, &mutex);
        }
        printf("Buffer value in CONSUMER is : %d\n", buffer);
        pthread_mutex_unlock(&mutex);
    }
    printf("Consumer finished\n");
}

int main()
{
    pthread_t producer_thread, consumer_thread;

    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&cond, NULL);

    pthread_create(&producer_thread, NULL, producer, NULL);
    pthread_create(&consumer_thread, NULL, consumer, NULL);

    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);

    pthread_cond_destroy(&cond);
    pthread_mutex_destroy(&mutex);
    
    return 0;
}
