#include <stdio.h>
#include <stdlib.h>

char* isValid(int a_count, int* a){
    char * result = malloc(4 * sizeof(char));

    int i = 0;
    int c;

    for (i=0; i<a_count; i++){
        c = 0;
        int j = 0;

        while (a[j]<a[j+1]){
            j++;
        }
        j += 2;
        while (a[j-1]>a[j]){
            j++;
        }
        if (j == a_count){
            c++;
        }

    }

    if (c == a_count){
        result = "Yes";
    }

    else {
        result = "No";
    }

    return result;
}

int main()
{
    int* arr = {3,2,1,5,4,6};
    printf("%s", isValid(6,arr));
    return 0;
}
