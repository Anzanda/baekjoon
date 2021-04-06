#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main(void){
    ll n;
    cin >> n;
    ll start =0;
    ll end = INT32_MAX;
    ll ans =0;
    while(1){
        ll mid = (start+end) >> 1;
        ans = mid - (mid/3) - (mid/5) + (mid/15);
       // printf("ans: %d\n", ans);
        if(ans < n){
            start = mid+1;
        }
        else if(ans > n){
            end = mid-1;
        }
        else{
           // printf("before mid: %d\n", mid);
            while(mid%3==0 || mid%5==0) mid--;
            printf("%d", mid);
            break;
        }
        
    }
    return 0;
}