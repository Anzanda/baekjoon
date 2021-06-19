#include <bits/stdc++.h>
#define MAXN 2*100000
using namespace std;

int n;
int arr[MAXN];
bool visited[MAXN+1];
int parent[MAXN+1];
map<int, int> m;
int Find(int x){
    if(x == parent[x]){
        return x;
    }
    return parent[x] = Find(parent[x]);//최적화 안하는 게 맞겠지?
}
void Union(int x, int y){
    x = Find(x);
    y = Find(y);
    if(x!=y){
        parent[x] = y;
    }
}
int main(void){ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    long long ans = 0;
    for(int i=0; i<=MAXN; i++){
        parent[i] = i;
    }
    for(int i=0; i<n; i++){
        if(arr[i] == arr[n-1-i]){

        }
        else{
            Union(arr[i], arr[n-1-i]);
        }
    }
    for(int i=1; i<=MAXN; i++){
        int tmp = Find(i);
        if(tmp!=i){
            m[tmp]++;
        }
    }
    for(auto iter=m.begin(); iter!=m.end(); iter++){
        ans += iter->second;
    }
    cout << ans << "\n";
    return 0;
}