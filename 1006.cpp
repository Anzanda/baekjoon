#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define FastIO ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define MAX 10000
#define INF 987654321

int t, n, w;
int enemy[MAX][2];
int dp[MAX][3];
/*
    j=0일 때, i번째가 위 아래 둘 다 채워진 경우중 최솟값
    j=1일 때, i번째가 위만 채워진 경우중 최솟값
    j=2일 때, i번째가 아래만 채워진 경우중 최솟값
*/
int ans;
void rundp() {
    int section1 = enemy[0][0] + enemy[1][0] <= w ? 1:2;
    int section2 = enemy[0][1] + enemy[1][1] <= w ? 1:2;
    int verticle = enemy[1][0] + enemy[1][1] <= w ? 1:2;
    dp[1][0] = min({section1+section2, dp[0][0]+verticle, dp[0][1]+section2+1, dp[0][2]+section1+1});
    dp[1][1] = min(dp[0][0]+1, dp[0][2]+section1);
    dp[1][2] = min(dp[0][0]+1, dp[0][1]+section2);
    for(int i=2; i<n; i++) {
        section1 = enemy[i-1][0] + enemy[i][0] <= w ? 1:2;
        section2 = enemy[i-1][1] + enemy[i][1] <= w ? 1:2;
        verticle = enemy[i][0] + enemy[i][1] <= w ? 1:2;
        dp[i][0] = min({dp[i-2][0]+section1+section2, dp[i-1][0]+verticle, dp[i-1][1]+section2+1, dp[i-1][2]+section1+1});
        dp[i][1] = min(dp[i-1][0]+1, dp[i-1][2]+section1);
        dp[i][2] = min(dp[i-1][0]+1, dp[i-1][1]+section2);
    }
    return;
}
int main(void) {
    FastIO;
    cin >> t;
    while(t--) {
        cin >> n >> w;
        for(int i=0; i<n; i++)  cin >> enemy[i][0];
        for(int i=0; i<n; i++)  cin >> enemy[i][1];
        vector<int> section = {enemy[0][0], enemy[0][1]};
        dp[0][0] = enemy[0][0] + enemy[0][1] <= w ? 1:2;
        dp[0][1] = dp[0][2] = 1;
        rundp();
        ans = dp[n-1][0];
        if(enemy[0][0]+enemy[n-1][0] <= w) {
            enemy[0][0] = INF;
            dp[0][0] = 2;
            dp[0][1] = dp[0][2] = 1;
            rundp();
            ans = min(ans, dp[n-1][2]);
            enemy[0][0] = section[0];
        }
        if(enemy[0][1]+enemy[n-1][1] <= w) {
            enemy[0][1] = INF;
            dp[0][0] = 2;
            dp[0][1] = dp[0][2] = 1;
            rundp();
            ans = min(ans, dp[n-1][1]); 
            enemy[0][1] = section[1];
        }
        if(enemy[0][0]+enemy[n-1][0]<=w && enemy[0][1]+enemy[n-1][1]<=w) {
            enemy[0][0] = enemy[0][1] = INF;
            dp[0][0] = 2;
            dp[0][1] = dp[0][2] = 1;
            rundp();
            ans = min(ans, dp[n-2][0]);
            enemy[0][0] = section[0];
            enemy[0][1] = section[1];
        }
        if(n == 1) {
            ans = enemy[0][1] + enemy[0][0] <= w ? 1:2;
        }
        cout << ans << endl;
    }
}