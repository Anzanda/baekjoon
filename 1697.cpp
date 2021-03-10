#include <iostream>
#include <queue>
using namespace std;

int n,k;
int main(void){
    cin >> n >> k;
    vector<int> dp(200001, 100001);
    queue<int> q;
    q.push(n);
    dp[n] = 0;
    while(q.size()){
        int cur;
        cur = q.front();
        q.pop();
        if(cur > k){
            if(dp[cur-1] > dp[cur] + 1){
                dp[cur-1] = dp[cur] + 1;
                q.push(cur-1);
            }
        }
        else if(cur < k){
            if(dp[cur*2] > dp[cur] + 1){
            dp[cur*2] = dp[cur] + 1;
            q.push(cur*2);
            }
            if(dp[cur+1] > dp[cur] + 1){
                dp[cur+1] = dp[cur] + 1;
                q.push(cur+1);
            }
            if(!cur)    continue;
            if(dp[cur-1] > dp[cur] + 1){
                dp[cur-1] = dp[cur] +1;
                q.push(cur-1);
            }
        }
        else{
            break;
        }
    }
    cout << dp[k];
    return 0;
}