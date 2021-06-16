#include <bits/stdc++.h>
#define MAXN 4000000
using namespace std;

int n;
bool prime[MAXN+1];//!prime이 소수라는 뜻임.
int main(void){
    cin >> n;

    stack<int> primeStack;
    for(int i=2; i<=n; i++){
        if(!prime[i]){//i가 소수라면.
            primeStack.push(i);
            int j=2;
            while(i*j <= n){
                prime[i*j] = true;
                j = j + 1;
            }
        }
    }

    int ans = 0;
    int tmp = 0;
    queue<int> q;
    while(primeStack.size()){
        if(tmp > n){
            tmp -= q.front();
            q.pop();
        }
        else if(tmp == n){
            ans += 1;
            tmp -= q.front();
            q.pop();
        }
        else{
            tmp += primeStack.top();
            q.push(primeStack.top());
            primeStack.pop();    
        }
    }
    
    if(tmp == n){
        ans++;
    }
    cout << ans << "\n";
    return 0;
}