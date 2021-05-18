#include <bits/stdc++.h>
using namespace std;

#define MAXN 2500

int n;
int ans;
vector<int> v[MAXN+1];
int c[MAXN+1];
vector<bool> visited;

void swap(int a, int b){
    int tmp = c[a];
    c[a] = c[b];
    c[b] = tmp;
}
void init(int n){
    visited[n] = true;
    for(auto there: v[n]){
        int diff;
        if(!visited[there]){
            if(v[there].size() == 1){//leaf node!
                visited[there] = true;
                diff = abs(12-c[there]);
                c[there] = 12;
                c[n] += diff;
            }   
            else{
                init(there);
                diff = abs(12-c[there]);
                c[there] = 12;
                c[n] += diff;
            }
        }
    }
    while(c[n] > 12)    c[n]-=12;

}


int main(void){iostream::sync_with_stdio(false);cin.tie(NULL);
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> c[i];
    }
    for(int i=0; i<n-1; i++){
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int tmp[MAXN+1];
    copy(c, c+MAXN+1, tmp);

    visited.resize(n+1, false);
    for(int i=1; i<=n; i++){
        visited.assign(n+1, false);
        copy(tmp, tmp+MAXN+1, c);
        init(i);
        if(c[i]==1 || c[i]==12)   ans++;

    }
    
    cout << ans;
    return 0;   
}