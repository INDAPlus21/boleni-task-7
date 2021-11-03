#include <stdio.h>                  // standard input/output library

int min(int numbers[], int length) {
    int min = numbers[0];
    for (int i = 0; i < length; i++) {
        if (numbers[i] < min) {
            min = numbers[i];
        }
    }
    return min;
}

int main()
{
    int r;
    int k;

    scanf("%d%d", &r, &k);

    if (r < 0 || k < 0 || r > 1000 || k > 1000) {
        printf("Variables not within range.");
        return -1;
    }

    for (int y = 0; y < r; y++) {
        for (int x = 0; x < k; x++) {

            int leftD = x + 1;
            int rightD = k - x;
            int topD = y + 1;
            int botD = r - y;

            int numbers[] = {leftD, rightD, topD, botD};
            int minimum = min(numbers, 4);

            if (minimum <= 9)
                printf("%d", minimum);
            else
                printf(".");
        }
        printf("\n");
    }
}

