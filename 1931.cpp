#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int main(void){
    int n;
    cin >> n;

    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int, int>>> pq;
    for(int i=0; i<n; i++){
        int f,l;
        cin >> f >> l;
        pq.push(make_pair(f, l));
    }

    stack<pair<int, int>> s;
    s.push(pq.top());
    pq.pop();
    while(pq.size()){
        if(pq.top().first == s.top().first){
            if(s.top().first == s.top().second){
                s.push(pq.top());
            }
            pq.pop();
            continue;
        }
        else{
            if(s.top().second <= pq.top().first){
                s.push(pq.top());
                pq.pop();
                continue;//모르겠음.
            }
            if(s.top().second <= pq.top().second){
                pq.pop();
                continue;
            }
            else{
                s.pop();//pop 언더플로우.
                s.push(pq.top());
                pq.pop();
                continue;
            }
        }
    }
    cout << s.size();
    return 0;
}