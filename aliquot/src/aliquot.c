
#include <stdio.h>

long long sum_of_proper_divisors(long long n) {
    long long sum = 1;
    long long i;

    if (n <= 1)
        return 0;

    for (i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            sum += i;
            if (i != n / i)
                sum += n / i;
        }
    }

    return sum;
}

int main(void) {
    long long n;
    long long max_length;
    long long current;
    long long steps = 0;
    char option;
    const long long LIMIT = 1000000000000000LL;

    printf("Please give the number to start the aliquot sequence from: ");
    if (scanf("%lld", &n) != 1 || n <= 0)
        return 1;

    printf("Provide the max aliquot length to look for (0 for unlimited): ");
    if (scanf("%lld", &max_length) != 1)
        return 1;

    printf("Do you want to print the full sequence ('f') or just the length ('l')? ");
    if (scanf(" %c", &option) != 1)
        return 1;
    if (option != 'f' && option != 'l')
        return 1;

    current = n;

    if (option == 'f') {
        while ((max_length == 0 || steps < max_length) && current != 0) {
            printf("%lld\n", current);
            current = sum_of_proper_divisors(current);
            steps++;

            if (current > LIMIT) {
                printf("Number exceeds maximum supported integer (1000000000000000). Stopping.\n");
                return 1;
            }
        }
    } else {
        while ((max_length == 0 || steps < max_length) && current != 0) {
            current = sum_of_proper_divisors(current);
            steps++;

            if (current > LIMIT) {
                printf("Number exceeds maximum supported integer (1000000000000000). Stopping.\n");
                return 1;
            }
        }
        printf("Length of aliquot sequence: %lld\n", steps);
    }

    return 0;
}
