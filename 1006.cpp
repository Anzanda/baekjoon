#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define MAX 10000
#define FastIO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define INF 987645321

int T, n, w;   
vector<vector<int>> v;
vector<vector<int>> dp;
void rundp() {
    for(int i=2; i<=n; i++) {
        int up = v[0][i-1] + v[0][i] <= w ? 1 : 2;
        int down = v[1][i-1] + v[1][i] <= w ? 1 : 2;
        int verticle = v[0][i] + v[1][i] <= w ? 1: 2;

        dp[i][0] = min({dp[i-1][0]+verticle, dp[i-2][0]+up+down, dp[i-1][1]+up+1, dp[i-1][2]+down+1});
        dp[i][1] = min(dp[i-1][2]+down, dp[i-1][0]+1);
        dp[i][2] = min(dp[i-1][1]+up, dp[i-1][0]+1);
    }
}
int main(void) {  
    FastIO;
    cin >> T;
    while(T--) {
        cin >> n >> w;
        v = vector<vector<int>>(2, vector<int>(n+1, 0));
        dp = vector<vector<int>>(n+1, vector<int>(3, 0));
        for(int i=0; i<2; i++) {
            for(int j=1; j<=n; j++) {
                cin >> v[i][j];
            }
        } 
        vector<int> tmp = {v[0][1], v[1][1]};

        int ans=INF;
        dp[1][0] = v[0][1] + v[1][1] <= w ? 1:2;
        dp[1][1] = dp[1][2] = 1;
        rundp();
        ans = min(ans, dp[n][0]);
        if(v[0][1] + v[0][n] <= w) {
            dp[1][0] = 2;
            dp[1][1] = dp[1][2] = 1;
            v[0][1] = INF;
            rundp();
            ans = min(ans, dp[n][1]);
            v[0][1] = tmp[0]; 
        }
        if(v[1][1] + v[1][n] <= w) {
            dp[1][0] = 2;
            dp[1][1] = dp[1][2] = 1;
            v[1][1] = INF;
            rundp();
            ans = min(ans, dp[n][2]);
            v[1][1] = tmp[1]; 
        }
        if(v[0][1]+v[0][n] <= w && v[1][1]+v[1][n] <= w) {
            v[0][1] = v[1][1] = INF;
            dp[1][0] = 2;
            dp[1][1] = dp[1][2] = 1;
            rundp();
            ans = min(ans, dp[n-1][0]);
            v[0][1] = tmp[0];
            v[1][1] = tmp[1];
        }
        if(n == 1) {
            ans = v[0][1] + v[1][1] <= w ? 1:2;
        }
        cout << ans << endl;
    }
    return 0;
}