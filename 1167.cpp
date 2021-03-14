#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){
    int n;
    cin >> n;
    vector<vector<pair<int, int>>> v(n+1);    
    vector<int> in(n+1, 0);
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
            in[vertex]++;
            in[input_int1]++;
        }
        sort(v[i].begin(), v[i].end(), greater<>());
    }
    int start = 1;
    for(int i=2; i<=n; i++){
        if(in[i] < in[start] && in[i]!=0){
            start = i;
        }
    }
    
    queue<pair<int, int>> q;
    vector<bool> visited(n+1, false);
    vector<int> dp(n+1, 0);
    q.push(make_pair(start, -1));
    dp[start] = 0;
    int count = 0;
    while(q.size()){
        count++;
        pair<int, int> here = q.front();
        q.pop();

        if(visited[here.first])   continue;

        visited[here.first] = true;     //here.first -> index here.second->부모.
        for(auto there: v[here.first]){//there.first -> 거리 there.second -> index
            if(there.second == here.second) continue;            
            q.push(make_pair(there.second, here.first));
            if(dp[there.second] < dp[here.first] + there.first){
                dp[there.second] = dp[here.first] + there.first;
            }
        }
    }
    cout << *max_element(dp.begin(), dp.end());
    return 0;
}