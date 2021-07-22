#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define MAXN 500
#define FastIO ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr)
#define INF 987654321
typedef long long int ll;

int n;
int r, c;
pair<int, int> matrix[MAXN];
ll dp[MAXN][MAXN];
int solve(int l, int r) {
    if(l == r) {
        return 0;
    }
    if(dp[l][r] != -1) {
        return dp[l][r];
    }
    dp[l][r] = INF;
    for(int i=l; i<r; i++) {
        dp[l][r] = min(dp[l][r], solve(l, i) + solve(i+1, r) +
        (ll)matrix[l].first*matrix[i].second*matrix[r].second);
    }
    return dp[l][r];
}
int main(void) {
    FastIO;
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> r >> c;
        matrix[i] = {r, c};
    }
    memset(dp, -1, sizeof(dp));
    cout << solve(0, n-1) << endl;
    return 0;
}