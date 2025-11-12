#include<stdio.h>
#include<omp.h>

// long int ser_fib(long int n){
//     if (n < 2) return n;
//     return ser_fib(n-1) + ser_fib(n-2);
// }


long int ser_fib(long int n) {
    if (n < 2) return n;
    long int a = 0, b = 1, c;
    for (long int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}


int main(){
    long int n;
    int result;
    printf("enter value of 'n':\t");
    scanf("%ld", &n);
    result = ser_fib(n);

    printf("ANSWER IS :\t%d\n", result);
}