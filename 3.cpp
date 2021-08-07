#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define FastIO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define MAX 256

typedef long long ll;

int t;
int n, k;
ll score[MAX][MAX];
ll dp[MAX][MAX][MAX];
ll fin[MAX][MAX][MAX];
bool isRange(int r, int c) {
    return r >= 0 && r < n && c >= 0 && c < n;
}
ll solve(int r, int c, int k) {
    if(!isRange(r, c)) {
        return 0;
    }
    if(k <= 0) {
        return 0;
    }
    ll &ret = dp[r][c][k];
    if(ret != -1) {
        return ret;
    }
    ret = k * score[r][c];
    if(k == 1)  return ret;
    return ret += solve(r, c-1, k-1) + solve(r, c+1, k-1) - solve(r, c, k-2) - (k-2)*score[r][c];
}
ll rundp(int r, int c, int k) {
    if(!isRange(r, c)) {
        return 0;
    }
    if(k <= 0) {
        return 0;
    }
    ll &ret = fin[r][c][k];
    if(ret != -1) {
        return ret;
    }
    ret = 0;
    ret = solve(r, c, k);
    bool flag = k%2;
    for(int i=k-1; i>0; i--) {
        if(i%2 != flag) {
            ret += rundp(r-1, c, i);
            ret += rundp(r+1, c, i);
        } else {
            ret -= rundp(r, c, i)*2;
        }
    }
    return ret;
}
int main(void) {
    FastIO;
    cin >> t;
    for(int test_case=1; test_case<=t; test_case++) {
        cin >> n >> k;
        for(int i=0; i<n; i++)  for(int j=0; j<n; j++)  cin >> score[i][j];
        memset(dp, -1, sizeof dp);
        memset(fin, -1, sizeof fin);
        ll ans = -1;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                ll sum = solve(i, j, k);
                int nr = i+1;
                int nk = k - (nr - i);
                while(nr < n) {
                    nk = k - (nr - i);
                    sum += solve(i, j, nk)
                    nr++;
                }
            }
        }
        for(int i=0; i<n; i++) {
            for(int j=0; j<k; j++) {
                ans = max({ans, rundp(0, i, j), rundp(n-1,i,j)});
                ans = max({ans, rundp(i, 0, j), rundp(i, n-1, j)});
            }
        }
        cout << "Case #" << test_case << endl;
        cout << ans << endl;
    }
    return 0;
}