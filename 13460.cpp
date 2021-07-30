#include <bits/stdc++.h>
using namespace std;

#define MAX 10
#define endl "\n"
#define FastIO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define INF 987654321
#define f first
#define s second

int n, m;
bool up(vector<vector<char>> &tmp, pair<int ,int> &p) {
    tmp[p.f][p.s] = '.';
    while(p.f >= 0) {
        if(tmp[p.f][p.s] == '#' || tmp[p.f][p.s] == 'G') {
            break;
        }
        if(tmp[p.f][p.s] == 'O') {
            return true;
        } 
        p.f--;
    }
    tmp[++p.f][p.s] = 'G';
    return false;
}
bool down(vector<vector<char>> &tmp, pair<int, int> &p) {
    tmp[p.f][p.s] = '.';
    while(p.f < n) {
        if(tmp[p.f][p.s] == '#' || tmp[p.f][p.s] == 'G') {
            break;
        }
        if(tmp[p.f][p.s] == 'O') {
            return true;
        }
        p.f++;
    }
    tmp[--p.f][p.s] = 'G';
    return false;
}
bool left(vector<vector<char>> &tmp, pair<int, int> &p) {
    tmp[p.f][p.s] = '.';
    while(p.s >= 0) {
        if(tmp[p.f][p.s] == '#' || tmp[p.f][p.s] == 'G') {
            break;
        }
        if(tmp[p.f][p.s] == 'O') {
            return true;
        }
        p.s--;
    }
    tmp[p.f][++p.s] = 'G';
    return false;
}
bool right(vector<vector<char>> &tmp, pair<int ,int> &p) {
    tmp[p.f][p.s] = '.';
    while(p.s < m) {
        if(tmp[p.f][p.s] == '#' || tmp[p.f][p.s] == 'G') {
            break;
        }
        if(tmp[p.f][p.s] == 'O') {
            return true;
        } 
        p.s++;
    }
    tmp[p.f][--p.s] = 'G';
    return false;
}
int terminal(int dir, vector<vector<char>> &tmp, pair<int, int> &b, pair<int, int> &r) {
    switch(dir) {
        case 0:
            if(b.s == r.s) {
                if(b.f < r.f) {
                    if(up(tmp, b)) {
                        return -1;
                    } else {
                        return up(tmp, r);
                    }
                } else {
                    int ret = up(tmp, r);
                    if(up(tmp,b)) {
                        return -1;
                    }
                    return ret;
                }
            } else {
                if(up(tmp, b)) {
                    return -1;
                } else {
                    return up(tmp,r);
                }
            }
            break;
        case 1:
            if(b.s == r.s) {
                if(b.f > r.f) {
                    if(down(tmp, b)) {
                        return -1;
                    } else {
                        return down(tmp, r);
                    }
                } else {
                    int ret = down(tmp, r);
                    if(down(tmp, b)) {
                        return -1;
                    }
                    return ret;
                }
            } else {
                if(down(tmp, b)) {
                    return -1;
                } else {
                    return down(tmp, r);
                }
            }
            break;
        case 2:
            if(b.f == r.f) {
                if(b.s < r.s) {
                    if(left(tmp, b)) {
                        return -1;
                    }
                    return left(tmp, r);
                } else {
                    int ret = left(tmp, r);
                    if(left(tmp, b)) {
                        return -1;
                    } 
                    return ret;
                }
            } else {
                if(left(tmp, b)) {
                    return -1;
                }
                return left(tmp, r);
            }
            break;
        case 3:
            if(b.f == r.f) {
                if(b.s > r.s) {
                    if(right(tmp, b)) {
                        return -1;
                    }
                    return right(tmp, r);
                } else {
                    int ret = right(tmp, r);
                    if(right(tmp, b)) {
                        return -1;
                    }
                    return ret;
                }
            } else {
                if(right(tmp, b)) {
                    return -1;
                } 
                return right(tmp, r);
            }
            break;
    }
    return 1;
}
int ans;
void printBoard(vector<vector<char>> board);
void solve(int now, vector<vector<char>> board, pair<int ,int> blue, pair<int,int> red) {
    if(now == 10) {
        return;
    } 
    // cout << now << endl;
    // printBoard(board);
    for(int i=0; i<4; i++) {
        vector<vector<char>> tmp = board;
        pair<int, int> b = blue;
        pair<int, int> r = red;
        int jud = terminal(i, tmp, b, r);    
        if(jud < 0)     continue;
        if(jud == 0)    solve(now+1, tmp, b, r);
        if(jud > 0) {
            ans = min(ans, now);
            return;
        }
    }
}
void printBoard(vector<vector<char>> board) {
    cout << endl;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cout << board[i][j];
        }
        cout << endl;
    }
}
int main(void) {
    FastIO;
    cin >> n >> m;
    vector<vector<char>> board(n, vector<char>(m));
    pair<int, int> red;
    pair<int, int> blue;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> board[i][j];
            if(board[i][j] == 'R') {
                red = {i, j};
                board[i][j] = 'G';
            } 
            if(board[i][j] == 'B') {
                blue = {i, j};
                board[i][j] = 'G';
            }
        }
    }
    ans = INF;
    solve(0, board, blue, red);
    if(ans == INF)  ans = -2;
    cout << ans+1 << endl;
    return 0;
}