#include <bits/stdc++.h>
using namespace std;

#define MAXN 40000000
#define endl "\n"
#define FastIO ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr)

int n,m,k;
vector<int> card;
vector<int> target;
int p[MAXN];
int Find(int x) {
    if(x == p[x]) {
        return x;
    }
    return p[x] = Find(p[x]);
}
void Union(int x, int y) {
    x = Find(x);
    y = Find(y);
    if(x != y) {
        p[x] = y;
    }
}
int upperBound(int l, int r, int x) {
    int m;
    while(l < r) {
        m = (l + r) / 2;
        if(card[m] <= x) {
            l = m + 1;
        } else {
            r = m;
        }
    }
    return r;
}
int main(void) {
    FastIO;
    cin >> n >> m >> k;
    card.resize(m);
    for(int i=0; i<m; i++) {
        cin >> card[i];
    }
    sort(card.begin(), card.end());
    target.resize(k);
    for(int i=0; i<k; i++) {
        cin >> target[i];
    }
    for(int i=0; i<m; i++) {
        p[i] = i; 
    }
    for(int i=0; i<k; i++) {
        int idx = upperBound(0, m-1, target[i]);
        idx = Find(idx);
        Union(idx, idx+1);
        cout << card[idx] << endl;
    }
    return 0;
}