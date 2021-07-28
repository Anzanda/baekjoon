#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000
#define endl "\n"
#define FastIO ios_base::sync_with_stdio(false),cout.tie(nullptr),cin.tie(nullptr)

int n, m;
int p[MAXN*MAXN];
char f[MAXN][MAXN];
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
    return x == y;
}
bool isRange(int r, int c) {
    if(r < 0 || r > n-1 || c < 0 || c > m-1) {
        return false;
    }
    return true;
}
int main(void) {
    FastIO;
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> f[i][j];
        }
    }
    for(int i=0; i<n*m; i++) {
        p[i] = i;
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            int src = i * m + j;
            if(f[i][j] == 'D') {
                if(isRange(i+1,j)) {
                    int dst = (i+1) * m + j; 
                    Union(src , dst);
                }
            } else if(f[i][j] == 'U') {
                if(isRange(i-1, j)) {
                    int dst = (i - 1) * m + j;
                    Union(src, dst);
                }
            } else if(f[i][j] == 'L') {
                if(isRange(i, j-1)) {
                    int dst = i * m + (j-1);
                    Union(src, dst);
                }
            } else {
                if(isRange(i, j+1)) {
                    int dst = i * m + (j+1);
                    Union(src, dst);
                }
            }
        }
    }
    map<int, int> map;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            int idx = i * m + j;
            map[Find(idx)]++;
        }
    }
    cout << map.size() << endl;
    return 0;
}