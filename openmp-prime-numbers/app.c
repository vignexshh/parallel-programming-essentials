#include<stdio.h>

int is_prime(int n){
    if (n < 2) {
        return 0; /* not prime */
    }
    for (int j = 2; j * j <= n; j++) {
        if (n % j == 0) {
            return 0; /* not prime */
        }
    }
    return 1; /* prime */
}

int main(void) {
    int result = is_prime(5);
    printf("5 is %s\n", result ? "prime" : "not prime");
    return 0;
}