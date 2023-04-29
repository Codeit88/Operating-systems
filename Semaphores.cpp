#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

int a, b, c, d;
int x, y, z, w, s1, s2;

sem_t sem1, sem2;

void *thread1(void *arg) {
    sem_wait(&sem1); // Wait for sem1 to be available
    x = z + 2;
    y = z * 5;
    s1 = x + y;
    printf("Output of thread 1:\n");
    printf("s1 = %d\n", s1);
    sem_post(&sem2); // Release sem2
    pthread_exit(NULL);
}

void *thread2(void *arg) {
    sem_wait(&sem2); // Wait for sem2 to be available
    z = x * 2;
    w = y + 5;
    s2 = z + w;
    printf("Output of thread 2:\n");
    printf("s2 = %d\n", s2);
    sem_post(&sem1); // Release sem1
    pthread_exit(NULL);
}

int main() {
    sem_init(&sem1, 0, 1);
    sem_init(&sem2, 0, 0);
    
    // Get input from user
    printf("Enter four integers (a, b, c, d): ");
    scanf("%d %d %d %d", &a, &b, &c, &d);
     
    pthread_t tid1, tid2;
    pthread_create(&tid1, NULL, thread1, NULL);
    pthread_create(&tid2, NULL, thread2, NULL);
    
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
    
    // Destroy semaphores
    sem_destroy(&sem1);
    sem_destroy(&sem2);
    
    return 0;
}
