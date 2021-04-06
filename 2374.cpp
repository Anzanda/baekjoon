#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int ans;
int cnt;
vector<int> v;
int solve(int start, int end){
    //cnt++;
    //printf("[(%d, %d)\n", start, end);
    if(start < 1 || end > n){
        return -1;
    }
    if(start > end){
        return -1;
    }
    if(start == end){
        return v[start];
    }

    int max = -1;
    int mIdx = -1;
    for(int i=start; i<=end; i++){
        if(v[i] > max){
            max = v[i];           
            mIdx = i;
        }
    }
    
    int left = solve(start, mIdx-1);
    int right =solve(mIdx+1, end);
    if(left != -1 && left <= v[mIdx]){
        ans += v[mIdx] - left;
    }
    if(right != -1 && right <= v[mIdx]){
        ans += v[mIdx] - right;
    }

    return max;
}

int main(void){
    cin >> n;

    v.resize(n+1);
    for(int i=1; i<=n; i++){
        int num;
        cin >> num;
        v[i] = num;
    }
    cnt = 0;
    ans = 0;
    solve(1, n);
    cout << ans << endl;
    return 0;
}