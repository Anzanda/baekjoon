#include <iostream>
#include <stack>
using namespace std;

int n;
long long max(long long a, long long b){
    return a>b?a:b;
}
int main(void){ios::sync_with_stdio(false);cin.tie(NULL);
    cin >> n;
    stack<pair<int, long long>> s;
    long long ans = 0;
    int num;
    long long tmp;
    for(int i=0; i<n; i++){
        cin >> num;

        tmp = 0;
        while(!s.empty() && s.top().first > num){//°°À¸¸é???
            tmp += s.top().second;
            ans = max(ans, tmp * s.top().first);
            s.pop();
        }
        tmp += num;
        s.emplace(num, tmp);
    }
    tmp = 0;
    while(!s.empty()){
        tmp += s.top().second;
        ans = max(ans, tmp * s.top().first);
        s.pop();
    }
    cout << ans;
    return 0;
}