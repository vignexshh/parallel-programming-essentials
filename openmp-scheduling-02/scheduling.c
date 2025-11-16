#include<stdio.h>
#include<omp.h>


int main() {

    int n, thread;

    printf("Enter the number of tasks to be executed : ");
    scanf("%d", &n);

    printf("\nEnter the number of threads to be used for execution of %d tasks : ", n);
    scanf("%d", &thread);

    omp_set_num_threads(thread);
    printf("\n-------------------------------");

    #pragma omp parallel for schedule(static, 2)

     for(int i=0; i<n; i++){
        printf("\n%d has executed task %d\n", omp_get_thread_num(), i);

     }

     printf("\n-------------------------------\n");


     return 0;
}