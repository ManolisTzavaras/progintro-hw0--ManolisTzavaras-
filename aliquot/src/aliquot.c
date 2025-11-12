
#include <stdio.h>

long long int LIMIT = 1000000000000000;

long long int start, max_len;
char mode;

long long int div_sum(long long int n) {
    if (n == 1) return 0;

    long long int s = 1;
    for (long long int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            long long int j = n / i;
            if (i == j) {
                s += i;
            } else {
                s += i + j;
            }
        }
    }
    return s;
}

int main() {
    printf("Please give the number to start the aliquot sequence from: ");
    if (scanf("%lld", &start) != 1 || start <= 0 || start >= LIMIT) {
        printf("Only positive integer values below 1000000000000000 are accepted.\n");
        return 1;
    }

    printf("Provide the max aliquot length to look for (0 for unlimited): ");
    if (scanf("%lld", &max_len) != 1 || max_len < 0 || max_len >= LIMIT) {
        printf("Only positive integer values below 1000000000000000 are accepted.\n");
        return 1;
    }

    printf("Press f for full sequence or l for length. ");
    scanf(" %c", &mode);

    if (mode != 'f' && mode != 'l') {
        printf("The only acceptable options are f and l.\n");
        return 1;
    }

    long long int n = start;
    long long int len = 0;

    if (mode == 'f') {
        printf("%lld\n", start);
    }

    while (1==1) {
        if (max_len != 0 && len >= max_len) {
            break;
        }

        if (n == 0 || n >= LIMIT) {
            break;
        }

        n = div_sum(n);
        len++;

        if (n >= LIMIT) {
            printf("Last acceptable number: %lld\n", n);
            printf("Number exceeds maximum supported integer (1000000000000000). Stopping.\n");
            return 1;
        }

        if (mode == 'f') {
            printf("%lld\n", n);
        }
    }

    if (mode == 'l') {
        printf("Length of aliquot sequence: %lld\n", len);
    }

    return 0;
}
