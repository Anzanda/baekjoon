#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int maxNode;
int maxDist;
void dfs(vector<vector<pair<int,int>>> &v, vector<bool> &visited, int node, int dist){
    visited[node] = true;
    if(dist > maxDist){
        maxNode = node;
        maxDist = dist;
    }
    // cout << "Node: " << node << endl;
    // cout << "dist: " << dist << endl;
    for(auto there: v[node]){
        if(visited[there.second]){
            continue;
        }
        else{
            dfs(v, visited, there.second, dist + there.first);        
        }
    }
}

int main(void){
    int n;
    cin >> n;
    vector<vector<pair<int, int>>> v(n+1);    
    int input_int1, input_int2;
    for(int i=1; i<=n; i++){
        int vertex;
        cin >> vertex;
        while(true){
            cin >> input_int1;
            if(input_int1 == -1){
                break;
            }
            cin >> input_int2;
            v[vertex].push_back(make_pair(input_int2, input_int1));//거리, 정점으로 저장.
        }
    }

    maxNode = -1;
    maxDist = 0;
    vector<bool> visited(n+1, false);
    dfs(v, visited, 1, 0);
    
    fill(visited.begin(), visited.end(), false);

    maxDist = 0;
    dfs(v, visited, maxNode, 0);

    cout << maxDist;
    return 0;
}