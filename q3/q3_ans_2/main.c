#include <stdio.h>
#include <stdlib.h>

int ans[10] = {0};
int state = 0;

int* countNums(char *s, int count){
    int num = atoi(s);
    char* str;
    sprintf(str, "%03d", num);

    for (int j=0; j<10; j++){
        ans[j]=0;
    }

    for (int i=0; i<count; i++){
        int element = (int)s[i] - '0';
        ans[element]++;
    }

    return ans;
}


char ** checkDivisibility(int arr_count, char ** arr) {


    char ** result = malloc(arr_count * sizeof(char * ));

    for (int i = 0; i < arr_count; i++) {
        *(result + i) = malloc(5 * sizeof(char));
    }

    for (int i=0; i<arr_count; i++){
        state = 0;

        for (int j=0;j<=1000;j+=8){
            int* numsCount = countNums(arr[i],strlen(arr[i]));
            int count=0;
            char str[4];
            sprintf(str, "%03d", j);
            for (int k=0; k<strlen(str); k++){
                int point = (int)str[k]-'0';
                int checkDigit = numsCount[point];
                if (checkDigit!=0){
                    count++;
                    numsCount[point] = checkDigit - 1;
                }
                if (count==strlen(str)){
                    result[i] = "YES";
                    state = 1;
                    break;
                }
            }

            if (state ==1){
                break;
            }
        }
        if (state==0){
                result[i] = "NO";
            }

    }

    return result;
}


int main()
{
    char* s[5] = {"75", "61"};
    char** ans = checkDivisibility(2, s);
    for (int i=0; i<2; i++){
        printf("%s\n", ans[i]);
    }
    return 0;
}
