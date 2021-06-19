#include <bits/stdc++.h>
#define MAXN 100000
using namespace std;

int n,s;
vector<int> v;
int main(void){
    cin >> n >> s;
    v.resize(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    
    int lidx = 0;
    int ridx = 0;
    int sum =v[0];
    int ans = INT_MAX;
    while(lidx<=ridx && ridx<n){
        if(sum > s){
            ans = ans > (ridx-lidx+1) ? (ridx-lidx+1) : ans;
            sum -= v[lidx];
            lidx++;            
        }
        else if(sum < s){
            sum += v[++ridx];
        }
        else{
            ans = ans > (ridx-lidx+1) ? (ridx-lidx+1) : ans;
            sum += v[++ridx];
        }
    }
    if(ans == INT_MAX){
        cout << 0 << "\n";
    }
    else{
        cout << ans << "\n";
    }
    return 0;
    
}