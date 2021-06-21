#include <bits/stdc++.h>
using namespace std;

int r,c;
string arr[20];
bool vst[26];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int ans;
int alpha2int(char c){
    return c-65;
}
void dfs(int x, int y, int cnt){
    if(x<0||x>r-1||y<0||y>c-1){
        return;
    }
    if(vst[alpha2int(arr[x][y])]){
        return;
    }
    vst[alpha2int(arr[x][y])] = true;
    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        dfs(nx, ny, cnt+1);
    }
    vst[alpha2int(arr[x][y])] = false;
    ans = ans > cnt ? ans : cnt;
}
int main(void){
    cin >> r >> c;
    for(int i=0; i<r; i++){
        cin >> arr[i];
    }

    dfs(0,0,0);
    cout << ans+1 << "\n";
    return 0;
}