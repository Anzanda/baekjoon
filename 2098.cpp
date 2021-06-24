#include <bits/stdc++.h>
#define MAXN 16
#define INF 987654321
#define endl "\n"
using namespace std;

int n, all;
int w[MAXN][MAXN];
int dp[MAXN][1<<MAXN];
void dfs(int now, int bit) {
    if(bit == all) {
        if(w[now][0]) {
            dp[now][bit] = w[now][0];
        }
        else {
            dp[now][bit] = INF;
        }  
    }
    if(dp[now][bit] != 0) {//0이 아니라는 것은 이미 해당노드를 기준으로 탐색을 했다는 의미.
    //탐색을 했다면 무조건 최소인 값이 담겨있을 것이므로 return;을 해준다.
        return;
    }

    dp[now][bit] = INF;
    for(int i=0; i<n; i++){
        if((bit&(1<<i)) != (1<<i) && w[now][i]){
            dfs(i, bit|1<<i);
            dp[now][bit] = min(dp[now][bit], w[now][i]+dp[i][bit|1<<i]);
        }
    }
}
int main(void){
    cin >> n;
    all = (1<<n)-1;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> w[i][j];
        }
    }
    dfs(0, 1);
    cout << dp[0][1] << endl;
    
    return 0;
}