#include <bits/stdc++.h>
using namespace std;

#define MAX 16+7
#define endl "\n"
#define FastIO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)

int n;
int arr[MAX][MAX];
int dp[MAX][MAX][3];
int main(void) {
    FastIO;
    cin >> n;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            cin >> arr[i][j];
        }
    }
    dp[1][2][0] = 1;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            if(arr[i][j])   continue;
            dp[i][j][0] += dp[i][j-1][0] + dp[i][j-1][1];
            for(int k=0; k<3; k++)  
                if(arr[i-1][j]==0 && arr[i][j-1]==0)    
                    dp[i][j][1] += dp[i-1][j-1][k];
            dp[i][j][2] += dp[i-1][j][1] + dp[i-1][j][2];
        }
    }
    int ans = 0;
    for(int i=0; i<3; i++)  ans += dp[n][n][i];
    cout << ans << endl;
    return 0;
}