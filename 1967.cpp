#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, s, d;
vector<int> v[100001];
vector<bool> visit;
vector<int> dp;
void dfs(int x){
    visit[x] = true;
    int cnt = 0;
    for(auto i: v[x]){
        if(!visit[i]){
            dfs(i);
    
            dp[x] = dp[i]+1 > dp[x] ? dp[i]+1 : dp[x];
            cnt++;
        }
    }
    if(cnt == 0){
        dp[x] = 0;
    }
}
int main(void){
    cin >> n >> s >> d;
    int a, b;
    for(int i=0; i<n-1; i++){
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    visit.resize(n+1,false);
    dp.resize(n+1, -1);
   
    dfs(s);

    int ans =0;
    for(int i=1; i<=n; i++){
        if(dp[i] >= d){
            ans +=1;
        }
    }
    ans--;
    if(ans == -1){
        ans = 0;
    }
    cout << ans*2 << endl;
    return 0;
}