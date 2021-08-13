#include <stdio.h>
#include <string.h>

int n, k;
int coin[128];
int dp[128][100007];
int solve(int usingCount, int cost) {
    if(usingCount > n-1) {
        return 0;
    }
    if(dp[usingCount][cost] != -1) {
        return dp[usingCount][cost];
    }
    if(cost == 0) {
        return dp[usingCount][cost] = 1;
    }
    if(coin[usingCount] > cost) {
        return dp[usingCount][cost] = 0;
    }
    dp[usingCount][cost] = 0;
    for(int i=0; i<=cost; i+=coin[usingCount]) {
        dp[usingCount][cost] += solve(usingCount+1, cost-i);
    }
    return dp[usingCount][cost];
}
int main(void) {
    scanf("%d %d", &n, &k);
    for(int i=0; i<n; i++) {
        scanf("%d", &coin[i]);
    }
    memset(dp, -1, sizeof(dp));
    printf("%d\n", solve(0, k));
    return 0;
}