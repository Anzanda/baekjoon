#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define MAX 1000
#define FastIO ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0)

int n, m;
char board[MAX][MAX];
bool path[MAX][MAX];
bool vst[MAX][MAX];
int ans[MAX][MAX];
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};
bool isRange(int r, int c) {
    if(r < 0 || r > n-1 || c < 0 || c > m-1) {
        return false;
    }
    return true;
}
int dfs(int r, int c) {
    if(!isRange(r, c)) {
        return 0;
    }
    if(path[r][c])    return 0;
    if(board[r][c] != '0') {
        return 0;
    }
    path[r][c] = true;
    int ret = 1;
    for(int i=0; i< 4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        ret += dfs(nr, nc);
    }

    return ret;
}
void update(int r, int c, int cnt) {
    if(!isRange(r, c))  return;
    if(vst[r][c])   return;
    vst[r][c] = true;
    if(board[r][c] != '0') {
        ans[r][c] += cnt;
        return;
    }
    for(int i=0; i<4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        update(nr, nc, cnt);
    }
}
void solve(int r, int c) {
    if(path[r][c])  return;
    memset(vst, false, sizeof vst);
    int cnt = dfs(r,c);
    // cout << "(" << r << "," << c << ")" << ": " << cnt << endl;
    update(r, c, cnt);
}
int main(void) {
    FastIO;
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> board[i][j];
        }
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(board[i][j] == '0') {
                solve(i, j);
            } else {
                ans[i][j] += 1;
            }
        }
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cout << ans[i][j];
        }
        cout << endl;
    }
}