#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000000
int n;
long long dp[100][10][(1<<10)];//n,m,bit
int main(void){ios_base::sync_with_stdio(0);cin.tie(nullptr);cout.tie(nullptr);
    cin >> n;
    //init
    for(int i=1; i<10; i++){
        dp[0][i][(1<<i)] = 1;
    }
    for(int i=1; i<n; i++){
        for(int j=0; j<10; j++){
            for(int bit=0; bit<(1<<10); bit++){
                if(j==0){
                    if(bit&(1<<(j+1))){
                        dp[i][j+1][bit] = (dp[i][j+1][bit]+ dp[i-1][j][bit])%MOD;
                    }
                    else{
                        dp[i][j+1][bit+(1<<(j+1))] = (dp[i][j+1][bit+(1<<(j+1))]+ dp[i-1][j][bit])%MOD;
                    }
                }
                else if(j==9){
                    if(bit&(1<<(j-1))){
                        dp[i][j-1][bit] = (dp[i][j-1][bit]+dp[i-1][j][bit])%MOD;
                    }
                    else{
                        dp[i][j-1][bit+(1<<(j-1))] = (dp[i][j-1][bit+(1<<(j-1))]+dp[i-1][j][bit])%MOD;
                    }
                }
                else{
                    if(bit&(1<<(j+1))){
                        dp[i][j+1][bit] = (dp[i][j+1][bit]+dp[i-1][j][bit])%MOD;
                    }
                    else{
                        dp[i][j+1][bit+(1<<(j+1))] = (dp[i][j+1][bit+(1<<(j+1))]+dp[i-1][j][bit])%MOD;
                    }
                    if(bit&(1<<(j-1))){
                        dp[i][j-1][bit] = (dp[i][j-1][bit]+dp[i-1][j][bit])%MOD;
                    }
                    else{
                        dp[i][j-1][bit+(1<<(j-1))] = (dp[i][j-1][bit+(1<<(j-1))]+dp[i-1][j][bit])%MOD;
                    }
                }
            }
        }
    }
    
    long long ans = 0;
    for(int i=0; i<10; i++){
        ans = (ans+dp[n-1][i][1023])%MOD;
    }
    cout << ans << "\n";
    return 0;
}