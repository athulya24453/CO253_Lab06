#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

char * isValid(int a_count, int * a) {
    char * result = malloc(4 * sizeof(char));
    int root = INT_MIN;
    int s[a_count];
    int items = 0;
    for (int i = 0; i < a_count; i++) {
        if (a[i] < root) {
            result = "NO";
            return result;
        }
        while (items > 0 && s[items - 1] < a[i]) {
            root = s[items - 1];
            printf("root replaced by s[items] %d\n", root);
            items--;
        }
        s[items] = a[i];
        printf("%d ", s[items]);
        items++;
    }
    printf("\n");
    result = "YES";

    return result;
}

int main()
{
    int n;
    printf("n: ");
    scanf("%d", &n);
    int A[n];

    for (int i=0; i<n; i++){
        scanf("%d", &A[i]);
    }

    char* ans = isValid(n,A);
    printf("%s", ans);

    return 0;
}
