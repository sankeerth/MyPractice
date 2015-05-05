#include<pthread.h>
#include<iostream>

static int count = 0;
pthread_mutex_t mutex;
pthread_barrier_t barrier;

void* worker (void* arg)
{
    pthread_mutex_lock(&mutex);
    std::cout << "worker thread" << (int)arg << std::endl;
    count = count + 1;
    std::cout << count << std::endl;
    pthread_mutex_unlock(&mutex);
    pthread_barrier_wait(&barrier);

    std::cout << "worker thread" << (int)arg << std::endl;
}

int main()
{
    pthread_barrier_init(&barrier, 0, 5);
    pthread_mutex_init(&mutex, 0);
    pthread_t thread[5];
    for (int i = 0; i < 5; ++i) {
        pthread_create(&thread[i], NULL, worker, (void*)i);
    }
    pthread_join(thread[0], 0);
    pthread_join(thread[1], 0);
    pthread_join(thread[2], 0);
    pthread_join(thread[3], 0);
    pthread_join(thread[4], 0);
    pthread_mutex_destroy(&mutex);
    pthread_barrier_destroy(&barrier);
    pthread_exit(NULL);
}
