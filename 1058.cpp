#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define FastIO cin.tie(0)->sync_with_stdio(0)

const int MAX = 50;

int n;
int g[MAX][MAX];
int ans[MAX];
void input() {
    cin >> n;
    for(int i=0; i<n; i++) {
        string s;
        cin >> s;
        for(int j=0; j<n; j++) {
            if(s[j] == 'Y') {
                g[i][j] = 1;
            }
        }
    }
}
bool vst[MAX];
void solve() {
    for(int i=0; i<n; i++) {
        memset(vst, 0, sizeof vst);
        vst[i] = true;
        for(int j=0; j<n; j++) {
            if(g[i][j]) {
                vst[j] = true;
                ans[i]++;
            }
        }
        for(int j=0; j<n; j++) {
            if(g[i][j]) {
                for(int k=0; k<n; k++) {
                    if(g[j][k] && !vst[k]) {
                        vst[k] = true;
                        ans[i]++;
                    }
                }
            }
        }
    }
    cout << *max_element(ans, ans+n) << endl;
}
int main(void) {
    FastIO;
    input();
    solve();
    return 0;
}