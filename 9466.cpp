#include <bits/stdc++.h>
using namespace std;

#define MAXN 100000
#define endl "\n"
#define FastIO ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr)

int T;
int n;
int student[MAXN+1];
bool fin[MAXN+1];
bool vst[MAXN+1];
int c[MAXN+1];
int ans;
void dfs(int now, int cnt) {
    vst[now] = true;
    c[now] = cnt;
    int next = student[now];
    if(!vst[next]) {
        dfs(next, cnt+1);
    } else if(!fin[next]) {
        //cycle
        ans += cnt + 1 - c[next];
    }
    fin[now] = true;
}
int main(void) {
    FastIO;
    cin >> T;
    while(T--) {
        memset(fin, false, sizeof fin);
        memset(vst, false, sizeof vst);
        memset(c, 0, sizeof c);
        ans = 0;
        cin >> n;
        for(int i=1; i<=n; i++) {
            cin >> student[i];
        }
        for(int i=1; i<=n; i++) {
            if(!vst[i]) {
                dfs(i, 0);
            }
        }
        cout << n - ans << endl;
    }
    return 0;
}