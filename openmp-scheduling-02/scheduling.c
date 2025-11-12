#include<stdio.h>
#include<omp.h>

int main(){
    int n, thread, i;

    printf("Enter number of threads :");
    scanf("%d", &thread);
    printf("\nEnter number of tasks :");
    scanf("%d", &n);

    omp_set_num_threads(thread);
    printf("\n-------------------------------");
    #pragma omp parallel for schedule(static, 10)
    for(i=0;i<n;i++){
        printf("\nThread %d executes iteration %d\n", omp_get_thread_num(), i);
    }

    return 0;

}