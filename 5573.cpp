#include <bits/stdc++.h>
using namespace std;

#define MAX 1024
#define endl "\n"
#define FastIO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define f first
#define s second

int h,w,n;
int field[MAX][MAX];
int dp[MAX][MAX];
pair<int,int> ans;
void stroll(int r, int c) {
    if(r == h || c == w) {
        ans.f = r;
        ans.s = c;
        return;
    }
    if(dp[r][c]%2)  field[r][c] = !field[r][c];
    if(field[r][c]) {
        stroll(r, c+1);
    } else {
        stroll(r+1, c);
    }
}
int main(void) {
    FastIO;
    cin >> h >> w >> n;
    for(int i=0; i<h; i++) {
        for(int j=0; j<w; j++) {
            cin >> field[i][j];
        }
    }
    dp[0][0] = n-1;
    for(int i=0; i<h; i++) {
        for(int j=0; j<w; j++) {
            dp[i+1][j] += dp[i][j]/2;
            dp[i][j+1] += dp[i][j]/2;
            if(dp[i][j]%2) {
                if(field[i][j]) {
                    dp[i][j+1] += 1;
                } else {
                    dp[i+1][j] += 1;
                }
            }
        }
    }
    stroll(0,0);
    cout << ans.f+1 << " " << ans.s+1 << endl;
    return 0;
}