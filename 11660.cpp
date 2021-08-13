#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define FastIO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define MAX 1024+7

int n,m;
int arr[MAX][MAX];
int dp[MAX][MAX];
int main(void) {
    FastIO;
    cin >> n >> m;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            cin >> arr[i][j];
        }
    }
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            dp[i][j] += arr[i][j] + dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
        }
    }
    int x1, x2, y1, y2;
    for(int i=0; i<m; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        cout << dp[x2][y2] - dp[x1-1][y2] - dp[x2][y1-1] + dp[x1-1][y1-1] << endl;
    }
    return 0;
}