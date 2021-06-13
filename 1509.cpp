#include <bits/stdc++.h>
using namespace std;

string str;
int len;
bool dp[2500][2500];
// bool isPalindrome(){
    
// }
vector<int> countDP;
void expand(int start, int end){
    if(start-1 < 0 || end+1 > len-1){
        return;
    }
    if(str[start-1] == str[end+1]){
        dp[start-1][end+1] = true;
        expand(start-1, end+1);
    }
}
int main(void){
    cin >> str;
    len = str.length();
    for(int i=0; i<len; i++){
        dp[i][i] = true;
    }

    for(int i=0; i<len-1; i++){
        if(str[i] == str[i+1]){
            dp[i][i+1] = true;
            
        }
    }
    for(int i=0; i<len; i++){
        for(int j=0; j<len; j++){
            if(dp[i][j]){
                expand(i, j);
            }  
        }
    }

    int ans = INT_MAX;
    countDP.resize(len);
    countDP.assign(len, INT_MAX);
    countDP[0] = 1;
    for(int i=1; i<len; i++){
        countDP[i] = countDP[i-1] + 1;
        for(int j=0; j<=i; j++){
            if(dp[j][i])
                if(j==0){
                    countDP[i] = 1;
                }
                else if(countDP[i] > (1+countDP[j-1])){
                    countDP[i] = 1 + countDP[j-1];
                    ans = 1 + countDP[j-1];
                }
        }
    }
    
    cout << countDP[len-1] << endl;
    return 0;
}
