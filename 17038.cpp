#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define FastIO cin.tie(0)->sync_with_stdio(0)

const int MX = 1e5+5;

int n, m;
int p[MX];
int find(int x) {
    if(x == p[x])   return x;
    return p[x] = find(p[x]);
}
void Union(int x, int y) {
    x = find(x);
    y = find(y);
    if(x != y)  p[y] = x;
}
int main(void) {
    cin >> n >> m;
    iota(p, p+n+1, 0);
    for(int i=0; i<m; i++) {
        char type;
        int fav1, fav2;
        cin >> type >> fav1 >> fav2;
        Union(fav1, fav2);
    }
    set<int> s;
    for(int i=1; i<=n; i++) {
        s.insert(p[i]); 
    }
    cout << s.size() << endl;
    return 0;
}