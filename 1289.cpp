#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define FastIO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define MAX 100007
#define MOD 1000000007
#define pb push_back
#define f first
#define s second

typedef long long ll;

int n;
ll dp[MAX];
bool vst[MAX];
vector<pair<ll,ll>> v[MAX];
ll ans;
ll solve(int now, ll w) {
    vst[now] = true;
    ll ret = w;
    for(auto there: v[now]) {
        if(vst[there.f])    continue;
        ret += solve(there.f, there.s)*w;
        ret %= MOD;
    }
    dp[now] = ret;
    return ret;
}
void dfs(int now) {
    vst[now] = true;
    ll ret = 1;
    ll sum = 0;
    for(auto there: v[now]) {
        if(vst[there.f])    continue;
        dfs(there.f);
        ans += (dp[there.f]*sum)%MOD;
        sum += dp[there.f];
        sum %= MOD;
    }
}
int main(void) {
    FastIO;
    cin >> n;
    ll src, dst, w;
    for(int i=0; i<n-1; i++) {
        cin >> src >> dst >> w;
        v[src].pb({dst, w});
        v[dst].pb({src, w});
    }
    solve(1, 0);
    memset(vst, false, sizeof vst);
    dfs(1);
    for(int i=1; i<=n; i++) {
        ans += dp[i];
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}