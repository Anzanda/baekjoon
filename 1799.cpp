#include <bits/stdc++.h>
#define MAXN 10
using namespace std;

int n;
int ans, tmp;
int board[MAXN][MAXN];
bool ud[MAXN*2];//↘: x-y
bool du[MAXN*2];//↗: x+y
void dfs(int x, int y, int cnt){
    if(y >= n){
        if(y%2) y=0;
        else    y=1;
        x++;
    }
    if(x >= n){
        if(cnt > tmp){
            tmp = cnt;
        }
        return;
    }

    if(board[x][y]&&!ud[x-y+n]&&!du[x+y+1]){
       //printf("(%d, %d)\n", x, y);
       ud[x-y+n]=1;
       du[x+y+1]=1;
       dfs(x, y+2, cnt+1); 
       ud[x-y+n]=0;
       du[x+y+1]=0;
    }
    dfs(x, y+2, cnt);
}
int main(void){
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> board[i][j];
        }
    }
    dfs(0, 0, 0);
    ans += tmp;
    tmp = 0;
    dfs(0, 1, 0);
    ans += tmp;

    cout << ans << "\n";
    return 0;
}