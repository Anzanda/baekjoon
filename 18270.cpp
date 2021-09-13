#include <bits/stdc++.h>
using namespace std;

#define FastIO cin.tie(0)->sync_with_stdio(0)
#define endl "\n"
#define pb push_back

int n;
vector<string> arr;
map<string, int> m;
vector<int> adj[9];
void init() {
    arr = {"Bessie", "Buttercup", "Belinda",
    "Beatrice", "Bella", "Blue", "Betsy", "Sue"};
    sort(arr.begin(), arr.end());
    for(int i=0; i<8; i++) {
       m[arr[i]] = i; 
    }
}
vector<string> split(string str) {
    vector<string> ret;
    int idx = 0;
    while(str[idx] != ' '){
        idx++;
    }
    ret.pb(str.substr(0, idx));
    idx = str.size()-1;
    while(str[idx] != ' ')  idx--;
    ret.pb(str.substr(idx+1));
    return ret;
}
void input() {
    cin >> n;
    getchar();
    for(int i=0; i<n; i++) {
        string str;
        getline(cin, str);
        vector<string> str_arr = split(str);
        string a = str_arr[0];
        string b = str_arr[1];
        adj[m[a]].pb(m[b]); 
        adj[m[b]].pb(m[a]);
    }
}
void solve() {
    vector<int> v(8);
    iota(v.begin(), v.end(), 0);
    bool finished = false;
    do {
        finished=true;
        for(int i=0; i<8; i++) {
            if(adj[v[i]].empty())  continue;
            int complete = 0;
            for(auto elem: adj[v[i]]) {
                if(i == 0) {
                    if(elem == v[i+1]) {
                        complete++;
                    }
                } else if(i == 7) {
                    if(elem == v[i-1]) {
                        complete++;
                    }
                } else {
                    if(elem == v[i-1] || elem == v[i+1]) {
                        complete++;
                    }
                }
            }
            if(complete != adj[v[i]].size()) {
                finished = false; 
            }
        }
    }while(!finished && next_permutation(v.begin(), v.end()));
    for(auto elem: v) {
        cout << arr[elem] << endl;
    }
}
int main(void) {
    // FastIO;
    init();
    input();
    solve();
    return 0;
}