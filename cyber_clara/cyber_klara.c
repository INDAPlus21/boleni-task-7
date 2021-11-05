#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    unsigned long int n;
    scanf("%lu", &n);

    char names[2*n][21];

    for (unsigned long int i = 0; i < n; i++) {
        scanf("%s", names[i]);
    }

    for (unsigned long int i = 0; i < n; i++) {
        scanf("%s", names[n+i]);
    }

    char allNames[n][42];
    for (unsigned long int i = 0; i < n; i++) {
        char target[42];
        strcpy(target, names[i]);
        strcat(target, "_");
        strcat(target, names[n+i]);
        strcpy(allNames[i], target);
    }

    qsort(allNames, n, 42, strcmp);

    unsigned long int doublis = 0;

    for (unsigned long int i = 0; i < n; i++) {
        if (strcmp(allNames[i], allNames[i+1]) == 0 && i != n-1) {
            doublis++;
        }
    }

    printf("%lu", n-doublis);
    return 0;
}
