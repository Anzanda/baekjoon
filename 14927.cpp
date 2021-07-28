#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define FastIO ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr)
#define MAXN 18
#define INF 987654321

int n;
int bulb[MAXN][MAXN];
int tmp[MAXN][MAXN];
int dr[4] = {1, 0, -1, 0};
int dc[4] = {0, 1, 0, -1};
int ans;
int cnt;
bool isRange(int r, int c) {
    if(r < 0 || r > n-1 || c < 0 || c > n-1) {
        return false;
    }
    return true;
}
bool isOn(int r, int c) {
    return bulb[r][c];
}
void turnOn(int r, int c) {
    if(!isRange(r, c))  return;
    if(isOn(r, c)) {
        bulb[r][c] = 0;
    } else {
        bulb[r][c] = 1;
    } 
}
void change(int r, int c) {
   turnOn(r,c);
   for(int i=0; i<4; i++){ 
       int nr = r + dr[i];
       int nc = c + dc[i];
       turnOn(nr, nc);
   } 
}
void solve(int r, int c) {
    if(r == n) {
        return;
    }
    if(isOn(r-1, c)) {
        change(r, c);
        cnt++;
    }
    if(isRange(r, c+1)) {
        solve(r, c+1);
    } else {
        solve(r+1, 0);
    }
}
int main(void){
    FastIO;
    cin >> n;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> bulb[i][j];
        }
    }
    memcpy(tmp, bulb, sizeof(bulb));
    ans = INF;
    for(int i=0; i<(1<<n); i++) {
       memcpy(bulb, tmp, sizeof(tmp));
       cnt = 0;
       for(int j=0; j<n; j++) {
           if(i&(1<<j)) {
              change(0, j);
              cnt++; 
           }
       }
       solve(1, 0);
       for(int j=0; j<n; j++) {
           if(isOn(n-1, j)) {
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