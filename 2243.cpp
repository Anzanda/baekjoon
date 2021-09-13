#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define FastIO cin.tie(0)->sync_with_stdio(0)

const int MAX = 1e6+7;

int n;
int seg[4*MAX];
void input() {
    cin >> n;
}
void addSegTree(int lf, int rg, int x, int node, int cnt) {
    if(lf > rg) return;
    if(lf > x || rg < x) return;
    seg[node] += cnt;
    if(lf == rg) {
        return;
    } 
    int mid = (lf + rg) / 2;
    addSegTree(lf, mid, x, node*2, cnt);
    addSegTree(mid+1, rg, x, node*2+1, cnt);
}
int query(int node, int x, int lf, int rg) {
    if(lf == rg) {
        return lf;
    } 
    int mid = (lf + rg) / 2;
    if(x <= seg[node*2]) {
        return query(node*2, x, lf, mid);
    } else {
        return query(node*2+1, x-seg[node*2], mid+1, rg);
    }
}
void solve() {
    for(int i=0; i<n; i++) {
        int state, a, b;
        cin >> state;
        if(state == 1) {
            cin >> a;
            int res = query(1, a, 1, MAX);
            cout << res << endl;
            addSegTree(1, MAX, res, 1, -1);
        } else {
            cin >> a >> b;
            addSegTree(1, MAX, a, 1, b);
        }
    }
}
int main(void) {
    FastIO;
    input();
    solve();
    return 0;
}