#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define MAX 1024
#define FastIO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define INF 987645321

int n;
int arr[MAX][3];
int dp[MAX][3];
int ans;
void solve(int state) {
    memset(dp, -1, sizeof dp);
    for(int i=0; i<3; i++) {
        if(state == i)  continue;
        dp[1][i] = arr[1][i];
    }
    for(int i=2; i<n; i++) {
        for(int j=0; j<3; j++) {
            dp[i][j] = INF;
            for(int k=0; k<3; k++) {
                if(j == k)  continue;
                if(dp[i-1][k] != -1) {
                    dp[i][j] = min(dp[i][j], dp[i-1][k]);
                }
            }
            dp[i][j] += arr[i][j];
        }
    }
    for(int i=0; i<3; i++) {
        if(i == state)  continue;
        ans = min(ans, dp[n-1][i]+arr[0][state]);
    }
}
int main(void) {
    FastIO;
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    }
    ans = INF;
    for(int i=0; i<3; i++) {
        solve(i);
    }
    cout << ans << endl;
    return 0;
}