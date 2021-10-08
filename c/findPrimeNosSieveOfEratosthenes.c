/*
Algorithm - Sieve of Eratosthenes
Given a number N, find all the prime numbers less than or equal to N
*/

#include<stdio.h>
#include<stdbool.h>

int main() {
    int n, i, j;
    printf("Enter number till which prime numbers are to be generated: ");
    scanf("%d", &n);
    bool isPrime[n+1]; // boolean array to store whether the number is prime or not
    //Initialize the boolean array to true, denoting all are prime so far
    for (i=0; i<=n ; ++i) {
    	isPrime[i] = true;
    }
    isPrime[0] = false; //since 0 is not prime
    isPrime[1] = false; //since 1 is not prime

    //Sieve step
    for(i=2; i * i <= n ; ++i){
        // Check if the number i is prime then mark all its multiples as non prime
        if(isPrime[i]) {
            for(j =i*i; j <=n; j+=i )
                isPrime[j] = false;
        }
    }

    // All the numbers with isPrime[i]= true are prime
    printf("Prime numbers are: \n");
    for(i=2; i<= n; ++i){
        if(isPrime[i]) {
            printf("%d\n", i);
        }
    }
    return 0;
}
