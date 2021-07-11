#include <bits/stdc++.h>
using namespace std;

#define MAXN 100
#define endl "\n"
#define FastIO ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr)

int n,m;
int mem[MAXN+1];
int cost[MAXN+1];
int dp[MAXN+1][10001];
int main(void) {
    FastIO;
    cin >> n >> m;
    for(int i=1; i<=n; i++) {
        cin >> mem[i];
    }
    int maxCost = 0;
    for(int i=1; i<=n; i++) {
        cin >> cost[i];
        maxCost += cost[i];
    }
    int ans = 0;
    for(int i=1; i<=n; i++) {
        for(int j=0; j<=maxCost; j++) {
            if(j-cost[i] >= 0) {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-cost[i]] + mem[i]);
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    for(int i=0; i<=maxCost; i++) {
        if(dp[n][i] >= m) {
            cout << i << endl;
            break;
        }
    }
    return 0;
}