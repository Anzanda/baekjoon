#include <iostream>
#include <set>
#include <unordered_set>
using namespace std;

int t,n;
int main(void){
    
    cin >> t;
    while(t--){
        unordered_set<string> s;
        cin >> n;
        for(int i=0; i<n; i++){
            string str;
            cin >> str;
            s.insert(str);
        }

        bool flag = false;
        for(auto iter = s.begin(); iter!= s.end() && !flag; iter++){
            string cur = "";
            for(auto it = iter->begin(); it!=iter->end(); it++){
                cur += *it;
                if(s.find(cur) != s.end()){
                    if(cur == *iter)    break;
                    flag = true;
                    break;
                }
            }
        }
        if(flag)    cout << "NO\n";
        else        cout << "YES\n";
    }
}