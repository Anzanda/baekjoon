#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
bool cmp(pair<int, int> left , pair<int, int> right ) {
    return left.second < right.second;
}
int Pow(int k, int n){
    if(n==0){
        return 1;
    }
    return k*Pow(10, n-1);
}
int n;
int ans;
int main(void){
    cin >> n;

    string str;
    vector<string> v(8);
    map<char, int> m;
    for(int i=0; i<n; i++){
        cin >> str;
        int idx = 0;
        for(auto riter=str.rbegin(); riter!=str.rend(); riter++){
            v[idx] += *riter;
            idx++;
        }
    }

    for(int i=0; i<8; i++){
        if(v[i].length() == 0){
            continue;
        }
        for(int j=0; j<v[i].length(); j++){
            m[v[i][j]] += pow(10, i);
        }
    }
    vector<pair<char, int>> v2;
    copy(m.begin(), m.end(), back_inserter<vector<pair<char, int>>>(v2));
    sort(v2.begin(), v2.end(), cmp);
  
    int idx = 9;
    for(auto iter=v2.rbegin(); iter!=v2.rend(); iter++){
        m[iter->first] = idx--;
    }
    
    ans = 0;
    for(int i=0; i<8; i++){
        if(v[i].length() == 0){
            continue;
        }
        for(int j=0; j<v[i].length(); j++){
            // printf("v[%d][%d]: %c\n", i,j,v[i][j]);
            // printf("m[v[%d][%d]]: %d\n", i,j,m[v[i][j]]);
            ans += (m[v[i][j]]*Pow(10,i));
            // printf("ans: %d\n", ans);
        }
    }
    cout << ans;
    return 0;

}