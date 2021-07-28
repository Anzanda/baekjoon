#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define FastIO ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr)
#define MAXN 500000

int n, m;
int p[MAXN];
int ans;
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
bool isUnion(int x, int y) {
    x = Find(x);
    y = Find(y);
    return x==y;
}
int main(void) {
    FastIO;
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        p[i] = i;
    }
    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        if(isUnion(a, b)) {
            ans = i + 1;
            break;
        } else {
            Union(a, b);
        }
    }
    cout << ans << endl;
    return 0;
}