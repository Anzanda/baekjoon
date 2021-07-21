#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define FastIO ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
#define MAXN 100
#define INF 987654321

int n, m;
int card[MAXN];
int minDiff;
int tmp;
int ans;
void solve(int curr, int cnt) {
    if(cnt == 3 && tmp <= m) {
        ans = max(ans, tmp);
        return;
    }
    if(curr > n-1 || cnt > 3 || tmp > m) {
        return;
    }
    tmp += card[curr];
    solve(curr+1, cnt+1);
    tmp -= card[curr];
    solve(curr+1, cnt);
}

int main(void) {
    FastIO;
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        cin >> card[i];
    }
    minDiff = INF;
    solve(0, 0);
    cout << ans << endl;
    return 0;
}