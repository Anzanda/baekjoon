#include <bits/stdc++.h>
#define fastIO iostream::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
#define INF 987654321
#define MAXN 100000
using namespace std;

int arr[MAXN+1];
int dp[MAXN+1][5][5];
int cost(int x, int y) {
    if(x == 0 || y == 0) {
        return 2;
    }
    if(x == y) {
        return 1;
    }
    if(abs(x-y) == 2) {
        return 4;
    }
    return 3;
}
int main(void) {
    fastIO;

    arr[0] = INF;
    int size = 0;
    while(arr[size]) {
        cin >> arr[++size];
    }
    memset(dp, -1, sizeof dp);
    dp[0][0][0] = 0;
    for(int i=1; i<size; i++) {
        for(int j=0; j<=4; j++) {
            for(int k=0; k<=4; k++) {
                if(dp[i-1][j][k] != -1) {
                    if(arr[i] != k) { 
                        if(dp[i][arr[i]][k] != -1)
                            dp[i][arr[i]][k] = min(dp[i][arr[i]][k], dp[i-1][j][k]+cost(j,arr[i]));                   
                        else
                            dp[i][arr[i]][k] = dp[i-1][j][k]+cost(j,arr[i]);    
                    }
                    if(arr[i] != j) {
                        if(dp[i][j][arr[i]] != -1)
                            dp[i][j][arr[i]] = min(dp[i][j][arr[i]], dp[i-1][j][k]+cost(k, arr[i]));
                        else 
                            dp[i][j][arr[i]] = dp[i-1][j][k]+cost(k,arr[i]);
                    }
                    
                }
            }
        }
    }
    int ans = INF;
    for(int i=0; i<=4; i++) {
        for(int j=0; j<=4; j++) {
            if(dp[size-1][i][j] != -1 && ans > dp[size-1][i][j])
                ans = dp[size-1][i][j];
        }
    }
    cout << ans << endl;
    return 0;
}