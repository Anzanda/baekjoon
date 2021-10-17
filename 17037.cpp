#include <bits/stdc++.h>
using namespace std;

#define FastIO cin.tie(0)->sync_with_stdio(0)
#define endl 

int n, k;
int dp[1005][1005];
void input() {
    cin >> n >> k;
    for(int i=0; i<n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        dp[x1][y1]++;
        dp[x1][y2]--;
        dp[x2][y1]--;
        dp[x2][y2]++;
    }
}
void solve() {
    int ans = 0;
    for(int i=0; i<1000; i++) {
        for(int j=0; j<1000; j++) {
            if(i)   dp[i][j] += dp[i-1][j];
            if(j)   dp[i][j] += dp[i][j-1];
            if(i && j) dp[i][j] -= dp[i-1][j-1];
            if(dp[i][j] == k)   ans++; 
        }
    }
    cout << ans << endl;
}
int main(void) {
    FastIO;
    input();
    solve();
    return 0;
}