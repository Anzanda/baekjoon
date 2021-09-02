#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define FastIO cin.tie(0)->sync_with_stdio(0)

const int MAX = 1e6;

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
    addSegTree(mid+1, lf, x, node*2+1, cnt);
}
int getSegTree(int lf, int rg, int node, int s, int e) {
    if(lf >= s && e >= rg) {
        return seg[node];
    }
    if(lf > e || rg < s) {
        return 0;
    }
    int mid = (lf + rg)/2;
    int lv = getSegTree(lf, mid, node*2, s, e);
    int rv = getSegTree(mid+1, rg, node*2+1, s, e);
    return lv + rv;
}
int search(int x) {
    int lf = 1;
    int rg = 1000000;
    while(lf < rg) {
        int mid = (lf + rg) / 2;
        int val = getSegTree(1, n, 1, 1, mid);
        if(val < x) {
            lf = mid+1;
        } else {
            rg = mid;
        }
    }
    return rg;
}
void solve() {
    for(int i=0; i<n; i++) {
        int state, a, b;
        cin >> state;
        if(state == 1) {
            cin >> a;
            int res = search(a);
            cout << res << endl;
            addSegTree(1, n, res, 1, -1);
        } else {
            cin >> a >> b;
            addSegTree(1, n, a, 1, b);
        }
    }
}
int main(void) {
    // FastIO;
    input();
    solve();
    return 0;
}