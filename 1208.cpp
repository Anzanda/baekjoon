#include <bits/stdc++.h>
using namespace std;

#define MAXN 40

int n, s;
long long ans;
vector<int> v;
map<int, int> mp;
int half;
void leftDfs(int idx, int val){
    if(idx == half){
        mp[val]++;
        return;
    }
    leftDfs(idx+1, val+v[idx]);
    leftDfs(idx+1, val);
}
void rightDfs(int idx, int val){
    if(idx == n){
        ans += mp[s-val];
        return;
    }
    rightDfs(idx+1, val+v[idx]);
    rightDfs(idx+1, val);
    
}

int main(void){ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> s;
    v.resize(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }

    half = n/2;
    leftDfs(0, 0);
    rightDfs(half, 0);

    if(s == 0){
        ans--;
    }
    cout << ans << "\n";
    return 0;    
}