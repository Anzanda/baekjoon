#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int dfs(vector<vector<pair<int,int>>> &v, vector<bool> &visited, int node){
    visited[node] = true;
    for(auto there: v[node]){
        if(visited[there.second]){
            continue;
        }
        else{
            return there.first + dfs(v, visited, there.second);
        }
    }
    return 0;
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
        sort(v[vertex].begin(), v[vertex].end(), greater<>());
    }

    int max = 0;
    vector<bool> visited(n+1, false);
    for(int i=1; i<=n; i++){
        int tmp = dfs(v, visited, i);
        if(tmp > max){
            max = tmp;
        }
        for(int j=1; j<=n; j++){
            visited[j] = false;
        }
    }
    cout << max;
    return 0;
}