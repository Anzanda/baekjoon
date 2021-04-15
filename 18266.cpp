#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
// 1 <= L <= 10^9
// 1 <= N <= 5*10^4
// 1 <= w <= 10^3
vector<int> w, x, d;
int main(void){
    int n, len;
    cin >> n >> len;    
    
    int weight_tot=0;
    w.resize(n);x.resize(n);d.resize(n);
    for(int i=0; i<n; i++){
        cin >> w[i] >> x[i] >> d[i];
        weight_tot+=w[i];
    }

    vector<int> inds(n); iota(inds.begin(), inds.end(), 0);
    sort(inds.begin(), inds.end(), [](int a, int b) { return x[a] < x[b];});
    vector<int> W,X,D;
    for(auto t: inds){
        W.push_back(w[t]);
        X.push_back(x[t]);
        D.push_back(d[t]);
    }
    swap(w, W);swap(x, X);swap(d, D);

    vector<int> left, right;
    for(int i=0; i<n; i++){
        if(d[i] == -1){
            left.push_back(x[i]);
        }   
        else{
            right.push_back(x[i]);
        }
    }

    vector<pair<int, int>> v;
    for(int i=0; i<left.size(); i++){
        v.push_back({left[i], w[i]});
    }
    for(int i=0; i<right.size(); i++){
        v.push_back({len - right[i], w[left.size()+i]});
    }

    int time = 0;
    sort(v.begin(), v.end());
    for(auto t: v){
        weight_tot -= 2*t.s;
        if(weight_tot <= 0){
            time = t.f;
            break;
        }
    }
    
    int collision=0;
    queue<int> tmp;
    for(int i=0; i<n; i++){
        if(d[i] == -1){
            while(tmp.size() && tmp.front()<x[i]-2*time){
                tmp.pop();
            }
            collision+=tmp.size();
        }
        else{
            tmp.push(x[i]);
        }
    }
    cout << collision;
    return 0;
}