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

    sort(v.begin(), v.end());
    
    int lidx = 0;
    int ridx = v.size()-1;

    int ans = INT_MAX;
    int sum = 0;
    while(lidx>ridx){
        
    }

    
}