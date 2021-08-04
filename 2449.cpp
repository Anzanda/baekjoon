#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define MAX 256
#define endl "\n"
#define INF 987645321

int n, k;
int arr[MAX];
int dp[MAX][MAX];
int rundp(int l, int r) {
    if(dp[l][r] != -1) {
        return dp[l][r];
    }
    if(l == r) {
        dp[l][r] = 0;
        return dp[l][r];
    }
    dp[l][r] = INF;
    for(int k=l; k<r; k++) {
        dp[l][r] = min(dp[l][r], rundp(l, k)+rundp(k+1, r)+(arr[l]!=arr[k+1]?1:0));
    }
    return dp[l][r];
}
int main(void) {
    FastIO;
    cin >> n >> k;
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    memset(dp, -1, sizeof dp);
    cout << rundp(0, n-1) << endl;
    return 0;
}