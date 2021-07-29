#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define MAX 1024
#define FastIO ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)

int n, m;
char board[MAX][MAX];
int path[MAX][MAX];
bool vst[MAX][MAX];
vector<int> group;
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};
bool isRange(int r, int c) {
    if(r < 0 || r > n-1 || c < 0 || c > m-1) {
        return false;
    }
    return true;
}
int dfs(int r, int c, int p) {
    if(!isRange(r, c)) {
        return 0;
    }
    if(vst[r][c])   return 0;
    if(board[r][c] != '0') {
        return 0;
    }
    path[r][c] = p;
    vst[r][c] = true;
    int ret = 1;
    for(int i=0; i<4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        ret += dfs(nr, nc, p);
    }
    return ret;
}
void solve(int r, int c) {
    if(path[r][c] != -1) {
        return;
    }
    group.push_back(dfs(r, c, group.size()));
}
int main(void) {
    FastIO;
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> board[i][j];
        }
    }
    memset(path, -1, sizeof path);
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(board[i][j] == '0') {
                solve(i, j);
            }
        }
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(board[i][j] == '0') {
                cout << 0;
            } else {
                int ans = 1;
                set<int> s;
                for(int k=0; k<4; k++) {
                    int nr = i + dr[k];
                    int nc = j + dc[k];
                    if(!isRange(nr, nc))    continue;
                    if(path[nr][nc] != -1) {
                        s.insert(path[nr][nc]);
                    }
                }
                for(auto it=s.begin(); it!=s.end(); it++) {
                    ans += group[*it];
                }
                cout << (ans)%10;
            }
        }
        cout << endl;
    }
    return 0;
}