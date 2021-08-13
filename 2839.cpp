#include <stdio.h>

#define INF 987645321
int min(int a, int b) {
    return a > b ? b:a;
}
int n;
int dp[5007];
int cnt;
int solve(int now) {
    cnt+=1;
    if(now < 0) {
        return INF;
    }
    if(now == 0) {
        return 0;
    }
    if(dp[now] != -1) {
        return dp[now];
    }
    dp[now] = min(solve(now-3)+1, solve(now-5)+1);
    return dp[now]; 
}
int solve2(int now) {
    cnt+=1;
    if(now < 0) {
        return INF;
    }
    if(now == 0) {
        return 0;
    }
    return min(solve2(now-3)+1, solve2(now-5)+1);
}
int main(void) {
    scanf("%d", &n);
    for(int i=0; i<=n; i++) {
        dp[i] = -1;
    }
    int ans = solve(n);
    printf("dp의 함수 호출 횟수: %d\n", cnt);
    cnt = 0;
    ans = solve2(n);
    printf("완탐의 함수 호출 횟수: %d\n", cnt);
    if(ans > n) {
        ans = -1;
    }
    printf("%d\n", ans);
    return 0;
}