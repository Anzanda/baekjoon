#include <bits/stdc++.h>
using namespace std;
#define MAXN 100000
#define f first
#define s second
#define pb push_back
int n, m, k;
vector<int> disjoint(MAXN+1);
vector<int> cycle[MAXN+1];
vector<int> pos(MAXN+1);
int main(void){//ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n >> m >> k;

    vector<pair<int, int>> range(m);
    for(int i=0; i<m; i++){
        int l , r;
        cin >> range[i].f >> range[i].s;
    }
    
    vector<int> v(n+1);
    for(int i=1; i<=n; i++){
        int idx = i;
        for(auto it=range.begin(); it!=range.end(); it++){
            if(it->f <= idx && it->s >= idx){
                idx = it->f+it->s - idx;
            }
        }
        v[i] = idx;
    }
    
    
    for(int i=1; i<=n; i++){
        if(!disjoint[i]){

            disjoint[i]=i;
            cycle[i].push_back(i);
            pos[i] = 0;
            int j = v[i];

            if(j != i)  pos[j]=1;
            while(j != i){
                disjoint[j] = i;
                cycle[i].push_back(j);
                if(v[j] != i){
                    pos[v[j]] = pos[j] + 1;
                }
                j = v[j];
            }
        }
    }
    
    vector<int> tmp(n+1);
    for(int i=1; i<=n; i++){
        tmp[cycle[disjoint[i]][(pos[i]+k)%cycle[disjoint[i]].size()]]=i;
    }
    for(int i=1; i<=n; i++){
        cout << tmp[i] << "\n";
    }
    return 0;
}