#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000

int n;
vector<int> adj[MAXN+1];
vector<int> ans;
bool visited[MAXN+1][MAXN+1];
void printAll();
void dfs(int x){
    for(auto there: adj[x]){
        if(!visited[x][there]){
            visited[x][there]=true;
            visited[there][x]=true;
            dfs(there);
        }
    }
    ans.push_back(x);
}
int degree[MAXN+1];
int main(void){
    cin >> n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            int num;
            cin >> num;
            degree[i] += num;
            degree[j] += num;
            if(num){
                adj[i].push_back(j);
            }
        }
    }
    for(int i=1; i<=n; i++){
        degree[i] /= 2;
        if(degree[i] % 2){
            cout << -1 << '\n';
            return 0;
        }
    }
    dfs(1);
    for(auto it=ans.rbegin(); it!=ans.rend(); it++){
        cout << *it << " ";
    }
    return 0;
}

void printAll(){
    for(int i=1; i<=n; i++){
        printf("adj[%d] -> ", i);
        for(auto t: adj[i]){
            printf("%d ", t);
        }
        printf("\n");
    }
}