#include <stdio.h>
#include <string.h>

int main() {
    int seg, x, one;
    char A[20], D[40];

    printf("Enter the line segment: ");
    scanf("%d", &seg);

    printf("Enter the string: ");
    scanf("%s", A);

    int length = strlen(A);
    printf("\nThe length will be: %d", length);

    if (length % seg != 0) {
        x = seg - (length % seg);
        for (int i = 0; i < x; i++) {
            D[i] = '0';
        }
        D[x] = '\0';  // Null-terminate the padding string
        strcat(D, A); // Concatenate the original string
        printf("\nThe new string will be: ");
        puts(D);
    } else {
        strcpy(D, A);
    }

    int length1 = strlen(D);
    printf("\nThe new length will be: %d", length1);

    char str[100];
    for (int i = 0; i < length1;) {
        int p = 0;
        one = 0; // Initialize the counter for '1's

        for (int j = i; j < i + seg && j < length1; j++) {
            if (D[j] == '1') {
                one++;
            }
            str[p++] = D[j];
        }
        str[p] = '\0';  // Null-terminate the segment string

        printf("\nThe string segment will be: ");
        puts(str);
        printf("Number of '1's in this segment: %d\n", one);

        i += seg;
    }

    return 0;
}