#include <iostream>
#include <queue>
using namespace std;

int n;
long long ans;
int zeroCount = 0;
priority_queue<int> positive;
priority_queue<int> negative;
int main(void){
    cin >> n;
    int num;    
    for(int i=0; i<n; i++){
        cin >> num;
        if(num > 0){    
            positive.push(num);
        }
        else if(num < 0){
            negative.push(-num);
        }
        else{zeroCount++;}
    }

    int op1, op2;
    while(positive.size()){
        op1 = positive.top();
        positive.pop();
        if(positive.empty()){
            ans += op1;
            break;
        }
        op2 = positive.top();
        positive.pop();
        if(op1 == 1 || op2 == 1){
            ans += op1+op2;
        }
        else
            ans += op1 * op2;
    }

    while(negative.size()){
        op1 = negative.top();
        negative.pop();
        if(negative.empty()){
            if(zeroCount == 0){
                ans += (-op1);
            }
            break;
        }
        op2 = negative.top();
        negative.pop();

        ans += op1 * op2;
    }
    cout << ans << endl;
    return 0;
}