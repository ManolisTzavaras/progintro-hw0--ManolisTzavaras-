
#include <stdio.h>

int sum_of_proper_divisors(int n) {

    if(n<=1) return 0;
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
    printf("Enter a number: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Please enter a positive integer.\n");
        return 1;
    }
}

printf("Aliquot sequence %d: ", n);
   int seen[1000] = {0};
   int steps = 0;

   while (n != 0 && !seen[n]) {
    seen[n] = 1;
        int next = sum_of_proper_divisors(n);
        printf(" → %d", next);
        n = next;
        steps++;
        if (n >= 10000) break; // ασφάλεια σε μεγάλα n
    }

    printf("\n");

    if (n == 0)
        printf("Aliquot length: %d\n", steps);
    else if (seen[n])
        printf("Aliquot sequence entered a cycle.\n");

    return 0;
