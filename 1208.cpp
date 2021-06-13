#include <bits/stdc++.h>
using namespace std;

int n,s;
vector<int> v;
vector<int> l;
vector<int> r;
long long ans;
int main(void){ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> n >> s;
    v.resize(n);

    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    int half = n/2;
    l.resize(1<<(n-half));
    for(int i=0; i<1<<(n-half); i++){
        for(int j=0; j<(n-half); j++){
            if(i&1<<j){
                l[i] += v[j];
            }
        }
    }    
    r.resize(1<<half);
    for(int i=0; i<1<<half; i++){
        for(int j=0; j<half; j++){
            if(i&1<<j){
                r[i] += v[j+(n-half)];
            }
        }
    }

    sort(l.begin(), l.end());
    sort(r.begin(), r.end(), greater<int>());
    
    int lidx = 0;
    int ridx = 0;
    while(lidx < 1<<(n-half) && ridx < 1<<(half)){
        if(l[lidx] + r[ridx] == s){
            long long lcnt = 1;
            long long rcnt = 1;
            lidx++;
            ridx++;
            while(lidx < 1<<(n-half) && l[lidx] == l[lidx-1]){
                lcnt++;
                lidx++;
            }
            while(ridx < 1<<half && r[ridx] == r[ridx-1]){
                rcnt++;
                ridx++;
            }
            ans += lcnt*rcnt;
        }
        else if(l[lidx] + r[ridx] > s){
            ridx++;
        }
        else{
            lidx++;
        }
    }
    if(s == 0){
        ans--;
    }
    cout << ans << "\n";
    return 0;
}