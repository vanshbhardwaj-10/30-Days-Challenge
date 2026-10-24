
#include <stdio.h>

int main() {
    int a[12], n, i, j;
    int sum = 0, min, max;
    int secondlarge, found = 0;
    int peak = 0, run = 1, longest = 1;
    int k, temp, R, D, count = 0;

    printf("Enter N (5 to 12): ");
    scanf("%d", &n);

    while (n < 5 || n > 12) {
        printf("Invalid N! Enter again: ");
        scanf("%d", &n);
    }

    for (i = 0; i < n; i++) {
        printf("Enter reading (0 to 1000): ");
        scanf("%d", &a[i]);

        while (a[i] < 0 || a[i] > 1000) {
            printf("Invalid reading. Enter again: ");
            scanf("%d", &a[i]);
        }

        sum = sum + a[i];
    }

    printf("Original readings: ");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    min = a[0];
    max = a[0];

    for (i = 1; i < n; i++) {
        if (a[i] < min)
            min = a[i];

        if (a[i] > max)
            max = a[i];
    }

    printf("Sum = %d\n", sum);
    printf("Average = %.2f\n", (float)sum / n);
    printf("Minimum = %d\n", min);
    printf("Maximum = %d\n", max);

    for (i = 0; i < n; i++) {
        if (a[i] < max) {
            if (found == 0 || a[i] > secondlarge) {
                secondlarge = a[i];
                found = 1;
            }
        }
    }

    if (found == 1)
        printf("Second largest distinct value = %d\n", secondlarge);
    else
        printf("No second largest distinct value\n");

    for (i = 1; i < n - 1; i++) {
        if (a[i] > a[i - 1] && a[i] > a[i + 1])
            peak++;
    }

    printf("\nLocal peaks = %d", peak);

    for (i = 1; i < n; i++) {
        if (a[i] > a[i - 1])
            run++;
        else
            run = 1;

        if (run > longest)
            longest = run;
    }

    printf("\nLongest increasing run = %d", longest);

    printf("\nEnter K: ");
    scanf("%d", &k);

    k = k % n;

    if (k < 0)
        k = k + n;

    for (i = 0; i < k; i++) {
        temp = a[n - 1];

        for (j = n - 1; j > 0; j--)
            a[j] = a[j - 1];

        a[0] = temp;
    }

    printf("\nRotated array: ");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\nEnter last two digits of registration number: ");
    scanf("%d", &R);

    D = (R % 9) + 1;

    for (i = 0; i < n; i++) {
        if (a[i] % D == 0)
            count++;
    }

    printf("\nD = %d", D);
    printf("\nDivisible values count = %d\n", count);

    return 0;
}
