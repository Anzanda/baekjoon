#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main(void){
    ll n;
    cin >> n;
    ll start =0;
    ll end = INT32_MAX;
    ll ans =0;
    while(start<=end){
        ll mid = (start+end) >> 1;
        ans = mid - (mid/3) - (mid/5) + (mid/15);
       // printf("ans: %d\n", ans);
        if(ans < n){
            start = mid+1;
        }
        else{
            end = mid-1;
        }
    }
    cout << start;
    return 0;
}