#include <bits/stdc++.h>
#define MAXN 16
using namespace std;

int n;
int w[MAXN][MAXN];
int dp[MAXN][(1<<MAXN)];
void Print(int bit){
    printf(" bit: ");
    int mask;
    for(int i=n-1; i>=0; i--){
        mask = bit&(1<<i);
        cout << (mask>0);
    }
    cout << endl;
}
// void dfs(int now, int bit){
//     // cout << "now: " << now;
//     // Print(bit);
//     if(bit&(1)){
//         return;
//     }
//     for(int i=0; i<n; i++){
//         int mask = bit&(1<<i);
//         if(w[now][i] && mask == 0){
//             int tmp = dp[bit] + w[now][i];
//             if(tmp < dp[bit+(1<<i)]){
//                 dp[bit+(1<<i)] = tmp;
//                 dfs(i, bit+(1<<i));
//             }
//         }
//     }
// }
int dfs(int now, int bit){
    if(bit == (1<<n)-1){
        if(!w[now][0])  return INT_MAX;
        else    return w[now][0];
    }
    if(dp[now][bit] != -1){
        return dp[now][bit];
    }
    dp[now][bit] = INT_MAX;
    for(int i=0; i<n; i++){
        if(w[now][i] == 0)  continue;
        if((bit&(1<<i)) == (1<<i))    continue;

        dp[now][bit] = min(dp[now][bit], w[now][i]+dfs(i,bit|(1<<i)));
    }
    return dp[now][bit];
}
int main(void){
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> w[i][j];
        }
    }
    memset(dp, -1, sizeof(dp));
    cout << dfs(0, 1) << "\n";
    return 0;
}