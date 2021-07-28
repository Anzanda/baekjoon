#include <bits/stdc++.h>
using namespace std;

#define MAXN 10
#define endl "\n"
#define FastIO ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr)
#define INF 987654321

char bulb[MAXN][MAXN];
char tmp[MAXN][MAXN];
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};
int ans;
int cnt;
bool isRange(int r, int c) {
    if(r < 0 || r > 9 || c < 0 || c > 9) {
        return false;
    }
    return true;
}
bool isOn(int r, int c) {
    if(bulb[r][c] == 'O') {
        return true;
    }
    return false;
}
void change(int r, int c) {
    if(!isRange(r, c))  return;
    if(isOn(r, c)) {
        bulb[r][c] = '#';
    } else {
        bulb[r][c] = 'O';
    }
}
void button(int r, int c) {
    if(!isRange(r,c))   return;
    change(r,c);
    for(int i=0; i<4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        change(nr, nc);
    }
}
void solve(int r, int c) {
    if(r == 10) {
        return;
    }
    if(isOn(r-1, c)) {
        cnt++;
        button(r, c);
    }
    if(isRange(r, c+1)) {
        solve(r, c+1);
    } else {
        solve(r+1, 0);
    }
}
int main(void) {
    FastIO;
    for(int i=0; i<MAXN; i++) {
       for(int j=0; j<MAXN; j++) {
           cin >> bulb[i][j];
       } 
    }
    ans = INF;
    memcpy(tmp, bulb, sizeof(bulb));
    for(int i=0; i<1024; i++) {
        memcpy(bulb, tmp, sizeof(tmp));
        cnt = 0;
        for(int j=0; j<10; j++) {
            if(i&(1<<j)) {
                button(0, j);
                cnt++;
            }
        }
        solve(1, 0);
        for(int j=0; j<10; j++) {
            if(isOn(9, j)) {
                cnt = INF;
                break;
            }
        }
        ans = min(ans, cnt);
    }
    if(ans == INF)  ans = -1;
    cout << ans << endl;
    return 0;
}