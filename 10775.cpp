#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define FastIO ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr)
#define MAXN 100000

int G, P;
int gate[MAXN+1];
int airplane[MAXN];
int Find(int x) {
    if(x == gate[x]) {
        return x;
    }
    return gate[x] = Find(gate[x]);
}
void Union(int x, int y) {
    x = Find(x);
    y = Find(y);
    if(x != y) {
        gate[x] = y;
    }
}
int main(void) {
    FastIO;
    cin >> G;
    cin >> P;
    for(int i=0; i<P; i++) {
        cin >> airplane[i];
    }
    for(int i=1; i<=G; i++) {
        gate[i] = i;
    }
    int ans = 0;
    for(int i=0; i<P; i++) {
        int cand = Find(airplane[i]);
        if(cand != 0) {
          ans++;
          Union(cand, cand-1);  
        } else {
            break;
        }
    }
    cout << ans << endl;
    return 0;
}