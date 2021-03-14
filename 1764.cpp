#include <iostream>
#include <set>
#include <string>
using namespace std;

int main(void){//ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    set<string> s, f;
    int n, m;
    cin >> n >> m;
    string input_string;
    for(int i=0; i<n; i++){
        cin>>input_string;
        s.insert(input_string);
    }

    int count = 0;
    for(int i=0; i<m; i++){
        cin >> input_string;
        if(s.find(input_string) != s.end()){
            count++;
            f.insert(input_string);
        }
    }
    cout << count << '\n';
    for(auto iter = f.begin(); iter != f.end(); iter++){
        cout << *iter << '\n';
    }
    return 0;
}