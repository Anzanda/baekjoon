#include <bits/stdc++.h>
#define MAXN 1000000
using namespace std;

int l, r;
bool prime[MAXN+1];//false면 prime이라는 뜻.
int gcd(int a, int b){
    
    if(b == 0){
        return a;
    }else{
        return gcd(b, a%b);
    }
}
int main(void){
    cin >> l >> r;
    for(int i=2; i<=r; i++){
        if(!prime[i]){
            int j=2;
            while(j*i <= r){
                prime[j*i]=true;
                j = j + 1;
            }
        }
    }
    vector<int> v;
    for(int i=l; i<=r; i++){
        if(prime[i]){
            v.push_back(i);
        }
    }
    // for(int i=0; i<v.size(); i++){
    //     printf("v[%d]: %d\n", i , v[i]);
    // }
    long long ans = 0;
    for(int i=0; i<v.size(); i++){
        for(int j=i+1; j<v.size(); j++){
            if(gcd(v[i], v[j]) == 1 || v[j]%v[i]==0){                

            }
            else{
                ans++;
            }
        }
    }
    cout << ans*2 << "\n";
    return 0;
}