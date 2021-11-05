#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    char names[2*n][21];

    for (int i = 0; i < n; i++) {
        scanf("%s", names[i]);
    }

    for (int i = 0; i < n; i++) {
        scanf("%s", names[n+i]);
    }

    char allNames[n][42];
    for (int i = 0; i < n; i++) {
        char target[42];
        strcpy(target, names[i]);
        strcat(target, names[n+i]);
        strcpy(allNames[i], target);
    }

    qsort(allNames, n, 42, strcmp);

    for(int i = 0; i < n; i++) {
        printf("%s\n", allNames[i]);
    }

    int doublis = 0;
    for (int i = 0; i < n; i++) {
        if (strcmp(allNames[i], allNames[i+1]) == 0) {
            doublis++;
        }
    }

    printf("%d", n-doublis);
    return 0;
}
