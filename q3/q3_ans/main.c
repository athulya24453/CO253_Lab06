#include <stdio.h>
#include <stdlib.h>
#include <math.h>

char ** checkDivisibility(int arr_count, char ** arr) {
    //* result_count = arr_count;
    char ** result = malloc(arr_count * sizeof(char * ));
    for (int i = 0; i < arr_count; i++) {
    *(result + i) = malloc(5 * sizeof(char));
    }

    for (int i=0; i<arr_count;i++){
        int sum = 0;
        int len = strlen(arr[i]);
        for (int j=(len-1);j>=0;j--){
            int digit = (int)arr[i][j]-'0';
            double power = pow(2,(len-j-1));
            sum += digit*power;
        }
        if (sum%8==0){
            result[i] = "Yes";
        }
        else {
            result[i]="No";
        }
    }
    return result;
}

int main()
{
    char* s[5] = {"123", "16", "124","64","133"};
    char** ans = checkDivisibility(5, s);
    for (int i=0; i<5; i++){
        printf("%s\n", ans[i]);
    }
    return 0;
}
