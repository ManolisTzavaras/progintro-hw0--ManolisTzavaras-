
#include <stdio.h>

int sum_of_proper_divisors(int n) {
    if(n <= 1) return 0;
    int sum = 1; // 1 is a proper divisor of any n > 1
    for(int i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            sum += i;
            if(i != n / i) {
                sum += n / i;
            }
        }
    }
    return sum;
}

int main() {
    int n;
    printf("Please give the number to start the aliquot sequence from:");
    if (scanf("%d", &n) != 1 || n <= 0) {
        return 1;
    }

    int max_length;
    printf(" Provide the max aliquot length to look for(0 for unlimited):");
    if (scanf("%d", &max_length) != 1) {
        return 1;
    }

    char option;
    printf(" Do you want to print the full sequence('f')or just the length('l')?");
    if (scanf(" %c", &option) != 1 || (option != 'f' && option != 'l')) {
        return 1;
    }

    int seen[10000] = {0}; // μεγαλύτερος πίνακας για ασφάλεια
    int steps = 0;
    int current = n;

    if (option == 'f') {
        while ((max_length == 0 || steps < max_length) && current != 0) {
            printf("%d\n", current);
            current = sum_of_proper_divisors(current);
            steps++;

            if (current > 1000000000000000) {
                printf("Number exceeds maximum supported integer(1000000000000000).Stopping.\n");
                return 1;
            }
        }
    } else if (option == 'l') {
        while ((max_length == 0 || steps < max_length) && current != 0) {
            current = sum_of_proper_divisors(current);
            steps++;

            if (current > 1000000000000000) {
                printf("Number exceeds maximum supported integer(1000000000000000).Stopping.\n");
                return 1;
            }
        }
        printf("Length of aliquot sequence:%d\n", steps);
    }

    return 0;
}
