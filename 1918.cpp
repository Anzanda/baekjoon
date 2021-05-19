#include <bits/stdc++.h>
using namespace std;


int main(void){
    string str;
    cin >> str;

    stack<char> s;
    string ans;
    for(auto c : str){
        if(c >= 'A' && c <= 'Z'){
            ans.push_back(c);
        }
        else{
            if(c == ')'){
                while(s.top() != '('){
                    ans.push_back(s.top());
                    s.pop();
                }
                s.pop();
            }
            else if(c == '*' || c == '/'){
                while(!s.empty() && (s.top() == '*' || s.top() == '/')){
                    ans.push_back(s.top());
                    s.pop();
                }
                s.push(c);
            }
            else if(c == '('){
                s.push(c);
            }
            else{
                while(!s.empty() && s.top() != '('){
                    ans.push_back(s.top());
                    s.pop();
                }
                s.push(c);
            }
        }
    }   
    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }
    cout << ans;
    return 0;
}