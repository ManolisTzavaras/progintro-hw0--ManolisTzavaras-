
#include <stdio.h>

// --- Συνάρτηση: sum_of_proper_divisors ---
int sum_of_proper_divisors(int n) {
    if (n <= 1)
        return 0;

    int sum = 1; // 1 is a proper divisor of any n > 1
    for (int i = 2; i * i <= n; i++) {          // Αρχή for
        if (n % i == 0) {                       // Αρχή if (έλεγχος διαιρετών)
            sum += i;
            if (i != n / i) {                   // Αρχή εσωτερικού if
                sum += n / i;
            }                                   // Τέλος εσωτερικού if
        }                                       // Τέλος if (έλεγχος διαιρετών)
    }                                           // Τέλος for
    return sum;
}                                               // Τέλος συνάρτησης sum_of_proper_divisors


// --- Κύρια συνάρτηση ---
int main(void) {
    int n;
    printf("Please give the number to start the aliquot sequence from: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        return 1;
    }

    int max_length;
    printf("Provide the max aliquot length to look for (0 for unlimited): ");
    if (scanf("%d", &max_length) != 1) {
        return 1;
    }

    char option;
    printf("Do you want to print the full sequence ('f') or just the length ('l')? ");
    if (scanf(" %c", &option) != 1 || (option != 'f' && option != 'l')) {
        return 1;
    }

    int steps = 0;
    int current = n;

    if (option == 'f') {                            // Αρχή if (full sequence)
        while ((max_length == 0 || steps < max_length) && current != 0) {   // Αρχή while (τύπωμα)
            printf("%d\n", current);
            current = sum_of_proper_divisors(current);
            steps++;

            if (current > 1000000000000000LL) {     // Αρχή if (έλεγχος overflow)
                printf("Number exceeds maximum supported integer (1000000000000000). Stopping.\n");
                return 1;
            }                                       // Τέλος if (overflow)
        }                                           // Τέλος while (τύπωμα)
    } else {                                        // else -> μόνο μήκος
        while ((max_length == 0 || steps < max_length) && current != 0) {   // Αρχή while (μήκος)
            current = sum_of_proper_divisors(current);
            steps++;

            if (current > 1000000000000000LL) {     // Αρχή if (overflow)
                printf("Number exceeds maximum supported integer (1000000000000000). Stopping.\n");
                return 1;
            }                                       // Τέλος if (overflow)
        }                                           // Τέλος while (μήκος)
        printf("Length of aliquot sequence: %d\n", steps);
    }                                               // Τέλος if (option == 'f')

    return 0;
}                                                   // Τέλος main
