#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define MAX 128
#define FastIO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
typedef __int128 ll;

const ll MOD = 1e9+7;
int n, l, r;
ll comb[MAX][MAX];
ll dp[MAX][MAX];
ll combinate(int r, int c) {
    ll& ret = comb[r][c];
    if(ret != -1) {
        return ret;
    }
    if(c == 0 || c == r) {
        return ret = 1;
    }
    return ret = (combinate(r-1, c-1)%MOD + combinate(r-1, c)%MOD)%MOD;
}
ll factorial(int n) {
    if(n == 0) {
        return 1;
    }
    return n*factorial(n-1)%MOD;
}
ll rundp(int r, int c) {
    ll& ret = dp[r][c];
    if(ret != -1) {
        return ret;
    }
    if(c == r) {
        return ret = 1;
    }
    if(c > r || c < 1) {
        return ret = 0;
    }
    if(c == 1) {
        return ret = factorial(r-1);
    }
    ret = 0;
    for(int i=c-1; i<=r-1; i++) {
        ll tmp = combinate(r-1,i)%MOD;
        tmp *= rundp(i, c-1)%MOD;
        tmp *= factorial(r-1-i)%MOD;
        ret += tmp;
        ret %= MOD;
    }
    return ret%MOD;
}
int main(void) {
    cin >> n >> l >> r;
    ll ans = 0;
    memset(dp, -1, sizeof dp);
    memset(comb, -1, sizeof comb);
    for(int i=0; i<n; i++) {
        ll tmp = combinate(n-1, i)%MOD;
        tmp *= rundp(i, l-1)%MOD;
        tmp *= rundp(n-1-i, r-1)%MOD;
        ans += tmp;
        ans %= MOD;
    }
    int qwe = ans;
    cout << qwe << endl;
    return 0;
}