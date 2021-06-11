#include <bits/stdc++.h>
using namespace std;

int n, k;
long long ans;    
vector<pair<int, int>> jew;
vector<int> bag;
int main(void){
    cin >> n >> k;
    
    jew.resize(n+1);
    bag.resize(k+1);
    for(int i=0; i<n; i++){
        int m,v;//무게, 가격.
        cin >> m >> v;
        jew[i] = {m,v};
    }
    
    for(int i=0; i<k; i++){
        int m;
        cin >> m;//배낭 최대 무게.
        bag[i] = m;
    }

    sort(jew.begin(), jew.end(), less<>());
    sort(bag.begin(), bag.end(), less<>());
    
    vector<pair<int,int>>::iterator jew_iter = jew.begin();
    vector<int>::iterator bag_iter = bag.begin();
    priority_queue<int> pq;
    while(bag_iter != bag.end()){
        while(jew_iter != jew.end() && jew_iter->first <= *bag_iter){
            pq.push(jew_iter->second);
            jew_iter++;    
        }
        if(!pq.empty()){
            ans += pq.top();
            pq.pop();
        }
        bag_iter++;
    }
    
    cout << ans << "\n";
    return 0;
}