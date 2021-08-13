#include <cstdio>
#include <string.h>
using namespace std;

#define MAX 64 

int dp[MAX][MAX][MAX];
int w(int a, int b, int c) {
    if(a<=0 || b<=0 || c<= 0) {
        return 1;
    }
    if(a>20 || b>20 || c>20) {
        return w(20, 20, 20);
    }
    if(dp[a][b][c] != -1) {
        return dp[a][b][c];
    }
    if(a<b && b<c) {
        return dp[a][b][c] = w(a,b,c-1)+w(a,b-1,c-1)-w(a,b-1,c);
    } 
    return dp[a][b][c] = w(a-1,b,c)+w(a-1,b-1,c)+w(a-1,b,c-1)-w(a-1,b-1,c-1);
}
int main(void) {
    int a, b, c;
    memset(dp, -1, sizeof dp);
    while(true) {
        scanf("%d %d %d", &a, &b, &c);
        if(a==-1 && b==-1 && c==-1) {
            return 0;
        }
        printf("w(%d, %d, %d) = %d\n", a, b, c, w(a,b,c));
    }
    return 0;
}