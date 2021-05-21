#include <bits/stdc++.h>
#define MAXN (int)1e+6
using namespace std;

int n;
int dp[MAXN+1];
int disjoint[MAXN+1];
void print(int x){
    if(x == -1)   return;
    cout << x << " ";
    print(disjoint[x]);
}
int main(void){iostream::sync_with_stdio(false);cin.tie(nullptr);
    cin >> n;

    dp[1] = 0;
    disjoint[1] = -1;
    for(int i=2; i<=n; i++){
        dp[i] = dp[i-1] + 1;
        disjoint[i] = i-1;
        if(i%3 == 0){
            if(dp[i] > dp[i/3]+1){
                dp[i] = dp[i/3]+1;
                disjoint[i] = i/3;
            }
        }
        if(i%2 == 0){
            if(dp[i] > dp[i/2]+1){
                dp[i] = dp[i/2]+1;
                disjoint[i] = i/2;
            }
        }
    }
    cout << dp[n] << endl;
    print(n);
    return 0;
}