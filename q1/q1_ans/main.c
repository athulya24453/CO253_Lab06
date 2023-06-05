#include <stdio.h>
#include <stdlib.h>

int minInt(int a, int b){
    if (a>b){
        return b;
    }
    else{
        return a;
    }
}

int gcd(int a, int b) {
    int ans = 1;
    int lim = minInt(a,b);
    for (int j=1 ;j<=lim;j++){
        if (a%j==0 && b%j==0){
            ans = j;
        }
    }
    return ans;
}

char * isPossible(int a, int b, int c, int d) {

    char * ans = malloc(5 * sizeof(char));

    int gcdab = gcd(a,b);
    int gcdcd = gcd(c,d);

    if (gcdab==gcdcd){
        if (a==d && b==c){
            ans = "No";
        }
        else{
            ans = "Yes";
        }
    }
    else {
        ans = "No";
    }
    return ans;
}

int main()
{
    int a,b,c,d;
    scanf("%d %d %d %d" , &a,&b,&c,&d);
    char* ans = isPossible(a,b,c,d);
    printf("%s", ans);
    //int ans = gcd(48,40);
    //printf("%d", ans);
    return 0;
}
