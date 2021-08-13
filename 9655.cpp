#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define FastIO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define MAX 1024
#define INF 987645321

int n;
int dp[MAX];
int rundp(int now) {
    if(now < 0) {
        return INF;
    }
    if(now == 0) {
        return 0;
    }
    if(dp[now] != -1) {
        return dp[now];
    }
    dp[now] = 1;
    dp[now] += min(rundp(now-1), rundp(now-3));
    return dp[now];
}
int main(void) {
    FastIO;
    cin >> n;
    memset(dp, -1, sizeof dp);
    rundp(n);
    if(dp[n]%2 == 0) {
        cout << "CY" << endl;
    } else {
        cout << "SK" << endl;
    }
    return 0;
}