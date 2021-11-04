#include <stdio.h>                  // standard input/output library
#include <string.h>
#include <stdbool.h>

int doubles(char names[][20], int n, char firstname[], char surname[]) {
    int doubles = 0;

    for (int i = 0; i < n; i++) {
        if (strcmp(names[i], firstname) == 0 && strcmp(names[n+i], surname) == 0) {
            doubles++;
        }
    }
    return doubles - 1;
}

bool contains(char names[][20], int n, int max, char firstname[], char surname[]) {
    for (int i = 0; i < max; i++) {
        if (strcmp(names[i], firstname) == 0 && strcmp(names[i+1], surname) == 0) {
            return true;
        }
    }
    return false;
}

int main() {
    int n;
    scanf("%d", &n);

    if (n < 0 || n > 100000)
        return -1;

    char names[2*n][20];

    for (int i = 0; i < n; i++) {
        scanf("%s", names[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%s", names[n+i]);
    }

    char usedNames[2*n][20];
    int posUsedNames = 0;

    int dubbles = 0;
    for (int i = 0; i < n; i++) {
        if (!contains(usedNames, n, posUsedNames+1, names[i], names[n+i])) {
            dubbles += doubles(names, n, names[i], names[n+i]);
            strcpy(usedNames[posUsedNames], names[i]);
            strcpy(usedNames[posUsedNames+1], names[n+i]);
            posUsedNames += 2;
        }
    }

    printf("%d", n-dubbles);
}


