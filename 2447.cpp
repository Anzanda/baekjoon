#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define FastIO ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr)
#define MAXN 2187

int n;
char star[MAXN][MAXN];
void solve(int r, int c, int cnt) {
    if(cnt == 0) {
        star[r][c] = '*';
        return;
    }
    int jump = pow(3, cnt-1);
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            if(i==1 && j==1)    continue;
            solve(r+jump*i, c+jump*j, cnt-1);
        }
    }
}
int main(void) {
    FastIO;
    cin >> n;
    int count = 0;
    int tmp = n;
    while(n!=0) {
        n/=3;
        count++;
    }
    memset(star, ' ', sizeof(star));
    solve(0, 0, count-1);
    for(int i=0; i<tmp; i++) {
        for(int j=0; j<tmp; j++) {
            cout << star[i][j];
        }
        cout << endl;
    }
    return 0;
}
