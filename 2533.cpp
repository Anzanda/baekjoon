#include <bits/stdc++.h>
using namespace std;

#define MAX 1000007
#define endl "\n"
#define FastIO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define pb push_back

int n;
vector<int> v[MAX];
int dp[MAX][2];//0이 꺼졌을 때, 1이 켜졌을 때.
bool vst[MAX];
void solve(int now) {
    vst[now] = true;
    dp[now][0] = 0;
    dp[now][1] = 1;//본인 켜야죠.
    for(auto there: v[now]) {
        if(vst[there])  continue;
        solve(there);
        dp[now][1] += min(dp[there][0], dp[there][1]);
        dp[now][0] += dp[there][1];
    }
}
int main(void) {
    FastIO;
    cin >> n;
    int src, dst;
    for(int i=0; i<n-1; i++) {
        cin >> src >> dst;
        v[src].pb(dst);
        v[dst].pb(src);
    }
    solve(1);
    cout << min(dp[1][0], dp[1][1]) << endl;
    return 0;
}